/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:46:23 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/17 00:58:49 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_list(t_ps *list)
{
	while (list)
	{
		ft_printf("A : %d\n", list->a);
		ft_printf("B : %d\n", list->b);
		list = list->next;
	}
}

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

bool	ps_check_sort(t_ps *list)
{
	if (!list || !list->next)
		return (false);
	while (list->next)
	{
		if (list->a > list->next->a)
			return (false);
		list = list->next;
	}
	return (true);
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
	print_list(list);
	ft_printf("\n");
	if (!ps_check_sort(list))
	{
		ps_sort_base(argc - 1, list);
		if (!ps_check_sort(list))
			ft_printf("NOP\n");
	}
	print_list(list);
	ps_free_data(list);
	return (0);
}
