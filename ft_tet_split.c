/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tet_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:46:15 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/02 21:46:26 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

/*
**	count the number of words in the string. Allocate space for the num of words
**	count the num of letters in each word -> allocate space
*/

char		**ft_tet_split(const char *s)
{
	size_t	word;
	size_t	num_words;
	char	**words;
	char	*iter;

	if (!s)
		return (0);
	num_words = ft_tit_count(s);
	words = (char **)ft_memalloc(sizeof(char*) * (num_words + 1));
	if (!words)
		return (NULL);
	word = 0;
	while (word < num_words)
	{
		iter = ft_istwonew(s, num_words);
		if (iter)
			words[word] = ft_strsub(s, 0, iter - s);
		else
			words[word] = ft_strdup(s);
		s = iter;
		++word;
	}
	return (words);
}
