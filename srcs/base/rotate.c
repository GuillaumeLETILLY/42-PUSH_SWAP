/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:54:39 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/20 22:52:27 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(t_stack *stack)
{
	rotate(&stack->a);
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	rotate(&stack->b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	ft_printf("rr\n");
}
