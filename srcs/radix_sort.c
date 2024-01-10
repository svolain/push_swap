/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:32:57 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/09 13:43:26 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_radix_sort(t_stack_node **a, t_stack_node **b)
{
	int				i;
	int				size;

	i = 0;
	while ((!ft_check_sorted(*a)) || *b != NULL)
	{
		size = ft_get_list_size(*a);
		while (0 < size-- && (!ft_check_sorted(*a)))
		{
			if ((((*a)->index >> i) & 1) == 0)
				ft_pb(b, a);
			else
				ft_ra(a);
		}
		i++;
		size = ft_get_list_size(*b);
		while (0 < size--)
		{
			if ((((*b)->index >> i) & 1) == 0 && (!ft_check_sorted(*a)))
				ft_rb(b);
			else
				ft_pa(a, b);
		}
	}
}
