/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:04:28 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/17 02:11:45 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ps_sort_three(t_ps *list)
{
	if (list->a > list->next->a && list->next->a < list->next->next->a
		&& list->a < list->next->next->a)
		sa(list);
	else if (list->a > list->next->a && list->next->a > list->next->next->a)
		(sa(list), rra(list));
	else if (list->a > list->next->a && list->next->a < list->next->next->a
		&& list->a > list->next->next->a)
		ra(list);
	else if (list->a < list->next->a && list->next->a > list->next->next->a
		&& list->a < list->next->next->a)
		(sa(list), ra(list));
	else if (list->a < list->next->a && list->next->a > list->next->next->a
		&& list->a > list->next->next->a)
		rra(list);
}

void	ps_sort_base(int argc, t_ps *list)
{
	if (argc <= 3)
		ps_sort_three(list);
}
