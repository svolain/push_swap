/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:27:43 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/09 09:19:05 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv - 1);
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*node;

	if (stack == NULL)
		return ;
	node = *stack;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack = NULL;
}

void	ft_error_free(t_stack_node **a, char **argv, bool flag_argc)
{
	ft_free_stack(a);
	if (flag_argc)
		ft_free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_check_nbrs(char *str)
{
	if (!(*str == '+'
			|| *str == '-'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+'
			|| *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	ft_check_repetition(t_stack_node *a, int value)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->nbr == value)
			return (1);
		a = a->next;
	}
	return (0);
}
