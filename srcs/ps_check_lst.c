/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:57:53 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/02 01:15:05 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ps_check_sort(t_ps **lst)
{
	t_ps	*curr;
	int		min;

	min = (*lst)->num;
	curr = (*lst)->next;
	while (curr)
	{
		if (curr->num <= min)
			return (0);
		min = curr->num;
		curr = curr->next;
	}
	return (1);
}

int	ps_lst_len(t_ps **lst)
{
	t_ps	*curr;
	int		len;

	len = 0;
	curr = *lst;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}

int	ps_check_dup(t_ps **lst)
{
	t_ps	*curr;
	t_ps	*tmp;
	int		num;
	int		len;

	len = ps_lst_len(lst);
	num = (*lst)->num;
	while (len >= 0)
	{
		curr = (*lst)->next;
		while (curr)
		{
			if (curr->num == num)
				return (1);
			num = curr->num;
			curr = curr->next;
		}
		len--;
	}
	return (0);
}
