/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:55:51 by ncella            #+#    #+#             */
/*   Updated: 2017/11/10 09:55:59 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (((char*)str)[i] != '\0')
	{
		if (((char*)str)[i] == c)
			return (((char*)str) + i);
		i++;
	}
	if (c == '\0')
		return (((char*)str) + i);
	return (NULL);
}
