/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:47:40 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/04 13:01:04 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDES
# include "../libft/libft.h"
# include <limits.h>

// STUCTURES
typedef struct s_nodes
{
	int				val;
	int				index;
	int				cost;
	int				cheapest;
	int				above_med;
	struct s_nodes	*target_node;
	struct s_nodes	*next;
	struct s_nodes	*prev;
}	t_nodes;

typedef struct s_ope
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	total;
}	t_ope;

// PROTOTYPES
// CMD
void	sa(t_nodes **a);
void	sb(t_nodes **b);
void	ss(t_nodes **a, t_nodes **b);
void	pa(t_nodes **a, t_nodes **b);
void	pb(t_nodes **b, t_nodes **a);
void	ra(t_nodes **a);
void	rb(t_nodes **b);
void	rr(t_nodes **a, t_nodes **b);
void	rra(t_nodes **a);
void	rrb(t_nodes **b);
void	rrr(t_nodes **a, t_nodes **b);

// INPUT MANAGEMENT
char	**ft_get_args(char **argv);
void	ft_init_a(t_nodes **a, char **args);

// SORTING
void	sort_turk(t_nodes **a, t_nodes **b, int list_len);

// SORTING UTILS
void	get_index_med(t_nodes *list);
t_nodes	*find_biggest_val(t_nodes *list);
t_nodes	*find_smallest_val(t_nodes *list);
void	align_before_push(t_nodes **list, t_nodes *top_node, char name);
void	operations_count(t_nodes *a, t_nodes *b, char name);

// TARGET
void	get_target_a(t_nodes *a, t_nodes *b);
void	get_target_b(t_nodes *a, t_nodes *b);

// OPERATION
t_ope	calc_ope(t_nodes *a, t_nodes *b, t_nodes *target_a, t_nodes *target_b);
void	sort_3(t_nodes **a);

// MOVE
void	quickest_move(t_nodes *list);
t_nodes	*get_quickest_move(t_nodes *list);

// UTILS
t_nodes	*ft_stack_last(t_nodes *stack);
void	error(char *msg);
void	ft_free_tab(char **tab);
int		ft_list_len(t_nodes *stack);
int		stack_is_sorted(t_nodes *stack);

// ERRORS
void	ft_free_errors(t_nodes **a, char **args);
void	ft_clear_stack(t_nodes **stack);
int		ft_error_dup(t_nodes *a, int n);
int		ft_error_syntax(char *str);

#endif // PUSH_SWAP_H