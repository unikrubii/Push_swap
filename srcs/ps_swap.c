/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 04:56:33 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/10 02:25:00 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	swap_lst(t_ps **lst)
{
	t_ps	*head;

	head = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	head->next = *lst;
	*lst = head;
}

void	swap(t_ps **a, t_ps **b, int print)
{
	if (a && b)
	{
		swap_lst(a);
		swap_lst(b);
		if (print == 1)
			write(1, "ss\n", 3);
	}
	else if (a)
	{
		swap_lst(a);
		if (print == 1)
			write(1, "sa\n", 3);
	}
	else if (b)
	{
		swap_lst(b);
		if (print == 1)
			write(1, "sb\n", 3);
	}
}
