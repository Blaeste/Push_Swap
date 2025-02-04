/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:23:42 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/03 14:17:26 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_nodes	*find_smallest_val(t_nodes *list)
{
	int		smallest_val;
	t_nodes	*smallest_val_list;

	smallest_val = INT_MAX;
	smallest_val_list = NULL;
	while (list)
	{
		if (list->val < smallest_val)
		{
			smallest_val = list->val;
			smallest_val_list = list;
		}
		list = list->next;
	}
	return (smallest_val_list);
}

t_nodes	*find_biggest_val(t_nodes *list)
{
	int		largest_val;
	t_nodes	*largest_val_list;

	largest_val = INT_MIN;
	largest_val_list = NULL;
	while (list)
	{
		if (list->val > largest_val)
		{
			largest_val = list->val;
			largest_val_list = list;
		}
		list = list->next;
	}
	return (largest_val_list);
}

void operations_count(t_nodes *a, t_nodes *b, char name)
{
	t_ope	ops;
	t_nodes	*list;

	list = NULL;
	if (name == 'a')
		list = a;
	else if (name == 'b')
		list = b;
	while (list)
	{
		if (list->target_node)
		{
			if (name == 'a')
				ops = calc_ope(a, b, list, list->target_node);
			else if (name == 'b')
				ops = calc_ope(a, b, list->target_node, list);
			list->cost = ops.total;
		}
		list = list->next;
	}
}

void	get_index_med(t_nodes *list)
{
	int	i;
	int	median;

	i = 0;
	median = ft_list_len(list) / 2;
	while (list)
	{
		list->index = i;
		if (list->index <= median)
			list->above_med = 1;
		else
			list->above_med = 0;
		i++;
		list = list->next;
	}
}

void	align_before_push(t_nodes **list, t_nodes *top_node, char name)
{
	if (!list || !*list || !top_node)
		return ;
	while (*list != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_med)
				ra(list);
			else
				rra(list);
		}
		else if (name == 'b')
		{
			if (top_node->above_med)
				rb(list);
			else
				rrb(list);
		}
	}
}
