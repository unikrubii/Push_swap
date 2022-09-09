/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:14:40 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/10 02:26:26 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	push_3(t_ps **lst)
{
	int	max;

	max = find_highest(lst);
	if ((*lst)->index == max)
	{
		rotate(lst, NULL, 1);
		if (!ps_check_sort(lst))
			swap(lst, NULL, 1);
	}
	else if ((*lst)->index == max - 1)
	{
		if ((*lst)->next->index == max - 2)
			swap(lst, NULL, 1);
		else
			r_rotate(lst, NULL, 1);
	}
	else
	{
		rotate(lst, NULL, 1);
		swap(lst, NULL, 1);
		r_rotate(lst, NULL, 1);
	}
}

static void	push_5_2(t_ps **from, t_ps **to, int len)
{
	if ((*from)->index <= 2)
	{
		if (ps_check_sort(from))
			push(to, from, 'a', 1);
		else
			push(from, to, 'b', 1);
	}
	else
	{
		if (lowest_index(from) <= len / 2)
			rotate(from, NULL, 1);
		else
			r_rotate(from, NULL, 1);
	}
	if (!ps_check_sort(from))
		len = ps_lst_len(from);
}

void	push_5(t_ps **from, t_ps **to, int len)
{
	if (ps_check_sort(from) && ps_lst_len(to) == 0)
		return ;
	if (!ps_check_sort(from) && ps_lst_len(to) == 0 && \
			(*from)->next->next->index == 3 && \
			(*from)->next->next->next->index == 4 && \
			(*from)->next->next->next->next->index == 5)
	{
		swap(from, NULL, 1);
		return ;
	}
	if (ps_lst_len(from) == 3 && !ps_check_sort(from))
	{
		push_3(from);
		if ((*to)->index != 2)
			swap(NULL, from, 1);
		push(to, from, 'a', 1);
		push(to, from, 'a', 1);
		return ;
	}
	push_5_2(from, to, len);
	push_5(from, to, len);
}

void	push_intv(t_ps **from, t_ps **to, int counter, int intv)
{
	static int	i = 0;

	if (ps_lst_len(from) < 3)
		return ;
	if ((*from)->index <= counter && (*from)->index < find_highest(from) - 1)
	{
		push(from, to, 'b', 1);
		i++;
	}
	else
		rotate(from, NULL, 1);
	if (i == intv)
	{
		i = 0;
		counter += intv;
	}
	push_intv(from, to, counter, intv);
}

void	push_swap(t_ps **a, t_ps **b)
{
	int	intv;

	intv = 0;
	if (ps_lst_len(a) == 3)
		push_3(a);
	else if (ps_lst_len(a) == 5)
		push_5(a, b, ps_lst_len(a));
	else
	{
		if (ps_lst_len(a) >= 500)
			intv = ps_lst_len(a) / 11;
		else
			intv = ps_lst_len(a) / 4;
		push_intv(a, b, intv, intv);
		if (!ps_check_sort(a))
			swap(a, NULL, 1);
		ps_pushback(b, a);
	}
}
