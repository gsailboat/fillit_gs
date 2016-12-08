/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:48:58 by gselbo            #+#    #+#             */
/*   Updated: 2016/12/01 23:04:32 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_change(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			s[i] = ('.');
		if (s[i + 2] == '\0' || (s[i + 1] == '\n' && s[i + 2] == '\n'))
			break ;
		i++;
	}
	return (s);
}
