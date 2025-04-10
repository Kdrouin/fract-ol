/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 23:12:03 by kadrouin          #+#    #+#             */
/*   Updated: 2025/02/21 23:12:03 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_space_n_sign(const char *str, int *i, int *sign)
{
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		*sign = 1 - 2 * (str[(*i)++] == '-');
	}
	return (*i);
}

double	ft_atod(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;
	int		divisor;

	sign = 1;
	i = 0;
	divisor = 1;
	result = 0.0;
	fraction = 0.0;
	i = ft_space_n_sign(str, &i, &sign);
	while (ft_isdigit(str[i]))
		result = result * 10.0 + (str[i++] - '0');
	if (str[++i] == '.')
	{
		while (ft_isdigit(str[i]))
		{
			fraction = fraction * 10.0 + (str[i++] - '0');
			divisor *= 10;
		}
		result += fraction / divisor;
	}
	return (result * sign);
}
