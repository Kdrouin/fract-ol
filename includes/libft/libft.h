/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:23:58 by kadrouin          #+#    #+#             */
/*   Updated: 2025/02/21 22:23:58 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_atod(const char *str);
void	ft_putendl_fd(char *s, int fd);
int		ft_strlen(char *str);
int		isdigit(int c);

#endif
