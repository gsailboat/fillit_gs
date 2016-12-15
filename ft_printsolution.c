/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 21:51:44 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/09 22:17:05 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

/*
** Prints out the board once the solver returns a true value. 
*/

void	printSolution(int N, char **grid)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < N)
    {
        while(j < N)
        {
            printf("%c", grid[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
}
