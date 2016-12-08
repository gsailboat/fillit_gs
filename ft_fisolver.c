/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fisolver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:50:59 by gselbo            #+#    #+#             */
/*   Updated: 2016/12/05 15:51:01 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

#define BUF_SIZE 4000

int		ft_solver(char **minos, int tetri)
{
	if (tetri == 1)
	{
		if (minos[0] == SQU)
			return (1);
		if else (minos[0] == H_LINE || minos[0] == V_LINE)
			return (3);
		else
			return (2);
	}
	else if (tetri > 1)
		return (2);
	else
		return (0);
}

char	**ft_grid(int rac)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < rac)
	{
		grid[i][j] = ('.');
		i++;
		if (i == rac)
		{
			grid[i][j] = ('.');
			if (j < rac)
			{
				i = 0;
				j++;
			}
		}
	}
	return (grid);
}

char	**ft_graph(char **minos, char **grid, int fit)
{
	int i;
	int j;

	j = 2;
	i = ft_solver(minos, fit);
	if (fit == 1)
		return(ft_grid(grid, i));
	else
		while (j < 104)
		{
			if()
			else
			ft_grid(grid, rac + 1);
		fit++;
		}
	}
	if (fit > 104)
		return (NULL);
}