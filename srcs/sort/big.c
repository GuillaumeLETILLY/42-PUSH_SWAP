/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:15:31 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/21 03:23:18 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (size / 4);
	return (size / 10);
}

static void	push_to_b_optimized(t_stack *s, int start, int end)
{
	int		size;
	int		pushed;
	int		i;
	int		mid;

	size = s->size_a;
	pushed = 0;
	i = 0;
	mid = (start + end) / 2;
	while (i < size && s->size_a)
	{
		if (s->a->value >= start && s->a->value <= end)
		{
			pb(s);
			if (s->b->value < mid && s->size_b > 1)
				rb(s);
			pushed++;
		}
		else if (s->size_a > 1)
			ra(s);
		i++;
	}
}

static void	push_back_to_a(t_stack *s)
{
	int	max;
	int	pos;
	int	size;

	while (s->size_b)
	{
		max = find_max(s->b);
		pos = get_index(s->b, max);
		size = s->size_b;
		if (pos <= size / 2)
			while (s->b->value != max)
				rb(s);
		else
			while (s->b->value != max)
				rrb(s);
		pa(s);
	}
}

void	ps_sort_big(t_stack *s)
{
	int	min;
	int	max;
	int	chunk_size;
	int	i;

	if (!s || !s->a || s->size_a <= 5)
		return ;
	min = find_min(s->a);
	max = find_max(s->a);
	chunk_size = get_chunk_size(s->size_a);
	i = 0;
	while (i * chunk_size <= max - min)
	{
		push_to_b_optimized(s, min + (i * chunk_size),
			min + ((i + 1) * chunk_size) - 1);
		i++;
	}
	push_back_to_a(s);
}
