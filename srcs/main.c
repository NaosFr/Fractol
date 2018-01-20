/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:35:56 by ncella            #+#    #+#             */
/*   Updated: 2017/12/14 09:47:58 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_error(char *str)
{
	ft_putstr(str);
	return (1);
}

static int		fill_pixel(t_mlx *smlx)
{
	ft_init(smlx);
	smlx->type_color = 1;
	ft_fractal(smlx);
	mlx_put_image_to_window(smlx->my_image_string, smlx->win,
			smlx->pointeur_image, 0, 0);
	mlx_hook(smlx->win, 2, 3, ft_key, smlx);
	mlx_mouse_hook(smlx->win, ft_mouse_click, smlx);
	mlx_hook(smlx->win, 6, (1L << 6), ft_mouse_move, smlx);
	ft_info(smlx);
	mlx_loop(smlx->mlx);
	ft_memdel((void**)&smlx);
	return (1);
}

static int		check_type_map(t_mlx *smlx, char *str)
{
	smlx->type_fractol = 0;
	if (ft_strcmp(str, "mandelbrot") == 0)
	{
		smlx->type_fractol = 1;
		return (1);
	}
	else if (ft_strcmp(str, "julia") == 0)
	{
		smlx->type_fractol = 2;
		return (1);
	}
	else if (ft_strcmp(str, "shadow") == 0)
	{
		smlx->type_fractol = 3;
		return (1);
	}
	else if (ft_strcmp(str, "illuma") == 0)
	{
		smlx->type_fractol = 4;
		return (1);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_mlx	*smlx;

	if (argc != 2)
	{
		ft_error("\033[31m[ ✘ ] ./fractol [NAME]\n");
		return (ft_error("mandelbrot | julia | shadow | illuma\n"));
	}
	if ((smlx = malloc(sizeof(t_mlx))) == NULL)
		return (ft_error("\033[31m[ ✘ ] error malloc\n"));
	if ((smlx->mlx = mlx_init()) == NULL)
		return (ft_error("\033[31m[ ✘ ] mlx couldn't init\n"));
	if (check_type_map(smlx, argv[1]) == 0)
		return (ft_error("\033[31m[ ✘ ] error name\n"));
	smlx->win = mlx_new_window(smlx->mlx, WIDTH, HEIGHT, "Fractol 42");
	smlx->pointeur_image = mlx_new_image(smlx->mlx, WIDTH, HEIGHT);
	smlx->my_image_string = mlx_get_data_addr(smlx->pointeur_image,
			&(smlx->bpp), &(smlx->s_l), &(smlx->endian));
	if (fill_pixel(smlx) == 0)
		return (ft_error("\033[31m[ ✘ ] error\n"));
	return (0);
}
