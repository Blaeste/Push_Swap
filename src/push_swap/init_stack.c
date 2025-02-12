/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:53:10 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/04 13:02:12 by eschwart         ###   ########.fr       */
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
		last_node = ft_stack_last(*stack);
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
