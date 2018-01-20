/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:29:31 by ncella            #+#    #+#             */
/*   Updated: 2017/11/29 11:51:57 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *str, char c)
{
	char	**m;
	int		n;

	if (str == NULL)
		return (NULL);
	n = ft_nb_words(str, c);
	m = malloc(sizeof(char*) * n + 1);
	if (m == NULL)
		return (NULL);
	return (ft_strsplit_1(str, m, c));
}
