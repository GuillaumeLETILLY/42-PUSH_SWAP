/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:42:46 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/20 22:52:23 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_node	*ps_create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void	ps_add_back(t_node **head, t_node *new)
{
	t_node	*last;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

void	ps_free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack)
		return ;
	current = stack->a;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	current = stack->b;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(stack);
}

t_stack	*ps_init_stack(char **argv)
{
	t_stack	*stack;
	t_node	*new;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	i = 1;
	while (argv[i])
	{
		new = ps_create_node(ft_atoi(argv[i]));
		if (!new)
			return (ps_free_stack(stack), NULL);
		ps_add_back(&stack->a, new);
		stack->size_a++;
		i++;
	}
	return (stack);
}
