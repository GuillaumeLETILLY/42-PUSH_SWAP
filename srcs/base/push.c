/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 03:00:13 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/13 03:34:35 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_push(t_nbr **src, t_nbr **dest)
{
	t_nbr	*tmp;

	if (src == NULL || *src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (dest)
	{
		tmp->next = *dest;
		*dest = tmp;
	}
}

void	pa(t_data *data)
{
	if (!data)
		return ;
	ft_push(&data->b, &data->a);
	ft_printf("pa\n");
}

void	pb(t_data *data)
{
	if (!data)
		return ;
	ft_push(&data->a, &data->b);
	ft_printf("pb\n");
}
