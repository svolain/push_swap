/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:58:20 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/09 08:18:39 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_arrsize(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

static	void	ft_free(char **arr, int k)
{
	while (k >= 0)
	{
		free(arr[k]);
		k--;
	}
	free(arr);
}

static int	ft_get_lenght(const char *s, int i, char c)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static int	ft_fillarr(char **arr, const char *s, char c, int k)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			j = ft_get_lenght(s, i, c);
			arr[k] = ft_substr(s, i, j);
			if (arr[k] == 0)
			{
				ft_free(arr, k);
				return (-1);
			}
			k++;
			i += j;
		}
		else
			i ++;
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		k;
	char	*zero;

	if (!s)
		return (0);
	arr = (char **)malloc(sizeof(char *) * (ft_arrsize(s, c) + 2));
	if (arr == 0)
		return (0);
	zero = (char *)malloc(sizeof(char));
	if (zero == 0)
		return (0);
	zero[0] = '\0';
	arr[0] = zero;
	k = 1;
	k = ft_fillarr(arr, s, c, k);
	if (k == -1)
		return (0);
	else
		arr[k] = 0;
	return (arr);
}
