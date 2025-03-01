/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   calculate.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kadrouin <kadrouin@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/02/23 22:32:48 by kadrouin		  #+#	#+#			 */
/*   Updated: 2025/02/23 22:32:48 by kadrouin		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/fractol.h"

int	calculate_mandelbrot(t_data *fractal)
{
	int		i;
	double	x_temp;

	i = 0;
	fractal->name = "mandelbrot";
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx
			- fractal->zy * fractal->zy + fractal->cx;
		fractal->zy = 2.0 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
			break ;
		i++;
	}
	fractal->last_modulus = sqrt(fractal->zx
			* fractal->zx + fractal->zy * fractal->zy);
	return (i);
}

int	calculate_julia(t_data *fractal)
{
	int		i;
	double	tmp;

	fractal->name = "julia";
	fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
	i = 0;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
			break ;
	}
	fractal->last_modulus = sqrt(fractal->zx
			* fractal->zx + fractal->zy * fractal->zy);
	return (i);
}
