/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:08:45 by eschwart          #+#    #+#             */
/*   Updated: 2025/01/28 10:32:22 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	current_index(t_nodes *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_list_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_med = 1;
		else
			stack->above_med = 0;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_nodes *a, t_nodes *b)
{
	t_nodes	*current_b;
	t_nodes	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = INT_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->val < a->val && current_b->val > best_match_index)
			{
				best_match_index = current_b->val;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == INT_MIN)
			a->target_node = find_biggest(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_anal_a(t_nodes *a, t_nodes *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_list_len(a);
	len_b = ft_list_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_med))
			a->cost = len_a - (a->index);
		if (a->target_node->above_med)
			a->cost += a->target_node->index;
		else
			a->cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheap(t_nodes *stack)
{
	long	cheapest_val;
	t_nodes	*cheapest_node;

	if (!stack)
		return ;
	cheapest_val = INT_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_val)
		{
			cheapest_val = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_nodes_a(t_nodes *a, t_nodes *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_anal_a(a, b);
	set_cheap(a);
}
