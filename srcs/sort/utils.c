/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:58:31 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/20 22:52:10 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	find_min(t_node *stack)
{
	int		min;
	t_node	*current;

	if (!stack)
		return (0);
	min = stack->value;
	current = stack->next;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_max(t_node *stack)
{
	int		max;
	t_node	*current;

	if (!stack)
		return (0);
	max = stack->value;
	current = stack->next;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_index(t_node *stack, int value)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack;
	while (current)
	{
		if (current->value == value)
			return (i);
		i++;
		current = current->next;
	}
	return (-1);
}
