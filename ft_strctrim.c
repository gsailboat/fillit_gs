/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:52:27 by gselbo            #+#    #+#             */
/*   Updated: 2016/12/01 22:10:22 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int  trim(char c)
{
	if (c == '.')
		return (1);
	return (0);
}
char        *ft_strctrim(const char *s)
{
	char    *start;
	char    *end;
	int     len;
	if (!s)
		return (0);
	len = ft_strlen(s);
	start = (char *)s;
	end = (char *)s + len - 1;
	while (trim(*start))
		++start;
	while (trim(*end) && end > start)
		--end;
	return (ft_strsub(start, 0, 1 + end - start));
}

