/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:17:13 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/09 10:37:04 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*last;

	if (ft_get_list_size(*stack) < 2)
		return ;
	head = *stack;
	last = ft_get_last_node(head);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
}

void	ft_ra(t_stack_node **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack_node **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack_node **a, t_stack_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
