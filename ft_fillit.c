/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:16:26 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/01 22:19:13 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

#define BUF_SIZE 100

char *ft_strctrim(const char *s);

/* 
 * allowed functions exit, open, close, write, read, malloc, free
*/

/*	Is_valid will read in the tetrimino and check to see if it is valid
**  if the information is valid return error prompt. 
*/

// ft_isvalid() Check to see if the tetrimino is valid
// 	ft_check_lines() Checks to see how many lines are passed through 
// ft_tetrimino() Optional function that will determine which tetrimino we are 
// 	working with. 


// ft_coordinates() will store the coordinate values of the pieces in a 2d array
// ft_isplacesafe() Checks to see if the placement of the piece is valid 
// ft_printboard() Create the board based off how many tetrimos there are 
// ft_solution() Recrusive backtracking that finds the solution. 
// ft_convert_to_char() convert tetriminos to capital letters based off sequence. 
// ft_print_solution() Will print out the solution 
 

/*
**	Read information from a fixed file called "valid_1"
*/

int 	read_information(void)
{
	char buf[BUF_SIZE + 1];
	int  read_file;

	read_file = open("valid_1", O_RDWR);
	if (read_file == -1)
	{
		ft_putstr("Error:Something fucked up happend in your code");
		return (1);
	}
	read_file = read(read_file, buf, BUF_SIZE);
	buf[read_file] = '\0';
	ft_putstr(buf);
	if (close(read_file == -1))
	{
		ft_putstr("close() error");
		return (1);
	}
	ft_putchar('\n');
	ft_putnbr(read_file);
	return (0);
}

/*	
**	Is_valid will read in the tetrimino and check to see if it is valid
**  if the information is valid return error prompt. Will count to see if a 4 x 4
** 	block has been passed through. Return true or false. Second step will be to 
** 	see if tetrimino is a valid shape.
*/

void	is_valid(char *file, size_t file_buffer)
{
	int iter;
	int j;

	iter = 0;
	//code will iterate through string 4 char, check for new line on 5th
	// char <-will do this 4 times and check for 2 new lines
	while (file_buffer)
	{
		while (iter <= 20)
		{
			if (file[iter] != '\n')
				return (0);
			iter += 5;
		}
		if (file[iter + 1] != '\n')
			return (0);
		file_buffer -= iter;
		iter;
	}
	return (1);
}

int		line(char *s)
{
	char	*h_line;

	h_line = "####\n";
	if (ft_strcmp(ft_strctrim(s), h_line) == 0)
		return (0);
	else
		return (1);
}


int     main(int argc, char **argv)
{
	int read_file_bytes;
	char *file_name;
	char *buf;
	int return_value;
	file_name = argv[argc - 1];
	if (argc != 2)
	{
		ft_putstr("wrong number of inputs: try again");
		return (0);
	}
	buf = read_information(file_name);
	return_value = is_valid(buf, 41);
	printf("%d\n", return_value);
	printf("%d\n", line(buf));

}
