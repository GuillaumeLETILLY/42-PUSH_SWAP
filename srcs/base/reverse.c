/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 03:15:21 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/16 04:16:51 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_ps *list)
{
	t_ps	*last;
	t_ps	*prev;
	int		tmp;

	if (!list || !list->next)
		return ;
	last = list;
	while (last->next)
		last = last->next;
	tmp = last->a;
	while (last != list)
	{
		prev = list;
		while (prev->next != last)
			prev = prev->next;
		last->a = prev->a;
		last = prev;
	}
	list->a = tmp;
	ft_printf("rra\n");
}

void	rrb(t_ps *list)
{
	t_ps	*last;
	t_ps	*prev;
	int		tmp;

	if (!list || !list->next)
		return ;
	last = list;
	while (last->next)
		last = last->next;
	tmp = last->b;
	while (last != list)
	{
		prev = list;
		while (prev->next != last)
			prev = prev->next;
		last->b = prev->b;
		last = prev;
	}
	list->b = tmp;
	ft_printf("rrb\n");
}

void	rrr(t_ps *list)
{
	(rra(list), rrb(list));
	ft_printf("rrr\n");
}
