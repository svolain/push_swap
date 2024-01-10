/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:25:57 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/09 09:02:50 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	struct s_stack_node	*next;
}	t_stack_node;

void			ft_free_matrix(char **argv);
void			ft_free_stack(t_stack_node **stack);
void			ft_error_free(t_stack_node **a, char **argv, bool flag_argc);
int				ft_check_nbrs(char *str);
int				ft_check_repetition(t_stack_node *a, int nbr);
bool			ft_check_sorted(t_stack_node *stack);
t_stack_node	*ft_get_last_node(t_stack_node *head);
void			ft_append_node(t_stack_node **stack, int nbr);
t_stack_node	*ft_get_min(t_stack_node **stack);
void			ft_get_index(t_stack_node **stack);
int				ft_get_list_size(t_stack_node *stack);
void			ft_swap(t_stack_node **stack);
void			ft_sa(t_stack_node **stack_a);
void			ft_sb(t_stack_node **stack_b);
void			ft_ss(t_stack_node **stack_a, t_stack_node **stack_b);
void			ft_push(t_stack_node **stack_to, t_stack_node **stack_from);
void			ft_pa(t_stack_node **a, t_stack_node **b);
void			ft_pb(t_stack_node **b, t_stack_node **a);
void			ft_rotate(t_stack_node **stack);
void			ft_ra(t_stack_node **a);
void			ft_rb(t_stack_node **b);
void			ft_rr(t_stack_node **a, t_stack_node **b);
void			ft_reverse_rotate(t_stack_node **stack);
void			ft_rra(t_stack_node **a);
void			ft_rrb(t_stack_node **b);
void			ft_rrr(t_stack_node **a, t_stack_node **b);
void			ft_tiny_sort(t_stack_node **a, t_stack_node **b);
void			ft_radix_sort(t_stack_node **a, t_stack_node **b);
int				ft_min_index(t_stack_node **stack, int val);
void			ft_sort_three(t_stack_node **a);
int				ft_count_steps(t_stack_node **stack, int index);
void			ft_sort_four(t_stack_node **a, t_stack_node **b);
void			ft_sort_five(t_stack_node **a, t_stack_node **b);
void			ft_radix_sort(t_stack_node **a, t_stack_node **b);
int				ft_get_max(t_stack_node **stack);

#endif
