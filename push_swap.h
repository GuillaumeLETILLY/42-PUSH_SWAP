/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:49:01 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/13 03:19:03 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "utils/libft/libft.h"
# include "utils/ftprintf/ft_printf.h"

/* base nbr */
typedef struct s_nbr
{
	int				nbr;
	struct s_nbr	*next;
}	t_nbr;

/* struct nbr A & B */
typedef struct s_data
{
	t_nbr	*a;
	t_nbr	*b;
}	t_data;

/* parsing core */
bool	ps_parsing(char **argv);

/* init core */
t_data	*ps_init_nbr(char **argv, t_data *data);

/* base operations */
void	pa(t_data *data);
void	pb(t_data *data);

#endif
