/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:10:42 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/13 00:12:41 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long int	ft_atol(const char *s)
{
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result * sign);
}
