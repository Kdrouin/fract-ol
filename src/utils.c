/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:51:21 by kadrouin          #+#    #+#             */
/*   Updated: 2025/02/21 22:51:21 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_color_to_pixel(t_data *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

void	exit_fractal(t_data *fractal)
{
	if (fractal->image)
		mlx_destroy_image(fractal->mlx_ptr, fractal->image);
	if (fractal->win_ptr)
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	if (fractal->mlx_ptr)
		mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	free(fractal->iterations);
	free(fractal);
	exit(0);
}

void	change_iterations(t_data *fractal, int key_code)
{
	if (key_code == M || key_code == MINUS)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == P || key_code == PLUS)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}

void	zoom(t_data *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}

void	set_julia_params(t_data *fractal, double cx, double cy)
{
	if (!cx && !cy)
	{
		fractal->cx = -0.745429;
		fractal->cy = 0.05;
	}
	else
	{
		fractal->cx = cx;
		fractal->cy = cy;
	}
	fractal->name = "julia";
	draw_julia(fractal);
}
