/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:06:15 by ncella            #+#    #+#             */
/*   Updated: 2017/11/08 15:06:22 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char	*str;

	str = src;
	while (n != 0)
	{
		if (*str++ == (unsigned char)c)
			return ((void*)--str);
		n--;
	}
	return (NULL);
}
