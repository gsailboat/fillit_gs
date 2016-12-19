/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_tets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:18:28 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/06 17:22:20 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>


/*
** In order to pass norm, we might need to create three pointers to a char and 
** concatinate the strings, before we use ft_strsplit
*/

char	**valid_tetrimino(void)
{
	char **valid_tet_test;
	char *array = "####?#....#....#....#?##..##?#....##....#?##....##?#...##...#?##.\
..##?#....#....##?###..#?##....#....#?#..###?#....#...##?#....###?##...#....#?\
###....#?###...#?#...##....#?#...###?#....##...#?";

	valid_tet_test = ft_strsplit(array, '?');
	return (valid_tet_test);
 }