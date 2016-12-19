/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:16:26 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/16 13:41:51 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

#define BUF_SIZE 4000

//char **valid_tets; <-- clear out variable if not needed.


int 	b_size(char* file_name)
{
	char buf[BUF_SIZE + 1];
	int  read_file;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	int  bytes_read;

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

int    is_valid(char *file, size_t file_buffer)
{
  size_t i;
  size_t real;

  i = 4;
  real = file_buffer + 1;
  while (file[i] == '\n' && i < real)
  {
      if (file[i + 5] == '\n')
          i += 5;
      else if (file[i + 1] == '\n')
          i += 6;
      else if (file[i + 1] == '\0' && real % 21 == 0)
      	return (1);
      else
      	break;
  }
  return (0);
}



/*	
** Function will convert each new line char into a dot to determine
** shape of the piece
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
		while (i < 19) //might need to change to 19
		{
			//printf("%s %s\n",string_shape[j], valid_tets[i]);
			if (i == 18 && ft_strcmp(ft_strctrim(string_shape[j]), valid_tets[i]) != 0)
				return (0);
			if (ft_strcmp(ft_strctrim(string_shape[j]), valid_tets[i]) == 0)
				break;
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

char	**trim_tetriminos(char **string_shape, int tit_count)
{
	int j;
	char **return_string;

	j = 0;
	if(!(return_string = (char **)ft_memalloc(sizeof(char*) * tit_count)))
		return (NULL);
	while (string_shape[j] != 0 && tit_count > 0)
	{
		convert_to_dot(string_shape[j]);
		return_string[j] = ft_strctrim(string_shape[j]);
		j++;
	}
	return (return_string);
}

int 	main(int argc, char **argv)
{
	char *file_name;
	char *buf;
	char **tetrimino_in_file;
	char **trimmed_tetrimino;
	int return_value;
	int ***test_array;
	int byte_size;


	//reads in file and checks to see if argument value is correct
	file_name = argv[argc - 1];
	if (argc != 2)
	{
		ft_putstr("wrong number of inputs: try again");
		return (0);
	}

	buf = read_information(file_name);
	byte_size = b_size(file_name);
	return_value = is_valid(buf, byte_size);
	tetrimino_in_file = (ft_tet_split(buf));
	//printf("%d %d\n",return_value, validate_tetrino(tetrimino_in_file));
	if (return_value == 0 || validate_tetrino(tetrimino_in_file) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	else
	{

		trimmed_tetrimino = trim_tetriminos(tetrimino_in_file, ft_tit_count(buf));
		test_array = ft_tet_coor(trimmed_tetrimino, ft_tit_count(buf));
		solver(ft_tit_count(buf), test_array, 2);
	}

}
