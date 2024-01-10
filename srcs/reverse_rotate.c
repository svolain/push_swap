/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:16:54 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/09 10:34:31 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*last;
	t_stack_node	*second_last;

	head = *stack;
	last = *stack;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	head = last;
	head->next = *stack;
	second_last->next = NULL;
	*stack = head;
}

void	ft_rra(t_stack_node **a)
{
	if (ft_get_list_size(*a) < 2)
		return ;
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack_node **b)
{
	if (ft_get_list_size(*b) < 2)
		return ;
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack_node **a, t_stack_node **b)
{
	if (ft_get_list_size(*a) < 2 || ft_get_list_size(*b))
		return ;
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
