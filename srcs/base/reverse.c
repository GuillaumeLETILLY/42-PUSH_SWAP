/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 03:15:21 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/20 22:52:33 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack *stack)
{
	reverse_rotate(&stack->a);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	reverse_rotate(&stack->b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack)
{
	reverse_rotate(&stack->a);
	reverse_rotate(&stack->b);
	ft_printf("rrr\n");
}
