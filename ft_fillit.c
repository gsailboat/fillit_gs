/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:16:26 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/19 20:21:13 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

#define BUF_SIZE 560

int			b_size(char *file_name)
{
	char	buf[BUF_SIZE + 1];
	int		read_file;
	int		bytes_read;

	read_file = open(file_name, O_RDWR);
	if (read_file == -1)
	{
		ft_putstr("Error:Something fucked up happend in your code");
		return (0);
	}
	bytes_read = read(read_file, buf, BUF_SIZE);
	if (close(read_file == -1))
	{
		ft_putstr("close() error");
		return (0);
	}
	return (bytes_read);
}

/*
**	Read information from a fixed file called "valid_1"
*/

char		*read_information(char *file_name)
{
	char	buf[BUF_SIZE + 1];
	char	*return_string;
	int		read_file;
	int		bytes_read;

	read_file = open(file_name, O_RDWR);
	if (read_file == -1)
	{
		ft_putstr("Error:Something fucked up happend in your code");
		return (NULL);
	}
	bytes_read = read(read_file, buf, BUF_SIZE);
	return_string = ft_strdup(buf);
	if (close(read_file == -1))
	{
		ft_putstr("close() error");
		return (NULL);
	}
	return (return_string);
}

int			main(int argc, char **argv)
{
	char	*file_name;
	char	*buf;
	char	**tetrimino_in_file;
	char	**t_tet;
	int		return_value;

	file_name = argv[argc - 1];
	if (argc != 2)
	{
		ft_putstr("./fillit [file-name]");
		return (0);
	}
	buf = read_information(file_name);
	return_value = is_valid(buf, b_size(file_name));
	tetrimino_in_file = (ft_tet_split(buf));
	if (return_value == 0 || validate_tetrino(tetrimino_in_file) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	else
	{
		t_tet = trim_tetriminos(tetrimino_in_file, ft_tit_count(buf));
		solver(ft_tit_count(buf), ft_tet_coor(t_tet, ft_tit_count(buf)), 2);
	}
}
