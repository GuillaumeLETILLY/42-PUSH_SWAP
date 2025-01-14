/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:46:23 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/13 03:38:42 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	(void)argc;
	if (!ps_parsing(argv) || !ps_init_nbr(argv, data))
		return (ft_putstr_fd("Error\n", 1), 1);
	return (0);
}
