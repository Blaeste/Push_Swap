/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:52:22 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/03 14:04:52 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
/*
void	sort_3(t_nodes **a)
{
	t_nodes	*biggest;

	biggest = find_biggest(*a);
	if (biggest == *a)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->val > (*a)->next->val)
		sa(a);
}

void	move_a_to_b(t_nodes **a, t_nodes **b)
{
	t_nodes	*cheapest;

	cheapest = get_cheap(*a);
	if (cheapest->above_med && cheapest->target_node->above_med)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_med) && !(cheapest->target_node->above_med))
		rev_rotate_both(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_node, 'b');
	pb(b, a);
}

void	move_b_to_a(t_nodes **a, t_nodes **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}



void	ft_push_swap(t_nodes **a, t_nodes **b, int list_len)
{
	
	while (list_len-- > 3 && !stack_is_sorted(*a))
	{
		init_list(a, b, 'a');
		move_a_to_b(a, b);
	}
	sort_3(a);
	
	while (*b)
	{
		init_list(a, b, 'b');
		move_b_to_a(a, b);
	}
	min_on_top(a);
}
*/