/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:19:56 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/04 13:05:12 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	move_a_to_b(t_nodes **a, t_nodes **b)
{
	t_nodes	*cheapest;
	t_ope	ops;

	cheapest = get_quickest_move(*a);
	if (!cheapest)
		return ;
	if (!cheapest->target_node)
		return (align_before_push(a, cheapest, 'a'), pb(b, a));
	ops = calc_ope(*a, *b, cheapest, cheapest->target_node);
	while (ops.rr-- > 0)
		rr(a, b);
	while (ops.rrr-- > 0)
		rrr(a, b);
	while (ops.ra-- > 0)
		ra(a);
	while (ops.rb-- > 0)
		rb(b);
	while (ops.rra-- > 0)
		rra(a);
	while (ops.rrb-- > 0)
		rrb(b);
	pb(b, a);
}

static void	move_b_to_a(t_nodes **b, t_nodes **a)
{
	t_nodes	*cheapest;
	t_ope	ops;

	cheapest = get_quickest_move(*b);
	if (!cheapest)
		return ;
	if (!cheapest->target_node)
		return (align_before_push(b, cheapest, 'b'), pa(a, b));
	ops = calc_ope(*a, *b, cheapest->target_node, cheapest);
	while (ops.rr-- > 0)
		rr(a, b);
	while (ops.rrr-- > 0)
		rrr(a, b);
	while (ops.ra-- > 0)
		ra(a);
	while (ops.rb-- > 0)
		rb(b);
	while (ops.rra-- > 0)
		rra(a);
	while (ops.rrb-- > 0)
		rrb(b);
	pa(a, b);
}

static void	min_on_top(t_nodes **a)
{
	t_nodes	*list_with_smallest_number;

	list_with_smallest_number = find_smallest_val(*a);
	if (list_with_smallest_number == NULL)
		return ;
	get_index_med(*a);
	while (*a != list_with_smallest_number)
	{
		if (list_with_smallest_number->above_med)
			ra(a);
		else
			rra(a);
	}
}

static void	init_list(t_nodes *a, t_nodes *b, char name)
{
	get_index_med(a);
	get_index_med(b);
	if (name == 'a')
	{
		get_target_a(a, b);
		operations_count(a, b, 'a');
		quickest_move(a);
	}
	else if (name == 'b')
	{
		get_target_b(a, b);
		operations_count(a, b, 'b');
		quickest_move(b);
	}
}

void	sort_turk(t_nodes **a, t_nodes **b, int list_len)
{
	while (list_len > 3 && !stack_is_sorted(*a))
	{
		init_list(*a, *b, 'a');
		move_a_to_b(a, b);
		list_len--;
	}
	sort_3(a);
	while (*b)
	{
		init_list(*a, *b, 'b');
		move_b_to_a(b, a);
	}
	min_on_top(a);
}
