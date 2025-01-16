/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:44:58 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/16 02:11:10 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_ps *list)
{
	int	tmp;

	if (!list || !list->next)
		return ;
	tmp = list->a;
	list->a = list->next->a;
	list->next->a = tmp;
	ft_printf("sa\n");
}

void	sb(t_ps *list)
{
	int	tmp;

	if (!list || !list->next)
		return ;
	tmp = list->b;
	list->b = list->next->b;
	list->next->b = tmp;
	ft_printf("sb\n");
}

void	ss(t_ps *list)
{
	if (!list || !list->next)
		return ;
	sa(list);
	sb(list);
	ft_printf("ss\n");
}
