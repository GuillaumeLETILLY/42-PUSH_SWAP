/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:46:23 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/15 00:44:48 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_free_data(t_ps *list)
{
	t_ps	*new;
	t_ps	*tmp;

	new = list;
	while (new)
	{
		tmp = new;
		new = new->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_ps	*list;

	if (argc < 2)
		return (1);
	if (!ps_parsing(argv))
		return (ft_putstr_fd("Error\n", 1), 1);
	list = ps_init_struct(argv);
	if (!list)
		return (ft_putstr_fd("Error\n", 1), 1);
	ps_free_data(list);
	return (0);
}
