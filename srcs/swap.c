/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:02:55 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/09 11:45:58 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_list_size(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	ft_swap(t_stack_node **stack)
{
	t_stack_node	*node;
	t_stack_node	*next;
	int				tmp_nbr;
	int				tmp_index;

	node = (*stack);
	next = node->next;
	if (!node && !next)
		return ;
	tmp_nbr = node->nbr;
	tmp_index = node->index;
	node->nbr = next->nbr;
	node->index = next->index;
	next->nbr = tmp_nbr;
	next->index = tmp_index;
}

void	ft_sa(t_stack_node **stack_a)
{
	if (ft_get_list_size(*stack_a) < 2)
		return ;
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack_node **stack_b)
{
	if (ft_get_list_size(*stack_b) < 2)
		return ;
	ft_swap (stack_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (ft_get_list_size(*stack_a) < 2 || ft_get_list_size(*stack_b) < 2)
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
