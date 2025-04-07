/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 04:33:04 by kadrouin          #+#    #+#             */
/*   Updated: 2025/03/01 04:33:04 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	apply_gradient(int iter, t_data *fractal)
{
	double	smooth_iter;
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == fractal->max_iterations)
		return (0);
	if (fractal->last_modulus <= 0.0)
		fractal->last_modulus = 1e-10;
	smooth_iter = iter + 1 - log(log(fractal->last_modulus)) / log(2);
	t = smooth_iter / fractal->max_iterations;
	if (t < 0.0)
		t = 0.0;
	if (t > 1.0)
		t = 1.0;
	r = (int)(128 + 127 * sin(6.28318 * t));
	g = (int)(128 + 127 * sin(6.28318 * t + 2.09439));
	b = (int)(128 + 127 * sin(6.28318 * t + 4.18879));
	return (r << 16 | g << 8 | b);
}

void	set_random_julia(double *cx, double *cy)
{
	*cx = (double)rand() / RAND_MAX * 4 - 2;
	*cy = (double)rand() / RAND_MAX * 4 - 2;
}

void	change_julia(double *cx, double *cy, int key_code)
{
	if (key_code == J)
		set_random_julia(cx, cy);
	else if (key_code == L)
		*cy += 0.1;
	else if (key_code == O)
		*cy -= 0.1;
	else if (key_code == P)
		*cx -= 0.1;
	else if (key_code == M)
		*cx += 0.1;
}
