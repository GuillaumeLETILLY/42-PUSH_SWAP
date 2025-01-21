/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:44:58 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/20 22:52:25 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
	*stack = second;
}

void	sa(t_stack *stack)
{
	swap(&stack->a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	swap(&stack->b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack)
{
	swap(&stack->a);
	swap(&stack->b);
	ft_printf("ss\n");
}
