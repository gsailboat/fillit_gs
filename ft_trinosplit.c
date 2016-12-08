/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trinosplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:34:53 by gselbo            #+#    #+#             */
/*   Updated: 2016/12/02 22:52:27 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*static int  ft_countw(char const *string, char c)
{
	size_t  num_words;
	int     pointer;
	pointer = 1;
	num_words = 0;
	while (*string)
	{
		if (pointer != (*string == c))
			if (pointer)
				num_words++;
		pointer = (*string == c);
		string++;
	}
	return (num_words);
}
*/

static char		*ft_istwonew(char *s)
{
	char	*new;

	new = ft_strchr(s, '\n');
	if (++new == '\n')
		return (new++);
	return (new);
}

char    	    **ft_strsplit(const char *s, char c)
{
	size_t  word;
	size_t  num_words;
	char    **words;
	char    *iter;
	if (!s)
		return (0);
	num_words = ft_countw(s, c);
	words = (char **)ft_memalloc(sizeof(char*) * (num_words + 1));
	if (!words)
		return (NULL);
	word = 0;
	while (word < num_words)
	{
		while (*s == c)
			++s;
		iter = ft_strchr(s, c);
		if (iter)
			words[word] = ft_strsub(s, 0, iter - s);
		else
			words[word] = ft_strdup(s);
		s = iter;
		++word;
	}
	return (words);
}
