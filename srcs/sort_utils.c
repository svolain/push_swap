/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:27:33 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/09 11:01:41 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_steps(t_stack_node **stack, int index)
{
	t_stack_node	*head;
	int				i;

	i = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		i++;
		head = head->next;
	}
	return (i);
}

int	ft_min_index(t_stack_node **stack, int val)
{
	t_stack_node	*head;
	int				min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}
