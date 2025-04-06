/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:01:51 by kadrouin          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/06 22:49:17 by kadrouin         ###   ########.fr       */
=======
/*   Updated: 2025/04/06 20:14:11 by kadrouin         ###   ########.fr       */
>>>>>>> 692955cdd8939875b6ca2fb0cd38495742a4f0a0
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	draw_fractal(t_data *fractal, char *query, double cx, double cy)
{
	fractal->x = 0;
	fractal->y = 0;
	if (ft_strncmp(query, "mandelbrot", 10) == 0
		|| ft_strncmp(query, "1", 1) == 0)
	{
		fractal->name = "mandelbrot";
		draw_mandelbrot(fractal);
	}
	else if (ft_strncmp(query, "julia", 5) == 0
		|| ft_strncmp(query, "2", 1) == 0)
	{
		set_julia_params(fractal, cx, cy);
		fractal->name = "julia";
		draw_julia(fractal);
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->image, 0, 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*fractal;

	if (parse_query(argv, argc) == 0)
		return (0);
	fractal = malloc(sizeof(t_data));
	if (!fractal)
	{
<<<<<<< HEAD
		ft_putendl_fd("Error: malloc failed", 1);
=======
		ft_putendl_fd("Usage: ./fractol (1 , 2 , Mandelbrot or Julia)", 1);
>>>>>>> 692955cdd8939875b6ca2fb0cd38495742a4f0a0
		return (0);
	}
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->win_ptr, key_hook, fractal);
	mlx_mouse_hook(fractal->win_ptr, mouse_hook, fractal);
	mlx_hook(fractal->win_ptr, 17, 0L, (void *)exit_fractal, fractal);
	if (parse_query(argv, argc) == 2)
		draw_fractal(fractal, argv[1], atoi(argv[2]), atoi(argv[3]));
	else
		draw_fractal(fractal, argv[1], 0, 0);
	mlx_loop(fractal->mlx_ptr);
	return (0);
}
