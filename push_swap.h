/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:49:01 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/16 04:15:10 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "utils/libft/libft.h"
# include "utils/ftprintf/ft_printf.h"

/* base nbr */
typedef struct s_ps
{
	int				a;
	int				b;
	struct s_ps		*next;
}	t_ps;

/* parsing core */
bool	ps_parsing(char **argv);

/* init core */
t_ps	*ps_init_struct(char **argv);

/* operations core */
void	sa(t_ps *list);
void	sb(t_ps *list);
void	ss(t_ps *list);
void	pa(t_ps *list);
void	pb(t_ps *list);
void	ra(t_ps *list);
void	rb(t_ps *list);
void	rr(t_ps *list);
void	rra(t_ps *list);
void	rrb(t_ps *list);
void	rrr(t_ps *list);

#endif
