/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:47:40 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/04 09:56:25 by eschwart         ###   ########.fr       */
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

// typedef struct s_cost
// {
// 	int	index;
// 	int	cost_a;
// 	int	cost_b;
// 	int	total_cost;
// }	t_cost;

// PROTOTYPES

//		ERRORS
void	ft_free_errors(t_nodes **a, char **args);
void	ft_clear_stack(t_nodes **stack);
int		ft_error_dup(t_nodes *a, int n);
int		ft_error_syntax(char *str);

//		STACK
void	ft_init_a(t_nodes **a, char **args);
void	init_nodes_a(t_nodes *a, t_nodes *b);
void	ft_init_b(t_nodes *a, t_nodes *b);
int		stack_is_sorted(t_nodes *stack);
void	prep_for_push(t_nodes **stack, t_nodes *top_node, char stack_name);
//void	move_a_to_b(t_nodes **a, t_nodes **b);
//void	move_b_to_a(t_nodes **a, t_nodes **b);
//void	min_on_top(t_nodes **a);
int		ft_list_len(t_nodes *stack);
int		find_small(t_nodes *stack);
void	init_nodes_a(t_nodes *a, t_nodes *b);
void	set_cheap(t_nodes *stack);
void	current_index(t_nodes *stack);
t_nodes	*find_min(t_nodes *stack);
t_nodes	*ft_stack_last(t_nodes *stack);
t_nodes	*get_cheap(t_nodes *stack);
t_nodes	*find_biggest(t_nodes *a);
t_nodes	*ft_find_last(t_nodes *stack);

//		UTILS
void	error(char *msg);
void	ft_free_tab(char **tab);
char	**ft_get_args(char **argv);

//		ALGO
void	sort_3(t_nodes **a);

void	ft_push_swap(t_nodes **a, t_nodes **b, int list_len);
int		*sorted_array(t_nodes *stack, int size);

//		CMD
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
void	rotate_both(t_nodes **a, t_nodes **b, t_nodes *cheap);
void	rev_rotate_both(t_nodes **a, t_nodes **b, t_nodes *cheap);


// 		SORTING
void	sort_turk(t_nodes **a, t_nodes **b, int list_len);


// 		SORTING UTILS
void	get_index_med(t_nodes *list);
t_nodes	*find_biggest_val(t_nodes *list);
t_nodes	*find_smallest_val(t_nodes *list);
void	align_before_push(t_nodes **list, t_nodes *top_node, char name);
void	operations_count(t_nodes *a, t_nodes *b, char name);

//		TARGET
void	get_target_a(t_nodes *a, t_nodes *b);
void	get_target_b(t_nodes *a, t_nodes *b);

//		OPERATION
t_ope 	calc_ope(t_nodes *a, t_nodes *b, t_nodes *target_a, t_nodes *target_b);

//		MOVE
void	quickest_move(t_nodes *list);
t_nodes	*get_quickest_move(t_nodes *list);


#endif // PUSH_SWAP_H