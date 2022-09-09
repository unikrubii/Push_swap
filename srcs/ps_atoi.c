/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 02:44:32 by sthitiku          #+#    #+#             */
/*   Updated: 2022/02/18 22:55:52 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static void	free_remain(t_ps **lst, char **split, t_ps *new)
{
	free_split(split);
	ps_lstclear(lst);
	free(new);
	write(2, "Error\n", 6);
	exit(CONV_ERR);
}

int	ps_atoi(const char *str, t_ps **lst, char **split, t_ps *new)
{
	long	minus;
	long	result;

	minus = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	result *= minus;
	if (*str != '\0' || result < -2147483648 || result > 2147483647)
		free_remain(lst, split, new);
	return (result);
}

void	ps_pushback(t_ps **b, t_ps **a)
{
	int	max;

	while (!ps_check_sort(a) || ps_lst_len(b) > 0)
	{
		max = find_highest(b);
		ps_btoa(b, a, max);
	}
}
