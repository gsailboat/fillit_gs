/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:38:45 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/11 13:39:06 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

char **createGrid(int N)
{
 //creates grid based off minimium N value that is 
 //calculated by tetrimino pieces. Returns a grid filled with 'O'
    int i;
    int j;
    char **grid;

    i = 0;
    j = 0;
    grid = (char **)ft_memalloc(sizeof(char*) * N);
    while (i < N)
    {
        grid[i] = (char *)ft_memalloc(sizeof(char) * N);
        grid[i][j] = '0';
        while(j++ < N)
        {
            grid[i][j] = '0';
        }
        j = 0;
        i++;
    }
    return (grid);
}


int isValid(int row, int col, int **tetrimino, char **board, int N)
{
  /*Will check to see if the placement of the piece is within the 
    bounds of the grid and checks to see if all the pieces are plotted 
    in an unmarked point*/

  //will add the row and column to the tetrimino pieces -> check to see if they are not 
  //outside the board bounds && will also check to see if coordinates of pieces are currently
  //set to '0' -> will return (1) if conditions are met else return (0)

    int piece;
    int c_row;
    int c_col;

    piece = 0;
    c_row = 0;
    c_col = 0;
    while (piece < 4)
    {
        //obtain the coordinates of the piece
        row = tetrimino[piece][0]; 
        col = tetrimino[piece][1];
        //printf("%d %d\n", row, col);
        if (board[c_row + row][c_col + col] != '0')
            return (0);
        if ((c_row + row) >= N || (c_col + col) >= N)
            return(0);
        piece++;
    }
    return (1);

}

int placeTetrimino(int ***tetriminos, int N, char **board, int i)
{
    //base case if all tetriminos have been placed return (1)
    //loop through columns first and check to see isValid ->place the piece -> call placeTetrimino with next piece
    //if false run clearTetrimino for current piece 
    //move to the next row if column hits bounds
    //returns false if not complete 

    int row;
    int col;

    row = 0;
    col = 0;


    while (row < N)
    {
        while (col < N)
        {
            if (isValid(row, col, tetriminos[i], board, N))
            {
            	printf("valid has passed the loop: %d\n ", i);
                board[row + tetriminos[i][0][0]][col + tetriminos[i][0][1]] = i + 'A';
                board[row + tetriminos[i][1][0]][col + tetriminos[i][1][1]] = i + 'A';
                board[row + tetriminos[i][2][0]][col + tetriminos[i][2][1]] = i + 'A';
                board[row + tetriminos[i][3][0]][col + tetriminos[i][3][1]] = i + 'A';
                printSolution(N, board);
                if (placeTetrimino(tetriminos, N, board, i + 1)) //calling the wrong shit! need to find a way to call with same params
                    return (1);
                board[row + tetriminos[i][0][0]][col + tetriminos[i][0][1]] = i + '0';
                board[row + tetriminos[i][1][0]][col + tetriminos[i][1][1]] = i + '0';
                board[row + tetriminos[i][2][0]][col + tetriminos[i][2][1]] = i + '0';
                board[row + tetriminos[i][3][0]][col + tetriminos[i][3][1]] = i + '0';
            }
            col++;
        }
        col = 0;
        row++;
    }
    return (0);

}

int solver(int N, int ***tetriminos)// int num_tets)
{
    /* if base case return 1 and end which is all tetrminos have been plotted
    loop through columns first to see isValid*/
    char **board;
    board = createGrid(N);
    int i;

    i = 0;

    if (placeTetrimino(tetriminos, N, board, i) == 1)
    {
    	printf("%s", "shit returned 1, now print out the board.");
    	printSolution(N, board);
    	return(1);
    }

    // if (!*tetriminos[i] || i == num_tets)
    // {
    // 	printSolution(N, board);
    //     return(1);
    // }
    // while(*tetriminos[i])
    // {
    //     if (placeTetrimino(tetriminos[i], N, board, i))
    //          i++;
    //     else
    //         break;
    // }
    printf("%s", "shit didn't work. Keep debugging!.");
    return (0);
}

int mainSolver(int num_tets, int ***tetriminos)
{
    int tot_pieces;
    int N;

    tot_pieces = num_tets * 4;
    N = 4;  //forced number for testing purposes
    while (N * N < tot_pieces)
    {
        N += 1;
    }
    if (solver(N,tetriminos) == 1)
    {
        return (1);
    }
    // else 
    // {
    //     N = N + 1; 
    //     solver(N,tetriminos,num_tets);
    // }
    return (0);
}





