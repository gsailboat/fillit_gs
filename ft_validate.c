/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 15:09:53 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/19 17:38:23 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
**	Is_valid will read in the tetrimino and check to see if it is valid
**	if the information is valid return error prompt. Will count to see
**	if a 4 x 4 block has been passed through. Return true or false.
**	Second step will be to see if tetrimino is a valid shape.
*/

int			is_valid(char *file, size_t file_buffer)
{
	size_t	i;
	int		j;
	size_t	real;

	i = 4;
	j = 1;
	real = file_buffer + 1;
	while (file[i] == '\n' && i < real)
	{
		if (file[i + 5] == '\n' && j <= 4)
		{
			i += 5;
			j++;
		}
		else if (file[i + 1] == '\n' && j == 4)
		{
			i += 6;
			j = 1;
		}
		else if (file[i + 1] == '\0' && real % 21 == 0)
			return (1);
		else
			break ;
	}
	return (0);
}

/*
**	Function will convert each new line char into a dot to determine
**	shape of the piece
*/

void		*convert_to_dot(char *string_tetrino)
{
	int		i;

	i = 0;
	while (string_tetrino[i] != '\0')
	{
		if (string_tetrino[i] == '\n')
			string_tetrino[i] = ('.');
		i++;
	}
	return (string_tetrino);
}

/*
**	Function will validate the tetrimino passed in a parameter. Func will
**	convert all new lines in the string to dots, and trim the ends of the
**	string until a hashtag is hit. The string array will be compared to 2D
**	array of predefined shapes with strcmp for validation.
*/

int			validate_tetrino(char **sg_shp)
{
	int		i;
	int		j;
	char	**v_tets;

	i = 0;
	j = 0;
	v_tets = valid_tetrimino();
	while (sg_shp[j] != 0)
	{
		convert_to_dot(sg_shp[j]);
		while (i < 19)
		{
			if (i == 18 && ft_strcmp(ft_strctrim(sg_shp[j]), v_tets[i]) != 0)
				return (0);
			if (ft_strcmp(ft_strctrim(sg_shp[j]), v_tets[i]) == 0)
				break ;
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

/*
**	Function will return a 2D array of trimmed tetriminos from the input file
*/

char		**trim_tetriminos(char **string_shape, int tit_count)
{
	int		j;
	char	**return_string;

	j = 0;
	if (!(return_string = (char **)ft_memalloc(sizeof(char*) * tit_count)))
		return (NULL);
	while (string_shape[j] != 0 && tit_count > 0)
	{
		convert_to_dot(string_shape[j]);
		return_string[j] = ft_strctrim(string_shape[j]);
		j++;
	}
	return (return_string);
}
