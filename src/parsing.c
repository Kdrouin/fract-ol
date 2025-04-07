/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 23:10:40 by kadrouin          #+#    #+#             */
/*   Updated: 2025/02/21 23:10:40 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	is_double(const char *str)
{
	int	has_decimal;
	int	has_digit;

	has_decimal = 0;
	has_digit = 0;
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			if (has_decimal)
				return (0);
			has_decimal = 1;
		}
		else if (!isdigit(*str))
			return (0);
		else
			has_digit = 1;
		str++;
	}
	return (has_digit);
}

int	parse_query(char **query, int argc)
{
	if (!query[1])
	{
		ft_putendl_fd("Error: No parameters provided", 1);
		return (0);
	}
	if ((ft_strncmp(query[1], "mandelbrot\0", 11) == 0) && (argc == 2))
		return (1);
	else if ((ft_atod(query[1]) == 1) && (argc == 2))
		return(1);
	else if (((ft_strncmp(query[1], "julia\0", 6) == 0)
				|| (ft_strncmp(query[1], "1", 2))) && (argc == 4))
	{
		if (!is_double(query[2]) || !is_double(query[3]))
		{
			ft_putendl_fd("Error: Invalid parameters for Julia set", 1);
			return (0);
		}
		else
			return (2);
	}
	ft_putendl_fd("Usage: ./fractol (Mandelbrot or 1) (Julia or 2)", 1);
	return (0);
}
