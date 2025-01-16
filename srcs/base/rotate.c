/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:54:39 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/16 02:38:30 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_ps *list)
{
	int	tmp;

	if (!list && !list->next)
		return ;
	tmp = list->a;
	while (list->next)
	{
		list->a = list->next->a;
		list = list->next;
	}
	list->a = tmp;
	ft_printf("ra\n");
}

void	rb(t_ps *list)
{
	int	tmp;

	if (!list || !list->next)
		return ;
	tmp = list->b;
	while (list->next)
	{
		list->b = list->next->b;
		list = list->next;
	}
	list->b = tmp;
	ft_printf("rb\n");
}

void	rr(t_ps *list)
{
	(ra(list), rb(list));
	ft_printf("rr\n");
}
