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

int	parse_query(char **query)
{
	if ((ft_strncmp(query[1], "mandelbrot", 10) == 0)
		|| (ft_strncmp(query[1], "1", 1) == 0))
		return (1);
	else if ((ft_strncmp(query[1], "julia", 5) == 0)
		|| (ft_strncmp(query[1], "2", 1) == 0))
		{
			if ((query[2] && query[3]) && (ft_atoi(query[2]) && ft_atoi(query[3])))
				return (2);
			else
				return (0);
		}
	else if ((ft_strncmp(query[1], "burningship", 11) == 0)
		|| (ft_strncmp(query[1], "3", 1) == 0))
		return (3);
	else
		return (0);
}
