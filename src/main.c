/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:01:51 by kadrouin          #+#    #+#             */
/*   Updated: 2025/02/23 21:25:19 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	draw_fractal(t_data *fractal, char *query, double cx, double cy)
{
	fractal->x = 0;
	fractal->y = 0;
	(void)cx;
	(void)cy;
	while (fractal->x < WIDTH)
	{
		while (fractal->y < HEIGHT)
		{
			if ((ft_strncmp(query, "mandelbrot", 10) == 0)
				|| (ft_strncmp(query, "1", 1) == 0))
				calculate_mandelbrot(fractal);
			// else if ((ft_strncmp(query, "julia", 5) == 0)
			// 	|| (ft_strncmp(query, "2", 1) == 0))
			// 	calculate_julia(fractol, cx, cy);
			// else if ((ft_strncmp(query, "burningship", 11) == 0)
			// 	|| (ft_strncmp(query, "3", 1) == 0))
			// 	calculate_burningship(fractol);
			else
				return (1);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*fractal;
	(void)argc;

	if (parse_query(argv) == 0)
	{
		ft_putendl_fd("Usage: ./fractol <fractal>", 1);
		ft_putendl_fd("Available fractals: mandelbrot, julia, burningship or 1, 2, 3", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_data));
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->win_ptr, key_hook, fractal);
	mlx_mouse_hook(fractal->win_ptr, mouse_hook, fractal);
	mlx_hook(fractal->win_ptr, 17, 0L, exit_fractal, fractal);
	if (parse_query(argv) == 2)
		draw_fractal(fractal, argv[1], atoi(argv[2]), atoi(argv[3]));
	else
		draw_fractal(fractal, argv[1], 0, 0);
	mlx_loop(fractal->mlx_ptr);
	return (0);
}
