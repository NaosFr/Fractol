/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:05:36 by ncella            #+#    #+#             */
/*   Updated: 2017/11/13 17:53:22 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int nbr)
{
	char	*str;
	int		len_int;
	int		m;

	m = 0;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	len_int = ft_len_int(nbr);
	if (nbr < 0)
		m = 1;
	str = ft_strnew(len_int + m);
	if (str == NULL)
		return (NULL);
	nbr = ABS(nbr);
	str[len_int + 1] = '\0';
	if (m == 0)
		len_int--;
	str = ft_while_itoa(str, len_int, nbr);
	if (m == 1)
		str[0] = '-';
	return (str);
}