// char	**ft_grid(int N)
// {
// 	int i;
// 	int j;
// 	char **grid;

// 	i = 0;
// 	j = 0;
// 	grid = (char **)ft_memalloc(sizeof(char*) * N);
// 	while (i < N)
// 	{
// 		grid[i] = (char *)ft_memalloc(sizeof(char) * N);
// 		grid[i][j] = '0';
// 		while(j++ < N)
// 		{
// 			grid[i][j] = '0';
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	return (grid);
// }


// /* function will take the relative position that solver passed through
// ** and adjusts the original coordinates in order to move the pieces 
// ** ?make sure this works in a way that doesn't add numbers outside bounds?
// */

// void	placePiece(int row, int col, char **board, int **tetri, int tetrimino)
// {
// 	int piece;
// 	int new_row;
// 	int new_col;

// 	piece = 0;
// 	while (piece < 4)
// 	{
// 		//obtain the coordinates of the piece
// 		new_row = tetri[piece][0] + row; 
// 		new_col = tetri[piece][1] + col;
// 		board[new_row][new_col] = tetrimino + 'A';
// 		piece++;
// 	}
// 	printf("%c", board[0][0]);
// 	printf("%c", board[0][1]);
// 	printf("%c", board[0][2]);
// 	printf("%c\n", board[0][3]);
// 	printf("%c", board[1][0]);
// 	printf("%c", board[1][1]);
// 	printf("%c", board[1][2]);
// 	printf("%c\n", board[1][3]);
// 	printf("%c", board[2][0]);
// 	printf("%c", board[2][1]);
// 	printf("%c", board[2][2]);
// 	printf("%c\n", board[2][3]);
// 	printf("%c", board[3][0]);
// 	printf("%c", board[3][1]);
// 	printf("%c", board[3][2]);
// 	printf("%c\n", board[3][3]);

// }

// void	clearPiece(int row, int col, char **board, int **tetri)
// {

// 	int piece;

// 	piece = 0;
// 	while (piece < 4)
// 	{
// 		//obtain the coordinates of the piece
// 		row = tetri[piece][0] + row; 
// 		col = tetri[piece][1] + col;
// 		board[row][col] = '0';
// 		piece++;

// 	}
// }

// //
// int	solver(int N, char **board, int ***tetri, int num_of_tetriminos)
// {
// 	/*need to write a base case to return true *all tetriminos have fit in*/
// 	int i;
// 	int row;
// 	int col;

// 	i = 0;
// 	row = 0;
// 	col = 0;
// 	if (i >= num_of_tetriminos)
// 		return (1);  //Solver somehow needs to return the board


// 	while (row < N)
// 	{
// 		while (col < N)
// 		{
// 			//Check to see if tetrimino can be place on column at current row
// 			if (isSafe(board,*tetri, row, col))
// 			{
// 				//if true place pieces based off coordinate values
// 				placePiece(row, col, board, *tetri, i);
// 				i++;
// 				//recur to place rest of tetriminos
// 				printf("%d\n", col);
// 			}
// 			else
// 			{
// 				//clearPiece(row, col, board, *tetri);
// 				//printf("%d\n", col);
// 			}
// 			col++;
// 			solver(N,board,tetri++,num_of_tetriminos--);
// 		}
// 		col = 0;
// 		row++;
// 	}
// 	return (0);
// }

// void solveTetrimino(int num_of_tetriminos, int N, int ***tetri)
// {
// 	int tot_pieces;
// 	char **board;

// 	tot_pieces = num_of_tetriminos * 4;
// 	//setup the board
// 	while (N * N < tot_pieces)
// 	{
// 		N += 1;
// 	}
// 	if (!(board = ft_grid(N)))
// 		printf("%s", "something fucked up here");

// 	if (tetri[1][1][1] == 20)
// 		printf("%d %d\n",tot_pieces, N);
// 	// //call the solver function
// 	if (solver(N, board, tetri, num_of_tetriminos) != 0)
// 	{
// 		//print the solution once solver returns true: 1
// 		printSolution(N, board);
// 	}
// 	// else
// 	// {
// 	// 	//if solver returns false, increase board size by 1
// 	// 	solveTetrimino(num_of_tetriminos, (N + 1), tetri);
// 	// }
// }
