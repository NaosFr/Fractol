/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:19:22 by ncella            #+#    #+#             */
/*   Updated: 2017/11/29 11:51:58 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit_1(char const *str, char **m, char c)
{
	int		adresse;
	int		i;
	int		argv[2];

	i = 0;
	adresse = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i] != '\0')
		{
			argv[1] = i;
			argv[0] = adresse;
			m = ft_cpy(argv, m, str, c);
			adresse++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	m[adresse] = 0;
	return (m);
}
