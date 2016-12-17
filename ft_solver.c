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

void    free_map(struct b board)
{
    int i;

    i = 0;
    while (i < board.b_size)
    {
            ft_memdel((void **)&(board.bd[i]));
            i++;
    }
    ft_memdel((void **)&(board.bd));
    ft_memdel((void **)&board);
}

/* creates grid based off minimium N value that is 
** calculated by tetrimino pieces. Returns a grid filled with 'O'
*/

struct b createSGrid(int N, struct b board)
{
    int i;
    int j;

    i = 0;
    j = 0;
    board.bd = (char **)ft_memalloc(sizeof(char*) * N);
    while (i < N)
    {
        board.bd[i] = (char *)ft_memalloc(sizeof(char) * N);
        board.bd[i][j] = '.';
        while(j++ < N)
        {
            board.bd[i][j] = '.';
        }
        j = 0;
        i++;
    }
    return (board);
}

struct b createBoard(int num_tets, int N)
{
	struct b board;
	int tot_pieces;

	tot_pieces = num_tets * 4;
    while (N * N < tot_pieces)
    {
        N += 1;
    }
	board.b_size = N;
	board = createSGrid(N,board);
    return (board);
}

/* Will check to see if the placement of the piece is within the 
** bounds of the grid and checks to see if all the pieces are plotted 
** in an unmarked point
*/

/* will add the row and column to the tetrimino pieces -> check to see if they are not 
** outside the board bounds && will also check to see if coordinates of pieces are currently
** set to '0' -> will return (1) if conditions are met else return (0)
*/

int isValid(int row, int col, int **tetrimino, struct b grid)
{
    int piece;
    int c_row;
    int c_col;
    int N;

    N = grid.b_size;
    piece = 0;
    c_row = 0;
    c_col = 0;
    if (!tetrimino)
    	return (0);
    while (piece < 4)
    {
        c_row = tetrimino[piece][0]; 
        c_col = tetrimino[piece][1];
        if ((c_row + row) >= N || (c_col + col) >= N)
            return(0);
        if (grid.bd[c_row + row][c_col + col] != '.')
            return (0);
        piece++;
    }
    return (1);
}

/* 
** base case if all tetriminos have been placed return (1)
** loop through columns first and check to see isValid ->place the piece -> call placeTetrimino with next piece
** if false run clearTetrimino for current piece 
** move to the next row if column hits bounds
** returns false if not complete 
*/

int placeTetrimino(int ***tetriminos, struct b grid, int i, int num_tets)
{
    int row;
    int col;
    int N;

    N = grid.b_size;
    row = 0;
    col = 0;
    if (num_tets == i)
    	return (1);
    while (row < N)
    {
        while (col < N)
        {
            if (isValid(row, col, tetriminos[i], grid))
            {
                grid.bd[row + tetriminos[i][0][0]][col + tetriminos[i][0][1]] = i + 'A';
                grid.bd[row + tetriminos[i][1][0]][col + tetriminos[i][1][1]] = i + 'A';
                grid.bd[row + tetriminos[i][2][0]][col + tetriminos[i][2][1]] = i + 'A';
                grid.bd[row + tetriminos[i][3][0]][col + tetriminos[i][3][1]] = i + 'A';
                if (placeTetrimino(tetriminos, grid, i + 1, num_tets)) 
                    return (1);
                grid.bd[row + tetriminos[i][0][0]][col + tetriminos[i][0][1]] = '.';
                grid.bd[row + tetriminos[i][1][0]][col + tetriminos[i][1][1]] = '.';
                grid.bd[row + tetriminos[i][2][0]][col + tetriminos[i][2][1]] = '.';
                grid.bd[row + tetriminos[i][3][0]][col + tetriminos[i][3][1]] = '.';
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

int solver(int num_tets, int ***tetriminos, int N)
{
    struct b board;
    board = createBoard(num_tets, N);
    int i;

    i = 0;
    if (placeTetrimino(tetriminos, board, i, num_tets) == 1)
    {
    	printSolution(board);
    	return(1);
    }
    else 
    {
        free_map(board);
        N = N + 1;
        solver(num_tets, tetriminos, N);
    }
    return (0);
}
