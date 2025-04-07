/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:57:05 by kadrouin          #+#    #+#             */
/*   Updated: 2025/02/21 22:57:05 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_hook(int key_code, t_data *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal);
	else if (key_code == LEFT || key_code == Q)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT || key_code == D)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP || key_code == Z)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN || key_code == S)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == R || key_code == SPACE)
		init_fractal(fractal);
	else if (key_code == J || key_code == L || key_code == O
		|| key_code == P || key_code == M)
		change_julia(&fractal->cx, &fractal->cy, key_code);
	else if (key_code == MINUS || key_code == PLUS)
		change_iterations(fractal, key_code);
	draw_fractal(fractal, fractal->name, fractal->cx, fractal->cy);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_data *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	if (mouse_code != SCROLL_UP && mouse_code != SCROLL_DOWN)
		return (0);
	draw_fractal(fractal, fractal->name, fractal->cx, fractal->cy);
	return (0);
}
