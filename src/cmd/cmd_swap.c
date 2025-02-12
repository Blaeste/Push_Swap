/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:11:36 by eschwart          #+#    #+#             */
/*   Updated: 2025/01/23 10:36:14 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap(t_nodes **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_nodes **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_nodes **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_nodes **a, t_nodes **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
