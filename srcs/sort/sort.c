/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:15:31 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/20 23:05:54 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (stack->size_a != 3 || is_sorted(stack->a))
		return ;
	a = stack->a->value;
	b = stack->a->next->value;
	c = stack->a->next->next->value;
	if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a > b && b < c && a < c)
		sa(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

static int	get_min_pos(t_node *stack)
{
	int		min;
	int		pos;
	int		min_pos;
	t_node	*current;

	if (!stack)
		return (-1);
	min = INT_MAX;
	pos = 0;
	min_pos = 0;
	current = stack;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

static void	sort_five(t_stack *stack)
{
	int	min_pos;

	if (is_sorted(stack->a))
		return ;
	while (stack->size_a > 3)
	{
		min_pos = get_min_pos(stack->a);
		if (min_pos <= stack->size_a / 2)
		{
			while (min_pos--)
				ra(stack);
		}
		else
		{
			while (min_pos++ < stack->size_a)
				rra(stack);
		}
		pb(stack);
	}
	sort_three(stack);
	while (stack->size_b)
		pa(stack);
}

void	ps_sort(t_stack *stack)
{
	if (!stack || !stack->a || is_sorted(stack->a))
		return ;
	if (stack->size_a == 2)
	{
		if (stack->a->value > stack->a->next->value)
			sa(stack);
	}
	else if (stack->size_a == 3)
		sort_three(stack);
	else if (stack->size_a <= 5)
		sort_five(stack);
	else
		ps_sort_big(stack);
}
