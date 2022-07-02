/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <sthitiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 04:56:33 by sthitiku          #+#    #+#             */
/*   Updated: 2022/07/02 05:03:46 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_lst(t_ps **lst)
{
	t_ps	*head;

	head = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	head->next = *lst;
	*lst = head;
}

void	swap(t_ps **a, t_ps **b)
{
	if (a && b)
	{
		swap_lst(a);
		swap_lst(b);
		write(1, "ss\n", 3);
	}
	else if (a)
	{
		swap_lst(a);
		write(1, "sa\n", 3);
	}
	else if (b)
	{
		swap_lst(b);
		write(1, "sb\n", 3);
	}
}