/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:42:46 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/13 03:24:11 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_nbr	*ps_create_nbr(char *value)
{
	t_nbr	*new;

	new = malloc(sizeof(t_nbr));
	if (!new)
		return (NULL);
	new->nbr = ft_atol(value);
	new->next = NULL;
	return (new);
}

static void	ps_init_add_back_nbr(char **argv, t_data *data)
{
	int		i;
	t_nbr	*current;

	i = 2;
	current = data->a;
	while (argv[i])
	{
		while (current->next)
			current = current->next;
		current->next = ps_create_nbr(argv[i]);
		if (!current->next)
			return ;
		i++;
	}
}

t_data	*ps_init_nbr(char **argv, t_data *data)
{
	t_nbr	*first;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	first = ps_create_nbr(argv[1]);
	if (!first)
	{
		free(data);
		return (NULL);
	}
	data->a = first;
	data->b = NULL;
	ps_init_add_back_nbr(argv, data);
	return (data);
}
