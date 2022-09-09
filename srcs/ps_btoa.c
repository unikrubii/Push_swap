/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:49:05 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/10 02:20:20 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	max_pos(t_ps **lst, int max)
{
	t_ps	*curr;
	int		pos;

	pos = 0;
	curr = *lst;
	while (curr)
	{
		if (curr->index == max)
			break ;
		pos++;
		curr = curr->next;
	}
	return (pos);
}

int	last_index(t_ps **lst)
{
	t_ps	*curr;
	int		last;

	curr = *lst;
	while (curr->next)
	{
		curr = curr->next;
	}
	last = curr->index;
	return (last);
}

int	find_highest(t_ps **lst)
{
	t_ps	*curr;
	int		max;

	max = (*lst)->index;
	curr = (*lst)->next;
	while (curr)
	{
		if (curr->index > max)
			max = curr->index;
		curr = curr->next;
	}
	return (max);
}

void	ps_btoa2(t_ps **b, t_ps **a, int max)
{
	if ((*b)->index == max - 2)
	{
		push(b, a, 'a', 1);
		rotate(a, NULL, 1);
	}
	else if ((*b)->next->index == max)
		swap(NULL, b, 1);
	else if (max_pos(b, max) <= ps_lst_len(b) / 2)
		rotate(NULL, b, 1);
	else
		r_rotate(NULL, b, 1);
}

void	ps_btoa(t_ps **b, t_ps **a, int max)
{
	if ((*b)->index == max)
	{
		push(b, a, 'a', 1);
		if (!ps_check_sort(a))
		{
			if ((*a)->next->index == max - 1)
				swap(a, NULL, 1);
			if (last_index(a) == max - 2)
				r_rotate(a, NULL, 1);
		}
	}
	else if ((*b)->index == max - 1)
	{
		push(b, a, 'a', 1);
		if (!ps_check_sort(a) && (*a)->next->index == (*a)->index + 1)
			swap(a, NULL, 1);
	}
	else
		ps_btoa2(b, a, max);
}
