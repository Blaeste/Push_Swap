/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:42:04 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/03 13:53:21 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	reset_move(t_nodes *list)
{
	while (list)
	{
		list->cheapest = 0;
		list = list->next;
	}
}

void	quickest_move(t_nodes *list)
{
	int		lowest_ope;
	t_nodes	*tmp;

	lowest_ope = INT_MAX;
	tmp = NULL;
	reset_move(list);
	while (list)
	{
		if (list->cost < lowest_ope)
		{
			lowest_ope = list->cost;
			tmp = list;
		}
		list = list->next;
	}
	if (tmp)
		tmp->cheapest = 1;
}

t_nodes	*get_quickest_move(t_nodes *list)
{
	while (list)
	{
		if (list->cheapest == 1)
			return (list);
		list = list->next;
	}
	return (NULL);
}
