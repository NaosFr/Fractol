/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:46:06 by ncella            #+#    #+#             */
/*   Updated: 2017/12/12 11:58:05 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init(t_mlx *smlx)
{
	if (smlx->type_fractol == 1 || smlx->type_fractol == 3 ||
			smlx->type_fractol == 4)
	{
		smlx->zoom = 300;
		smlx->x1 = -2.1;
		smlx->y1 = -1;
		smlx->iteration_max = 50;
	}
	else if (smlx->type_fractol == 2)
	{
		smlx->zoom = 200;
		smlx->x1 = -2.1;
		smlx->y1 = -1.5;
		smlx->iteration_max = 150;
		smlx->c_r = 0.285;
		smlx->c_i = 0.01;
	}
	if (smlx->type_fractol == 3)
		smlx->x1 = -1.4;
}
