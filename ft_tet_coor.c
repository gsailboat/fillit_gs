/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tet_coor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:50:21 by gselbo            #+#    #+#             */
/*   Updated: 2016/12/07 19:50:25 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

int		ft_modify(char **minos, int p)
{
	char	*add;

	add = ".";
	if (minos[p][4] == '#')
	{
		if (minos[p][3] == '#' && minos[p][5] == '#')
		{
			minos[p] = ft_strcat("..", minos[p]);
			return (2);
		}
		else
		{
			minos[p] = ft_strcat(add, minos[p]);
			return (1);
		}
	}
	else
		return (0);
}

int    ***ft_assignmalloc(int tit_count)
{
	int	n;
	int	a;
	int j;
	int ***cord;

    n = 0;
    a = 0;
    j = 0;
    tit_count = 4;

    cord = (int ***)ft_memalloc(sizeof(int**) * tit_count);
    while (j < tit_count)
    {
    	cord[j] = (int **)ft_memalloc(sizeof(int*) * 4);
    	while (a < 4)
    	{
    		cord[j][a] = (int *)ft_memalloc(sizeof(int) * 2);
    		a++;
    	}
    	a = 0;
    	j++;
    }
    return (cord);

}

int		***ft_tet_coor(char **minos, int tetri)
{
	int x;
	int y;
	int col_c;
	int tet;
	int ***cord;

	x = 0;
	y = 0;
	col_c = 0;
	tet = 0;
	cord = ft_assignmalloc(tetri);

	// printf("%c\n", minos[0][0]);
	// printf("%c\n", minos[0][1]);
	// printf("%c\n", minos[0][2]);
	// printf("%c\n", minos[0][3]);
	// printf("%c\n", minos[0][4]);
	// printf("%c\n", minos[0][5]);
	// printf("%c\n", minos[0][6]);
	// printf("%c\n", minos[0][7]);

	while (tet < tetri)
	{
		//x = ft_modify(minos, tet);
		while (minos[tet][x] != '\0')
		{
			if (minos[tet][x] == '#'  && col_c < 4)
			{
				cord[tet][col_c][0] = y;
				cord[tet][col_c][1] = x % 5;
				col_c++;
			}
			x++;
			if (x % 5 == 0)
				y++;
		}
	tet++;
	x = 0;
	y = 0;
	col_c = 0;
	}
	return (cord);
}