/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:46:23 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/20 22:51:53 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_stacks(t_stack *stack)
// {
// 	t_node	*current_a;
// 	t_node	*current_b;

// 	current_a = stack->a;
// 	current_b = stack->b;
// 	ft_printf("Stack A:\n");
// 	while (current_a)
// 	{
// 		ft_printf("%d\n", current_a->value);
// 		current_a = current_a->next;
// 	}
// 	ft_printf("Stack B:\n");
// 	while (current_b)
// 	{
// 		ft_printf("%d\n", current_b->value);
// 		current_b = current_b->next;
// 	}
// }

static int	ps_check_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack->a)
		return (1);
	current = stack->a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (!stack->b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (1);
	if (!ps_parsing(argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	stack = ps_init_stack(argv);
	if (!stack)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!ps_check_sorted(stack))
		ps_sort(stack);
	ps_free_stack(stack);
	return (0);
}
