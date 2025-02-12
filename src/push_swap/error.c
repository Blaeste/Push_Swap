/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:42:30 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/10 13:00:52 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	ft_error_dup(t_nodes *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->val == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_clear_stack(t_nodes **stack)
{
	t_nodes	*temp;
	t_nodes	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->val = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	ft_free_errors(t_nodes **a, char **args)
{
	ft_clear_stack(a);
	write(2, "Error\n", 6);
	ft_free_tab(args);
	exit (1);
}
