/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:02:14 by kadrouin          #+#    #+#             */
/*   Updated: 2025/02/21 22:02:14 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "key.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*pointer_to_image;
	void	*image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int		max_iterations;
	int		*iterations;
	double	last_modulus;
	char	*name;
	int		color;
}			t_data;

int		draw_fractal(t_data *fractal, char *query, double cx, double cy);
void	change_iterations(t_data *fractal, int key_code);
void	zoom(t_data *fractal, int x, int y, int zoom);

int		calculate_mandelbrot(t_data *fractal);
void	*draw_mandelbrot(void *fractal_void);
int		apply_gradient(int iter, t_data *fractal);

int		calculate_julia(t_data *fractal);
void	*draw_julia(void *fractal_void);
void	set_julia_params(t_data *fractal, double cx, double cy);
void	set_random_julia(double *cx, double *cy);
void	change_julia(double *cx, double *cy, int key_code);

int		close_window(int keycode, t_data *data);
int		key_hook(int key_code, t_data *fractal);
int		mouse_hook(int mouse_code, int x, int y, t_data *fractal);
void	exit_fractal(t_data *fractal);
void	init_fractal(t_data *fractal);
void	init_mlx(t_data *fractal);
void	put_color_to_pixel(t_data *fractal, int x, int y, int color);

int		parse_query(char **query, int argc);

#endif
