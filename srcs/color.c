/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:54:04 by ncella            #+#    #+#             */
/*   Updated: 2017/12/12 14:40:40 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		color1(int i)
{
	int color[9];

	color[0] = 0xf7df;
	color[1] = 0xff5a;
	color[2] = 0x07ff;
	color[3] = 0x7ffa;
	color[4] = 0xf7ff;
	color[5] = 0xf7bb;
	color[6] = 0xff38;
	color[7] = 0xff59;
	color[8] = 0x001f;
	return (color[i]);
}

static int		color2(int i)
{
	int color[7];

	color[0] = 0x784418;
	color[1] = 0xdb9e1d;
	color[2] = 0xdb9e1d;
	color[3] = 0x51001f;
	color[4] = 0xe5d6bb11;
	color[5] = 0x784418;
	color[6] = 0xdb9e1d;
	return (color[i]);
}

static int		color3(int i)
{
	int color[7];

	color[0] = 0x8754b3;
	color[1] = 0x9c6fda;
	color[2] = 0xbe8eed;
	color[3] = 0x8744a8;
	color[4] = 0x582c7f;
	color[5] = 0x8754b3;
	color[6] = 0x9c6fda;
	return (color[i]);
}

static int		color4(int i)
{
	int color[7];

	color[0] = 0x344583;
	color[1] = 0x000000;
	color[2] = 0xcccccc;
	color[3] = 0xbbbbbb;
	color[4] = 0xaaaaaa;
	color[5] = 0xcccccc;
	color[6] = 0xbbbbbb;
	return (color[i]);
}

int				ft_color(int i, t_mlx *smlx)
{
	if (smlx->type_color == 1)
		return (i * 255 / smlx->iteration_max);
	if (smlx->type_color == 2)
		return (color1(i % 6));
	if (smlx->type_color == 3)
		return (color2(i % 6));
	if (smlx->type_color == 4)
		return (color3(i % 6));
	if (smlx->type_color == 5)
		return (color4(i % 6));
	return (BLACK);
}
