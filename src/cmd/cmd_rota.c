/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rota.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:30:35 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/04 12:55:04 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate(t_nodes **stack)
{
	t_nodes	*first;
	t_nodes	*last;

	if (!*stack || ft_list_len(*stack) == 1)
		return ;
	first = *stack;
	last = ft_stack_last(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_nodes **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_nodes **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_nodes **a, t_nodes **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
