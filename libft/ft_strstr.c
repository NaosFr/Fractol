/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:59:42 by ncella            #+#    #+#             */
/*   Updated: 2017/11/09 10:08:45 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *str;
	const char *find;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		str = s1;
		find = s2;
		while (*find != '\0' && *str == *find)
		{
			str++;
			find++;
		}
		if (*find == '\0')
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
