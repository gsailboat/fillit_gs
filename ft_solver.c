/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:38:45 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/19 19:08:19 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

/*
** creates grid based off minimium N value that is
** calculated by tetrimino pieces. Returns a grid filled with 'O'
*/

t_name			createsgrid(int number, t_name board)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	board.bd = (char **)ft_memalloc(sizeof(char*) * number);
	while (i < number)
	{
		board.bd[i] = (char *)ft_memalloc(sizeof(char) * number);
		board.bd[i][j] = '.';
		while (j++ < number)
		{
			board.bd[i][j] = '.';
		}
		j = 0;
		i++;
	}
	return (board);
}

t_name			createboard(int num_tets, int n)
{
	t_name		board;
	int			tot_pieces;

	tot_pieces = num_tets * 4;
	while (n * n < tot_pieces)
	{
		n += 1;
	}
	board.b_size = n;
	board = createsgrid(n, board);
	return (board);
}

/*
**	Will check to see if the placement of the piece is within the
**	bounds of the grid and checks to see if all the pieces are plotted
**	in an unmarked point
*/

int				isvalid(int row, int col, int **tetrimino, t_name grid)
{
	int			piece;
	int			c_row;
	int			c_col;
	int			n;

	n = grid.b_size;
	piece = 0;
	c_row = 0;
	c_col = 0;
	if (!tetrimino)
		return (0);
	while (piece < 4)
	{
		c_row = tetrimino[piece][0];
		c_col = tetrimino[piece][1];
		if ((c_row + row) >= n || (c_col + col) >= n)
			return (0);
		if (grid.bd[c_row + row][c_col + col] != '.')
			return (0);
		piece++;
	}
	return (1);
}

/*
**	base case if all tetriminos have been placed return (1)
**	loop through columns first and check to see isValid ->place the piece
**	-> call placeTetrimino with next piece
**	if false run clearTetrimino for current piece
**	move to the next row if column hits bounds
**	returns false if not complete
*/

int				p_tetrimino(int ***tet, t_name grid, int i, int num_tets)
{
	int			row;
	int			col;

	row = -1;
	if (num_tets == i)
		return (1);
	while (++row < grid.b_size)
	{
		col = -1;
		while (++col < grid.b_size)
		{
			if (isvalid(row, col, tet[i], grid))
			{
				grid.bd[row + tet[i][0][0]][col + tet[i][0][1]] = i + 'A';
				grid.bd[row + tet[i][1][0]][col + tet[i][1][1]] = i + 'A';
				grid.bd[row + tet[i][2][0]][col + tet[i][2][1]] = i + 'A';
				grid.bd[row + tet[i][3][0]][col + tet[i][3][1]] = i + 'A';
				if (p_tetrimino(tet, grid, i + 1, num_tets))
					return (1);
				p_period(row, col, tet[i], grid);
			}
		}
	}
	return (0);
}

/*
**	if base case return 1 and end which is all tetrminos have been plotted
**	loop through columns first to see isValid
*/

int				solver(int num_tets, int ***tetriminos, int n)
{
	t_name		board;
	int			i;

	board = createboard(num_tets, n);
	i = 0;
	if (p_tetrimino(tetriminos, board, i, num_tets) == 1)
	{
		p_solution(board);
		return (1);
	}
	else
	{
		free_map(board);
		n = n + 1;
		solver(num_tets, tetriminos, n);
	}
	return (0);
}
