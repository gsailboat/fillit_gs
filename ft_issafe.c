/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issafe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:44:40 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/08 17:18:48 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

/* 
** return the length of the board size
*/

int board_size(char **board)
{
	int i;

	i = 0;
	while (board[0][i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
** Checks to see if the tetrimino overlaps any other pieces and is within the bounds
** of the created grid size. Grid will be filled with '0' values. A condition will 
** if piece to place is '0' indicating a free space. Loop through to place remaining 
** pieces. If space is not '0', False will be returned. 
*/

/* Function should look at the passed through coordinate values and see if there is 
** something there
** char **piece_1 = {{0,0},{1,0},{2,0},{3,0}};
** char **piece_2 = {{0,1},{0,2},{0,3},{0,4}};
*/

int	isSafe(char **board, int **tetri, int row, int col)
{
	int piece;

	row = 0;
	col = 0;
	piece = 0;
	while (piece < 4)
	{
		//obtain the coordinates of the piece
		row = tetri[piece][0]; 
		col = tetri[piece][1];
		//printf("%d %d\n", row, col);
		if (board[row][col] != '0')
			return (0);
		piece++;
	}
	return (1);
}
