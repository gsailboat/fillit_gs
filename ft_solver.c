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
//Will malloc a 2d array in order to create a grid based off parameter value 

char	**ft_grid(int rac)
{
	int i;
	int j;
	char **grid;

	i = 0;
	j = 0;
	grid = (char **)ft_memalloc(sizeof(char*) * rac);
	while (i < rac)
	{
		grid[i] = (char *)ft_memalloc(sizeof(char) * rac);
		grid[i][j] = '0';
		while(j++ < rac)
		{
			grid[i][j] = '0';
		}
		j = 0;
		i++;
	}
	return (grid);
}


/* function will take the relative position that solver passed through
** and adjusts the original coordinates in order to move the pieces 
** ?make sure this works in a way that doesn't add numbers outside bounds?
*/

void	placePiece(int row, int col, char **board, int **tetri, int tetrimino)
{
	int piece;
	int new_row;
	int new_col;

	piece = 0;
	while (piece < 4)
	{
		//obtain the coordinates of the piece
		new_row = tetri[piece][0] + row; 
		new_col = tetri[piece][1] + col;
		board[new_row][new_col] = tetrimino + 'A';
		piece++;
	}
	printf("%c", board[0][0]);
	printf("%c", board[0][1]);
	printf("%c", board[0][2]);
	printf("%c\n", board[0][3]);
	printf("%c", board[1][0]);
	printf("%c", board[1][1]);
	printf("%c", board[1][2]);
	printf("%c\n", board[1][3]);
	printf("%c", board[2][0]);
	printf("%c", board[2][1]);
	printf("%c", board[2][2]);
	printf("%c\n", board[2][3]);
	printf("%c", board[3][0]);
	printf("%c", board[3][1]);
	printf("%c", board[3][2]);
	printf("%c\n", board[3][3]);

}

void	clearPiece(int row, int col, char **board, int **tetri)
{

	int piece;

	piece = 0;
	while (piece < 4)
	{
		//obtain the coordinates of the piece
		row = tetri[piece][0] + row; 
		col = tetri[piece][1] + col;
		board[row][col] = '0';
		piece++;

	}
}

//
int	solver(int N, char **board, int ***tetri, int num_of_tetriminos)
{
	/*need to write a base case to return true *all tetriminos have fit in*/
	int i;
	int row;
	int col;

	i = 0;
	row = 0;
	col = 0;
	if (i >= num_of_tetriminos)
		return (1);  //Solver somehow needs to return the board


	while (row < N)
	{
		while (col < N)
		{
			//Check to see if tetrimino can be place on column at current row
			if (isSafe(board,*tetri, row, col))
			{
				//if true place pieces based off coordinate values
				placePiece(row, col, board, *tetri, i);
				i++;
				//recur to place rest of tetriminos
				printf("%d\n", col);
			}
			else
			{
				//clearPiece(row, col, board, *tetri);
				//printf("%d\n", col);
			}
			col++;
			solver(N,board,tetri++,num_of_tetriminos--);
		}
		col = 0;
		row++;
	}
	return (0);
}

void solveTetrimino(int num_of_tetriminos, int N, int ***tetri)
{
	int tot_pieces;
	char **board;

	tot_pieces = num_of_tetriminos * 4;
	//setup the board
	while (N * N < tot_pieces)
	{
		N += 1;
	}
	if (!(board = ft_grid(N)))
		printf("%s", "something fucked up here");

	if (tetri[1][1][1] == 20)
		printf("%d %d\n",tot_pieces, N);
	// //call the solver function
	if (solver(N, board, tetri, num_of_tetriminos) != 0)
	{
		//print the solution once solver returns true: 1
		printSolution(N, board);
	}
	// else
	// {
	// 	//if solver returns false, increase board size by 1
	// 	solveTetrimino(num_of_tetriminos, (N + 1), tetri);
	// }
}
