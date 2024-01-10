/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:16:13 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/09 09:33:48 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(t_stack_node **stack_to, t_stack_node **stack_from)
{
	t_stack_node	*head_to;
	t_stack_node	*head_from;
	t_stack_node	*tmp;

	head_to = *stack_to;
	head_from = *stack_from;
	tmp = *stack_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
}

void	ft_pa(t_stack_node **a, t_stack_node **b)
{
	if (ft_get_list_size(*b) == 0)
		return ;
	ft_push(a, b);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack_node **b, t_stack_node **a)
{
	if (ft_get_list_size(*a) == 0)
		return ;
	ft_push(b, a);
	write(1, "pb\n", 3);
}
