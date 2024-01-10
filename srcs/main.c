/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:00:15 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/09 09:29:16 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

long	ft_atol(const char *str)
{
	long	n;
	int		i;
	long	flag;

	n = 0;
	i = 0;
	flag = 1;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == ' ' || str[i] == '\f' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (flag * n);
}

void	ft_stack_init(t_stack_node **a, char **argv, bool flag_argc)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_check_nbrs(argv[i]))
			ft_error_free(a, argv, flag_argc);
		nbr = ft_atol(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			ft_error_free(a, argv, flag_argc);
		if (ft_check_repetition(*a, nbr))
			ft_error_free(a, argv, flag_argc);
		ft_append_node(a, nbr);
		i++;
	}
	ft_get_index(a);
	if (flag_argc)
		ft_free_matrix(argv);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_stack_init(&a, argv + 1, argc == 2);
	if (!ft_check_sorted(a))
	{
		if (ft_get_list_size(a) <= 5)
			ft_tiny_sort(&a, &b);
		else
			ft_radix_sort(&a, &b);
	}
	ft_free_stack(&a);
}
