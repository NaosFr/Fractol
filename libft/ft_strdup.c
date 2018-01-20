/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:44:38 by ncella            #+#    #+#             */
/*   Updated: 2017/11/07 18:44:40 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*tmp;

	i = 0;
	while (src[i] != '\0')
		i++;
	tmp = malloc(i + 1);
	if (tmp == NULL)
		return (NULL);
	tmp = ft_strcpy(tmp, (char*)src);
	return (tmp);
}
