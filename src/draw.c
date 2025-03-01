/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:31:36 by kadrouin          #+#    #+#             */
/*   Updated: 2025/02/21 22:31:36 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*draw_mandelbrot(void *fractal_void)
{
	t_data	*fractal;
	int		iterations;
	int		color;

	fractal = (t_data *)fractal_void;
	fractal->x = 0;
	fractal->y = 0;
	iterations = 0;
	while (fractal->x < WIDTH)
	{
		while (fractal->y < HEIGHT)
		{
			iterations = calculate_mandelbrot(fractal);
			fractal->iterations[fractal->y * WIDTH + fractal->x] = iterations;
			color = apply_gradient(iterations, fractal);
			put_color_to_pixel(fractal, fractal->x, fractal->y, color);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	return (NULL);
}

void	*draw_julia(void *fractal_void)
{
	t_data	*fractal;
	int		iterations;
	int		color;

	fractal = (t_data *)fractal_void;
	fractal->x = 0;
	fractal->y = 0;
	iterations = 0;
	while (fractal->x < WIDTH)
	{
		while (fractal->y < HEIGHT)
		{
			iterations = calculate_julia(fractal);
			fractal->iterations[fractal->y * WIDTH + fractal->x] = iterations;
			color = apply_gradient(iterations, fractal);
			put_color_to_pixel(fractal, fractal->x, fractal->y, color);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	return (NULL);
}
