/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:47:08 by sthitiku          #+#    #+#             */
/*   Updated: 2022/07/10 21:20:16 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	r_rotate_lst(t_ps **lst)
{
	t_ps	*head;
	t_ps	*curr;

	curr = *lst;
	while (curr->next)
	{
		if (!curr->next->next)
		{
			head = curr->next;
			curr->next = NULL;
			break;
		}
		curr = curr->next;
	}
	head->next = *lst;
	*lst = head;
}

static void	rotate_lst(t_ps **lst)
{
	t_ps	*head;
	t_ps	*last;
	t_ps	*curr;

	curr = *lst;
	last = *lst;
	head = (*lst)->next;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = last;
	last->next = NULL;
	*lst = head;
}

void	rotate(t_ps **a, t_ps **b)
{
	if (a && b)
	{
		rotate_lst(a);
		rotate_lst(b);
		write(1, "rr\n", 3);
	}
	else if (a)
	{
		rotate_lst(a);
		write(1, "ra\n", 3);
	}
	else if (b)
	{
		rotate_lst(b);
		write(1, "rb\n", 3);
	}
}

void	r_rotate(t_ps **a, t_ps **b)
{
	if (a && b)
	{
		r_rotate_lst(a);
		r_rotate_lst(b);
		write(1, "rrr\n", 4);
	}
	else if (a)
	{
		r_rotate_lst(a);
		write(1, "rra\n", 4);
	}
	else if (b)
	{
		r_rotate_lst(b);
		write(1, "rrb\n", 4);
	}
}