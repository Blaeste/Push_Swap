/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:26:18 by eschwart          #+#    #+#             */
/*   Updated: 2025/01/23 10:40:01 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_nodes	*ft_find_last(t_nodes *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_is_sorted(t_nodes *stack)
{
	t_nodes	*current;

	if (!stack || !stack->next)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->val > current->next->val)
			return (0);
		current = current->next;
	}
	return (1);
}

t_nodes	*find_biggest(t_nodes *a)
{
	t_nodes	*biggest;
	t_nodes	*current;

	if (!a)
		return (NULL);
	biggest = a;
	current = a->next;
	while (current)
	{
		if (current->val > biggest->val)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

t_nodes	*find_min(t_nodes *stack)
{
	long	min;
	t_nodes	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->val < min)
		{
			min = stack->val;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_nodes	*get_cheap(t_nodes *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
