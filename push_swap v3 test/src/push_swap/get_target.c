/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:45:09 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/04 10:04:14 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static t_nodes	*find_close_small(t_nodes *b, int val_a)
{
	int		closest_small_val;
	t_nodes	*target;

	closest_small_val = INT_MIN;
	target = NULL;
	while (b)
	{
		if (b->val < val_a && b->val > closest_small_val)
		{
			closest_small_val = b->val;
			target = b;
		}
		b = b->next;
	}
	return (target);
}

void	get_target_a(t_nodes *a, t_nodes *b)
{
	t_nodes	*target;

	if (b == NULL || ft_list_len(b) == 0)
		return ;
	while (a)
	{
		target = find_close_small(b, a->val);
		if (target == NULL)
			a->target_node = find_biggest_val(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

static t_nodes	*find_close_big(t_nodes *a, int val_b)
{
	int		closest_big_val;
	t_nodes	*target;

	closest_big_val = INT_MAX;
	target = NULL;
	while (a)
	{
		if (a->val < val_b && a->val < closest_big_val)
		{
			closest_big_val = a->val;
			target = a;
		}
		a = a->next;
	}
	return (target);
}

void	get_target_b(t_nodes *a, t_nodes *b)
{
	t_nodes	*target;

	if (a == NULL || ft_list_len(a) == 0)
		return ;
	while (b)
	{
		target = find_close_big(a, b->val);
		if (target == NULL)
			b->target_node = find_smallest_val(a);
		else
			b->target_node = target;
		b = b->next;
	}
}
