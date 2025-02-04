/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:20:13 by eschwart          #+#    #+#             */
/*   Updated: 2025/01/23 10:34:50 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push(t_nodes **dest, t_nodes **src)
{
	t_nodes	*node_pushed;

	if (!*src)
		return ;
	node_pushed = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_pushed->prev = NULL;
	if (!*dest)
	{
		*dest = node_pushed;
		node_pushed->next = NULL;
	}
	else
	{
		node_pushed->next = *dest;
		(*dest)->prev = node_pushed;
		*dest = node_pushed;
	}
}

void	pa(t_nodes **a, t_nodes **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_nodes **b, t_nodes **a)
{
	push(b, a);
	ft_printf("pb\n");
}
