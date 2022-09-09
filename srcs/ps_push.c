/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:30:04 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/09 13:56:15 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	push_lst(t_ps **from, t_ps **to)
{
	t_ps	*to_push;
	t_ps	*head;

	to_push = *from;
	head = (*from)->next;
	*from = head;
	head = *to;
	to_push->next = head;
	*to = to_push;
}

void	push(t_ps **from, t_ps **to, char dest, int print)
{
	if (dest == 'a')
	{
		push_lst(from, to);
		if (print == 1)
			write(1, "pa\n", 3);
	}
	else
	{
		push_lst(from, to);
		if (print == 1)
			write(1, "pb\n", 3);
	}
}
