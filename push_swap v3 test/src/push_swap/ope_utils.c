/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:07:14 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/04 10:08:27 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	calc_rotations_a(t_ope *ops, t_nodes *a, t_nodes *target_a)
{
	int	list_size;

	list_size = ft_list_len(a);
	if (target_a->above_med)
		ops->ra = target_a->index;
	else
		ops->rra = list_size - target_a->index;
}

static void	calc_rotations_b (t_ope *ops, t_nodes *b, t_nodes *target_b)
{
	int	list_size;

	list_size = ft_list_len(b);
	if (target_b->above_med)
		ops->rb = target_b->index;
	else
		ops->rrb = list_size - target_b->index;
}

static void	calc_rr(t_ope *ops)
{
	if (ops->ra > 0 && ops->rb > 0)
	{
		if (ops->ra > ops->rb)
		{
			ops->rr = ops->rb;
			ops->ra -= ops->rb;
			ops->rb = 0;
		}
		else
		{
			ops->rr = ops->ra;
			ops->rb -= ops->ra;
			ops->ra = 0;
		}
	}
}

static void	calc_rrr(t_ope *ops)
{
	if (ops->rra > 0 && ops->rrb > 0)
	{
		if (ops->rra > ops->rrb)
		{
			ops->rrr = ops->rrb;
			ops->rra -= ops->rrb;
			ops->rrb = 0;
		}
		else
		{
			ops->rrr =  ops->rra;
			ops->rrb -= ops->rra;
			ops->rra = 0;
		}
	}
}

t_ope calc_ope(t_nodes *a, t_nodes *b, t_nodes *target_a, t_nodes *target_b)
{
	t_ope	ops;

	ops.ra = 0;
	ops.rb = 0;
	ops.rra = 0;
	ops.rrb = 0;
	ops.rr = 0;
	ops.rrr = 0;
	calc_rotations_a(&ops, a, target_a);
	calc_rotations_b(&ops, b, target_b);
	calc_rr(&ops);
	calc_rrr(&ops);
	ops.total = ops.ra + ops.rb + ops.rra + ops.rrb + ops.rr + ops.rrr;
	return (ops);
}
