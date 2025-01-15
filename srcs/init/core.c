/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:42:46 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/15 02:30:20 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_ps	*ps_create_node(char *value)
{
	t_ps	*new;

	new = malloc(sizeof(t_ps));
	if (!new)
		return (NULL);
	new->a = ft_atol(value);
	new->next = NULL;
	return (new);
}

static t_ps	*ps_push_value_to_a(char **value)
{
	t_ps	*list;
	t_ps	*current;
	t_ps	*new;
	int		i;

	i = 0;
	list = NULL;
	while (value[i])
	{
		new = ps_create_node(value[i]);
		if (!list)
			list = new;
		else
		{
			current = list;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		i++;
	}
	return (list);
}

// static void	print_list(t_ps *list)
// {
// 	while (list)
// 	{
// 		ft_printf("A : %d\n", list->a);
// 		ft_printf("B : %d\n", list->b);
// 		list = list->next;
// 	}
// }

t_ps	*ps_init_struct(char **argv)
{
	t_ps	*list;

	argv++;
	list = ps_push_value_to_a(argv);
	if (!list)
		return (NULL);
	return (list);
}
