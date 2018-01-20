/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:08:24 by ncella            #+#    #+#             */
/*   Updated: 2017/11/13 18:08:25 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_counter_atoi(int counter, int m, int val)
{
	if (counter > 12 && m == 1)
		return (-1);
	if (counter > 12 && m == -1)
		return (0);
	else
	{
		val = val * m;
		return (val);
	}
}
