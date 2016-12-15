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

/* creates grid based off minimium N value that is 
** calculated by tetrimino pieces. Returns a grid filled with 'O'
*/

char **createGrid(int N)
{

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

/* Will check to see if the placement of the piece is within the 
** bounds of the grid and checks to see if all the pieces are plotted 
** in an unmarked point
*/

/* will add the row and column to the tetrimino pieces -> check to see if they are not 
** outside the board bounds && will also check to see if coordinates of pieces are currently
** set to '0' -> will return (1) if conditions are met else return (0)
*/

int isValid(int row, int col, int **tetrimino, char **board, int N)
{

	printf("Enter IsValid row:%d col:%d  ", row, col);
    int piece;
    int c_row;
    int c_col;

    piece = 0;
    c_row = 0;
    c_col = 0;

    printf("%d,", tetrimino[0][0]);
    printf("%d ", tetrimino[0][1]);
    printf("%d,", tetrimino[1][0]);
    printf("%d ", tetrimino[1][1]);
    printf("%d,", tetrimino[2][0]);
    printf("%d ", tetrimino[2][1]);
    printf("%d,", tetrimino[3][0]);
    printf("%d\n ", tetrimino[3][1]);

    if (!tetrimino)
    	return (0);
    while (piece < 4)
    {
        c_row = tetrimino[piece][0]; 
        c_col = tetrimino[piece][1];
        if ((c_row + row) >= N || (c_col + col) >= N)
        {
        	printf("%s\n", "return false2");
            return(0);
        }
        if (board[c_row + row][c_col + col] != '0')
        {
        	printf("%s\n", "return false");
            return (0);
        }
        piece++;
    }
    printf("%s\n", "return true");
    return (1);
}

/* 
** base case if all tetriminos have been placed return (1)
** loop through columns first and check to see isValid ->place the piece -> call placeTetrimino with next piece
** if false run clearTetrimino for current piece 
** move to the next row if column hits bounds
** returns false if not complete 
*/

int placeTetrimino(int ***tetriminos, int N, char **board, int i)
{

	printf("enter placeTet: %d\n ", i);
    int row;
    int col;
    int array_size;

    row = 0;
    col = 0;
    if (!tetriminos[i]) //base case <- need to fix in order for tetriminos printed to equal num_tet
    	return (1);

    while (row < N)
    {
        while (col < N)
        {
            if (isValid(row, col, tetriminos[i], board, N))
            {
            	printf("valid has passed the loop: %d row: %d col: %d\n ", i, row, col);
                board[row + tetriminos[i][0][0]][col + tetriminos[i][0][1]] = i + 'A';
                board[row + tetriminos[i][1][0]][col + tetriminos[i][1][1]] = i + 'A';
                board[row + tetriminos[i][2][0]][col + tetriminos[i][2][1]] = i + 'A';
                board[row + tetriminos[i][3][0]][col + tetriminos[i][3][1]] = i + 'A';
                printSolution(N, board);
                if (placeTetrimino(tetriminos, N, board, i + 1)) 
                    return (1);
               	printf("valid is deleting tet: %d\n ", i);
                board[row + tetriminos[i][0][0]][col + tetriminos[i][0][1]] = '0';
                board[row + tetriminos[i][1][0]][col + tetriminos[i][1][1]] = '0';
                board[row + tetriminos[i][2][0]][col + tetriminos[i][2][1]] = '0';
                board[row + tetriminos[i][3][0]][col + tetriminos[i][3][1]] = '0';
            }
        col++;
        }
        col = 0;
        row++;
    }
    return (0);

}

/* 
** if base case return 1 and end which is all tetrminos have been plotted
** loop through columns first to see isValid
*/

int solver(int N, int ***tetriminos)
{
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
    printf("%s", "shit didn't work. Keep debugging!.");
    return (0);
}

int mainSolver(int num_tets, int ***tetriminos)
{
    int tot_pieces;
    int N;

    tot_pieces = num_tets * 4;
    N = 2;  
    while (N * N < tot_pieces)
    {
        N += 1;
    }
    if (solver(N,tetriminos) == 1)
        return (1);
    else 
    {
        N = N + 1; 
        solver(N,tetriminos);
    }
    return (0);
}
