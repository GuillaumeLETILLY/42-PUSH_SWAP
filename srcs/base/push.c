/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 03:00:13 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/20 22:52:37 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->prev = tmp;
	*dst = tmp;
	(*dst)->prev = NULL;
}

void	pa(t_stack *stack)
{
	push(&stack->b, &stack->a);
	stack->size_b--;
	stack->size_a++;
	ft_printf("pa\n");
}

void	pb(t_stack *stack)
{
	push(&stack->a, &stack->b);
	stack->size_a--;
	stack->size_b++;
	ft_printf("pb\n");
}
