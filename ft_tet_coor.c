/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tet_coor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:50:21 by gselbo            #+#    #+#             */
/*   Updated: 2016/12/19 17:05:28 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

char		*ft_modify(char *m)
{
	char *periods;

	if ((m[0] == '#' && m[4] == '#' && m[3] == '.') || (m[5] == '#'
		&& m[9] == '#'))
	{
		periods = (char*)malloc(sizeof(char) * (ft_strlen(m) + 2));
		ft_strcat(periods, ".");
		periods = ft_strcat(periods, m);
		return (periods);
	}
	else if (m[0] == '#' && m[3] == '#' && m[4] == '#' && m[5] == '#')
	{
		periods = (char*)malloc(sizeof(char) * (ft_strlen(m) + 3));
		ft_strcat(periods, "..");
		periods = ft_strcat(periods, m);
		return (periods);
	}
	else
		return (m);
}

int			***ft_assignmalloc(int tit_count)
{
	int		n;
	int		a;
	int		j;
	int		***cord;

	n = 0;
	a = 0;
	j = 0;
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

int			***ft_tet_coor(char **minos, int tetri)
{
	int		x;
	int		col_c;
	int		tet;
	int		***cord;

	tet = 0;
	cord = ft_assignmalloc(tetri);
	while (tet < tetri)
	{
		x = 0;
		col_c = -1;
		minos[tet] = ft_modify(minos[tet]);
		while (minos[tet][x] != '\0')
		{
			if (minos[tet][x] == '#' && ++col_c < 4)
			{
				cord[tet][col_c][0] = x / 5;
				cord[tet][col_c][1] = x % 5;
			}
			x++;
		}
		tet++;
	}
	return (cord);
}
