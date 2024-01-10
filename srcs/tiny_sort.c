/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:22:36 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/09 11:53:21 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_stack_node **a)
{
	t_stack_node	*head;
	int				min;
	int				min_next;

	min = ft_min_index(a, -1);
	min_next = ft_min_index(a, min);
	head = *a;
	if (head->index == min)
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (head->index == min_next && head->next->index != min)
		ft_rra(a);
	else if (head->index == min_next && head->next->index == min)
		ft_sa(a);
	else if (head->index != min_next && head->next->index == min)
		ft_ra(a);
	else if (head->index != min && head->next->index == min_next)
	{
		ft_sa(a);
		ft_rra(a);
	}
}

void	ft_sort_four(t_stack_node **a, t_stack_node **b)
{
	int	steps;

	steps = ft_count_steps(a, ft_min_index(a, -1));
	if (steps == 1)
		ft_ra(a);
	else if (steps == 2)
	{
		ft_ra(a);
		ft_ra(a);
	}
	else if (steps == 3)
		ft_rra(a);
	if (ft_check_sorted(*a))
		return ;
	ft_pb(b, a);
	ft_sort_three(a);
	ft_pa(a, b);
}

void	ft_sort_five(t_stack_node **a, t_stack_node **b)
{
	int	steps;

	steps = ft_count_steps(a, ft_min_index(a, -1));
	if (steps == 1)
		ft_sa(a);
	if (steps == 2)
	{
		ft_ra(a);
		ft_ra(a);
	}
	if (steps == 3)
	{
		ft_rra(a);
		ft_rra(a);
	}
	if (steps == 4)
		ft_rra(a);
	ft_pb(b, a);
	ft_sort_four(a, b);
	ft_pa(a, b);
}

void	ft_tiny_sort(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = ft_get_list_size(*a);
	if (size == 2)
		ft_sa(a);
	else if (size == 3)
		ft_sort_three(a);
	else if (size == 4)
		ft_sort_four(a, b);
	else if (size == 5)
		ft_sort_five(a, b);
}
