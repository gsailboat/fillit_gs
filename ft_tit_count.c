/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tit_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:38:32 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/02 21:42:55 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_tit_count(char const *string)
{
	int count;
	int i;

	count = 1;
	i = 0;

	if (!string)
		return (0);
	while (string[i] != '\0')
	{
		if(string[i] == '\n' && string[i+1] =='\n')
			count++;
		i++;
	}
	return(count);
}
