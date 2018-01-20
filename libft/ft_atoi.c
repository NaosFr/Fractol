/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:56:33 by ncella            #+#    #+#             */
/*   Updated: 2017/11/29 11:58:30 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int j;
	int m;
	int val;
	int counter;

	i = 0;
	m = 1;
	val = 0;
	counter = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 7) || str[i] == '0')
		str++;
	if (*str == '+' || *str == '-')
		i++;
	if (*str == '-')
		m = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = str[i] - '0';
		val = val * 10 + j;
		counter++;
		i++;
	}
	return (ft_counter_atoi(counter, m, val));
}
