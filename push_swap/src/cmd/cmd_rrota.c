/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rrota.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:47:02 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/04 12:55:08 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rrotate(t_nodes **stack)
{
	t_nodes	*last;

	if (!*stack || ft_list_len(*stack) == 1)
		return ;
	last = ft_stack_last(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_nodes **a)
{
	rrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_nodes **b)
{
	rrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_nodes **a, t_nodes **b)
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}
