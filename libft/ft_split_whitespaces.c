/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:12:35 by ncella            #+#    #+#             */
/*   Updated: 2017/12/09 10:33:56 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_words(char *str)
{
	int i;
	int n;
	int tmp;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\n' && str[i] != '\0' && str[i] != ' ')
		{
			i++;
			tmp = 1;
		}
		if (str[i] == '\n' || str[i] == '\0' || str[i] == ' ')
		{
			if (tmp == 1)
				n++;
			if (str[i] != '\0')
				i++;
			tmp = 0;
		}
	}
	return (n);
}

static int		length_words(int i, char *str)
{
	int size;

	size = 0;
	while (str[i] != '\n' && str[i] != ' ')
	{
		i++;
		size++;
	}
	return (size);
}

static char		**cpy(int adresse, int i, char **m, char *str)
{
	int y;
	int size;

	size = length_words(i, str);
	m[adresse] = malloc(size + 1);
	y = 0;
	while (y < size)
	{
		m[adresse][y] = str[i];
		y++;
		i++;
	}
	m[adresse][y] = '\0';
	return (m);
}

char			**ft_split_whitespaces(char *str)
{
	char	**m;
	int		n;
	int		i;
	int		adresse;

	adresse = 0;
	n = nb_words(str);
	i = 0;
	m = malloc(sizeof(char*) * n + 1);
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != ' ')
		{
			m = cpy(adresse, i, m, str);
			adresse++;
			while (str[i] != '\n' && str[i] != ' ')
				i++;
		}
		else
			i++;
	}
	m[adresse] = 0;
	return (m);
}
