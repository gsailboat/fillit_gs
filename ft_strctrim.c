/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:52:27 by gselbo            #+#    #+#             */
/*   Updated: 2016/12/19 19:06:13 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static	int	trim(char c)
{
	if (c == '.' || c == '\n')
		return (1);
	return (0);
}

void		p_period(int row, int col, int **tetrim, t_name grid)
{
	grid.bd[row + tetrim[0][0]][col + tetrim[0][1]] = '.';
	grid.bd[row + tetrim[1][0]][col + tetrim[1][1]] = '.';
	grid.bd[row + tetrim[2][0]][col + tetrim[2][1]] = '.';
	grid.bd[row + tetrim[3][0]][col + tetrim[3][1]] = '.';
}

char		*ft_strctrim(const char *s)
{
	char	*start;
	char	*end;
	int		len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	start = (char *)s;
	end = (char *)s + len - 1;
	while (trim(*start))
		++start;
	while (trim(*end) && end > start)
		--end;
	return (ft_strsub(start, 0, 1 + end - start));
}

void		p_solution(t_name grid)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = grid.b_size;
	while (i < n)
	{
		while (j < n)
		{
			ft_putchar(grid.bd[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void		free_map(t_name board)
{
	int		i;

	i = 0;
	while (i < board.b_size)
	{
		ft_memdel((void **)&(board.bd[i]));
		i++;
	}
	ft_memdel((void **)&(board.bd));
	ft_memdel((void **)&board);
}
