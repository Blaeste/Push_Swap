/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:53:10 by eschwart          #+#    #+#             */
/*   Updated: 2025/01/28 10:53:08 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_append_node(t_nodes **stack, int n)
{
	t_nodes		*new_node;
	t_nodes		*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_nodes));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->val = n;
	new_node->index = 0;
	new_node->cost = 0;
	new_node->above_med = 0;
	new_node->cheapest = 0;
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	ft_init_a(t_nodes **a, char **args)
{
	int		i;
	long	n;


	i = 0;
	while (args[i])
	{
		if (ft_error_syntax(args[i]))
			ft_free_errors(a, args);
		n = ft_atol(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_free_errors(a, args);
		if (ft_error_dup(*a, (int)n))
			ft_free_errors(a, args);
		ft_append_node(a, (int)n);
		i++;
	}
}

void	prep_for_push(t_nodes **stack, t_nodes *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_med)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_med)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	set_target_b(t_nodes *a, t_nodes *b)
{
	t_nodes	*current_a;
	t_nodes	*target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->val > b->val && current_a->val < best_match)
			{
				best_match = current_a->val;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	ft_init_b(t_nodes *a, t_nodes *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
