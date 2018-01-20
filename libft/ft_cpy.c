/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:18:01 by ncella            #+#    #+#             */
/*   Updated: 2017/11/13 18:18:03 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_cpy(int *argv, char **m, char const *str, char c)
{
	int y;
	int size;

	size = ft_length_words(argv[1], str, c);
	m[argv[0]] = malloc(size + 1);
	if (m[argv[0]] == NULL)
		return (NULL);
	y = 0;
	while (y < size)
	{
		m[argv[0]][y] = str[argv[1]];
		y++;
		argv[1]++;
	}
	m[argv[0]][y] = '\0';
	return (m);
}
