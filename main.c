/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:53:08 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/04 12:51:04 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	sort_3(t_nodes **a)
{
	t_nodes	*biggest;

	biggest = find_biggest_val(*a);
	if (biggest == *a)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->val > (*a)->next->val)
		sa(a);
}

static void	push_swap(t_nodes **a, t_nodes **b, int list_len)
{
	if (!stack_is_sorted(*a))
	{
		if (list_len == 2)
			sa(a);
		else if (list_len == 3)
			sort_3(a);
		else
			sort_turk(a, b, list_len);
	}
}

int	main(int argc, char **argv)
{
	t_nodes	*a;
	t_nodes	*b;
	char	**args;
	int		list_len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	args = ft_get_args(argv);
	ft_init_a(&a, args);
	list_len = ft_list_len(a);
	push_swap(&a, &b, list_len);
	ft_free_tab(args);
	ft_clear_stack(&a);
	ft_clear_stack(&b);
	return (0);
}
