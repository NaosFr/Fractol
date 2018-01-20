/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:56:48 by ncella            #+#    #+#             */
/*   Updated: 2017/11/10 09:56:52 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s2, const char *s1, size_t n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (s1[tmp])
		tmp++;
	if (tmp == 0)
		return ((char*)s2);
	while (s2[i])
	{
		while (s1[j] == s2[i] && i < (int)n)
		{
			i++;
			j++;
			if (s1[j] == '\0')
				return (((char*)s2) + i - tmp);
		}
		i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
