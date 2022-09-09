/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:57:55 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/10 02:22:31 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	split_len(char **num)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (num[i])
	{
		len++;
		i++;
	}
	return (len);
}

void	ps_args_to_lst(char *str, t_ps **a)
{
	char	**num;
	int		len;
	int		i;

	num = ft_split(str, ' ');
	len = split_len(num);
	i = 0;
	while (i < len)
	{
		lst_init(a, num[i], num);
		i++;
	}
	free_split(num);
}

void	show_list(t_ps **lst)
{
	t_ps	*curr;

	curr = *lst;
	while (curr)
	{
		printf("%d\t%d\n", curr->num, curr->index);
		curr = curr->next;
	}
}

int	check_num(t_ps **lst, int median)
{
	t_ps	*curr;

	curr = *lst;
	while (curr)
	{
		if (curr->num < median)
			return (1);
		curr = curr->next;
	}
	return (0);
}
