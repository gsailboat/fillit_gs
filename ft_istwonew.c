/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istwonew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:46:32 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/02 22:47:22 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char     *ft_istwonew(const char *s, size_t num_words)
{
	char    *new;

	if (num_words == 1)
	{
		new = (char *)s + 20;
		return (new);
	}
	else 
	{
		new  = (char *)s;
		while (*new != '\0')
		{
			if (*new == '\n' && *(++new) == '\n')
				return (new);
			++new;
		}	
	}
	return (new);
}
