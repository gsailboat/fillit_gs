/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:16:26 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/01 13:41:51 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** allowed functions exit, open, close, write, read, malloc, free
*/

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

#define BUF_SIZE 4000


char **valid_tets;

/*
**	Read information from a fixed file called "valid_1"
*/

char 	*read_information(char* file_name)
{
	char buf[BUF_SIZE + 1];
	char *return_string;
	int  read_file;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	int  bytes_read;

	read_file = open(file_name, O_RDWR);
	if (read_file == -1)
	{
		ft_putstr("Error:Something fucked up happend in your code");
		return (NULL);
	}
	bytes_read = read(read_file, buf, BUF_SIZE);
	//printf("%d\n", bytes_read);
	return_string = ft_strdup(buf);
	if (close(read_file == -1))
	{
		ft_putstr("close() error");
		return (NULL);
	}
	return (return_string);
}

/*	
**	Is_valid will read in the tetrimino and check to see if it is valid
**  if the information is valid return error prompt. Will count to see if a 4 x 4
** 	block has been passed through. Return true or false. Second step will be to 
** 	see if tetrimino is a valid shape. ****currently results in a false negative with single tets**
**	**************Still need to fix the function so it handles only one tetrimino************
*/

int	is_valid(char *file, size_t file_buffer)
{
	size_t iter;
	int j;

	iter = 4;
	j = -1;
	while (file_buffer > iter)
	{
		while (j++ < 3)
		{
			if (file[iter] != '\n')
				return (0);
			iter += 5;
		}
		if (file[iter] != '\n' && file[iter + 1] != '\n')
			return (0);
		else
		{
			iter += 1;
			j = 0;
		}
	}
	return (1);
}

/*	Function will convert each new line char into a dot to determine
**	shape of the piece
*/

void	*convert_to_dot(char *string_tetrino)
{
	int i;

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

int		validate_tetrino(char **string_shape)
{
	int i;
	int j;
	char **valid_tets = valid_tetrimino();

	i = 0;
	j = 0;
	while (string_shape[j] != 0)
	{
		convert_to_dot(string_shape[j]);
		while (i < 19)
		{
			if (i == 18 && ft_strcmp(ft_strctrim(string_shape[j]), valid_tets[i]) != 0)
				return (0);
			if (ft_strcmp(ft_strctrim(string_shape[j]), valid_tets[i]) == 0)
				break;
			// printf("%s\n", (valid_tets[i]));
			// printf("%d\n", i);
			i++;
		}
		j++;
	}
	return (1);
}

int 	main(int argc, char **argv)
{
	char *file_name;
	char *buf;
	char **tetrimino_in_file;
	int return_value;
	int ***test_array;

	//reads in file and checks to see if argument value is correct
	file_name = argv[argc - 1];
	if (argc != 2)
	{
		ft_putstr("wrong number of inputs: try again");
		return (0);
	}
	//input file read into 'buf'
	buf = read_information(file_name);

	//running the is_valid function to see if the input file is correctly 
	//outputting valid 4x4 pieces 
	return_value = is_valid(buf, 41);  //need to calculate buff size
	if (return_value == 0)
		return (0);
	else 

	//assign the tetriminos into a 2d array to validate the pieces.
	tetrimino_in_file = ft_tet_split(buf);

	//run the validate_tet function to do a string compare against
	//predefined tetriminos set up in ft_valid_tet.c
	printf("%d\n", validate_tetrino((tetrimino_in_file)));

	//run a test on tet_coor
	test_array = ft_tet_coor(tetrimino_in_file, 4);
	//printf("%d\n", test_array[0][0][0]);

}
