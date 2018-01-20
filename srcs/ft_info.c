/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naos <naos@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:55:21 by ncella            #+#    #+#             */
/*   Updated: 2017/12/12 11:57:28 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_info(t_mlx *smlx)
{
	mlx_string_put(smlx->mlx, smlx->win, 10, 0, 0x00FFFFFF, "=== ncella ===");
	mlx_string_put(smlx->mlx, smlx->win, 10, 30, 0x00FFFFFF, "up         : w");
	mlx_string_put(smlx->mlx, smlx->win, 10, 50, 0x00FFFFFF, "down       : s");
	mlx_string_put(smlx->mlx, smlx->win, 10, 70, 0x00FFFFFF, "left       : a");
	mlx_string_put(smlx->mlx, smlx->win, 10, 90, 0x00FFFFFF, "rigth      : d");
	mlx_string_put(smlx->mlx, smlx->win, 10, 110, 0x00FFFFFF,
			"next->     : space");
	mlx_string_put(smlx->mlx, smlx->win, 10, 130, 0x00FFFFFF,
			"use mouse  : zoom");
	mlx_string_put(smlx->mlx, smlx->win, 10, 150, 0x00FFFFFF,
			"1->5       : color");
	mlx_string_put(smlx->mlx, smlx->win, 10, 170, 0x00FFFFFF,
			"exit       : esc");
}
