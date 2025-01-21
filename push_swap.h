/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:49:01 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/20 23:05:36 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "utils/libft/libft.h"
# include "utils/ftprintf/ft_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
}	t_stack;

/* parsing core */
bool		ps_parsing(char **argv);
t_stack		*ps_init_stack(char **argv);
void		ps_free_stack(t_stack *stack);

/* operations */
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);
void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);

/* utils */
int			find_min(t_node *stack);
int			find_max(t_node *stack);
int			get_index(t_node *stack, int value);

/* sort */
void		ps_sort_big(t_stack *s);
void		ps_sort(t_stack *stack);

#endif