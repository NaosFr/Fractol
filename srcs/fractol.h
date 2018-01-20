/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:41:50 by ncella            #+#    #+#             */
/*   Updated: 2017/12/12 15:46:55 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600
# define ABS(Value) ((Value < 0) ? (Value * (-1)) : (Value))
# define BLACK 0x00000000

typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
	int			bpp;
	int			s_l;
	int			endian;
	char		*my_image_string;
	void		*pointeur_image;
	double		x1;
	double		y1;
	double		vx;
	double		vy;
	double		zoom;
	double		iteration_max;
	double		c_r;
	double		c_i;
	int			type_color;
	int			type_fractol;
	double		tmp;
}					t_mlx;

char				ft_fractal(t_mlx *smlx);
void				ft_algo_mandelbrot(int *img, t_mlx *smlx, int x, int y);
void				ft_algo_julia(int *img, t_mlx *smlx, int x, int y);
void				ft_algo_shadow(int *img, t_mlx *smlx, int x, int y);
void				ft_algo_illuma(int *img, t_mlx *smlx, int x, int y);
int					ft_key(int keycode, t_mlx *smlx);
int					ft_mouse_click(int keycode, int x, int y, t_mlx *smlx);
int					ft_mouse_move(int x, int y, t_mlx *smlx);
int					ft_color(int i, t_mlx *smlx);
void				ft_init(t_mlx *smlx);
void				ft_info(t_mlx *smlx);

#endif
