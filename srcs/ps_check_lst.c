/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <sthitiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:57:53 by sthitiku          #+#    #+#             */
/*   Updated: 2022/07/15 19:40:40 by sthitiku         ###   ########.fr       */
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
		if (curr->num < min)
			return (0);
		min = curr->num;
		curr = curr->next;
	}
	return (1);
}

int	ps_check_dup(t_ps **lst)
{
	t_ps	*curr;
	int		num;

	num = (*lst)->num;
	curr = (*lst)->next;
	while (curr)
	{
		if (curr->num == num)
			return (1);
		num = curr->num;
		curr = curr->next;
	}
	return (0);
}
