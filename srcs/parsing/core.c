/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 23:19:50 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/13 00:41:48 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static bool	ps_pasring_check_overflow(const char *s)
{
	int		result;
	int		sign;

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
		result = result + 1;
		s++;
	}
	if (result > 10)
		return (false);
	return (true);
}

static bool ps_check_doublon(char **argv)
{
	int i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	ps_check_min_max(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX
			|| ft_atol(argv[i]) < INT_MIN
			|| !ps_pasring_check_overflow(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	ps_check_is_nbr(char **argv)
{
	int	i;
	int	c;

	i = 1;
	while (argv[i])
	{
		c = 0;
		while (argv[i][c])
		{
			if (!ft_isdigit(argv[i][c])
				&& argv[i][c] != '-' && argv[i][c] != '+')
				return (false);
			c++;
		}
		i++;
	}
	return (true);
}

bool	ps_parsing(char **argv)
{
	if (!ps_check_is_nbr(argv)
		|| !ps_check_min_max(argv)
		|| !ps_check_doublon(argv))
		return (false);
	return (true);
}
