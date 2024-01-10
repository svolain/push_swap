/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:57:54 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/09 11:38:32 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_check_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*ft_get_last_node(t_stack_node *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	ft_append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->nbr = nbr;
	node->index = -1;
	if (*stack == NULL)
		*stack = node;
	else
	{
		last_node = ft_get_last_node(*stack);
		last_node->next = node;
	}
}

t_stack_node	*ft_get_min(t_stack_node **stack)
{
	t_stack_node	*node;
	t_stack_node	*min;
	int				flag;

	node = *stack;
	min = NULL;
	flag = 0;
	if (node)
	{
		while (node)
		{
			if ((node->index == -1) && (!flag || node->nbr < min->nbr))
			{
				min = node;
				flag = 1;
			}
			node = node->next;
		}
	}
	return (min);
}

void	ft_get_index(t_stack_node **stack)
{
	t_stack_node	*node;
	int				index;

	index = 0;
	node = ft_get_min(stack);
	while (node)
	{
		node->index = index++;
		node = ft_get_min(stack);
	}
}
