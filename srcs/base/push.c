/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 03:00:13 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/17 01:47:53 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pb(t_ps *list)
{
	t_ps	*tmp;

	if (!list || !list->next)
		return ;
	tmp = list->next;
	list->next = list->next;
	list->b = list->a;
	list->a = 0;
	ft_printf("pb\n");
}

void	pa(t_ps *list)
{
	t_ps	*tmp;

	if (!list || !list->next)
		return ;
	tmp = list->next;
	list->next = list->next;
	list->a = list->b;
	list->b = 0;
	ft_printf("pa\n");
}
