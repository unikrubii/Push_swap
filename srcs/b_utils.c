/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 02:11:28 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/10 03:13:55 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	check_inst4(t_ps **a, t_ps **b, char *inst)
{
	if (ft_strlen(inst) == 4 && !ft_strncmp(inst, "rrb", 3) && \
			ps_lst_len(b) > 0)
	{
		if (ps_lst_len(b) > 1)
			r_rotate(NULL, b, 0);
	}
	else if (ft_strlen(inst) == 4 && !ft_strncmp(inst, "rrr", 3) && \
			ps_lst_len(b) > 0 && ps_lst_len(a) > 0)
	{
		if (ps_lst_len(a) > 1)
			r_rotate(a, NULL, 0);
		if (ps_lst_len(b) > 1)
			r_rotate(NULL, b, 0);
	}
	else if (ft_strlen(inst) == 3 && !ft_strncmp(inst, "rr", 2) && \
			ps_lst_len(b) > 0 && ps_lst_len(a) > 0)
	{
		if (ps_lst_len(a) > 1)
			rotate(a, NULL, 0);
		if (ps_lst_len(b) > 1)
			rotate(NULL, b, 0);
	}
	else
		return (0);
	return (1);
}

int	check_inst3(t_ps **a, t_ps **b, char *inst)
{
	if (ft_strlen(inst) == 3 && !ft_strncmp(inst, "ra", 2) && \
			ps_lst_len(a) > 0)
	{
		if (ps_lst_len(a) > 1)
			rotate(a, NULL, 0);
	}
	else if (ft_strlen(inst) == 3 && !ft_strncmp(inst, "rb", 2) && \
			ps_lst_len(b) > 0)
	{
		if (ps_lst_len(b) > 1)
			rotate(NULL, b, 0);
	}
	else if (ft_strlen(inst) == 4 && !ft_strncmp(inst, "rra", 3) && \
			ps_lst_len(a) > 0)
	{	
		if (ps_lst_len(a) > 1)
			r_rotate(a, NULL, 0);
	}
	else
		return (check_inst4(a, b, inst));
	return (1);
}

int	check_inst2(t_ps **a, t_ps **b, char *inst)
{
	if (ft_strlen(inst) == 3 && !ft_strncmp(inst, "ss", 2) && \
			ps_lst_len(b) > 0 && ps_lst_len(a) > 0)
	{
		if (ps_lst_len(b) > 1)
			swap(NULL, b, 0);
		if (ps_lst_len(a) > 1)
			swap(a, NULL, 0);
	}
	else if (ft_strlen(inst) == 3 && !ft_strncmp(inst, "pa", 2) && \
			ps_lst_len(b) > 0)
		push(b, a, 'a', 0);
	else if (ft_strlen(inst) == 3 && !ft_strncmp(inst, "pb", 2) && \
			ps_lst_len(a) > 0)
		push(a, b, 'b', 0);
	else
		return (check_inst3(a, b, inst));
	return (1);
}

int	check_inst(t_ps **a, t_ps **b, char *inst)
{
	if (ft_strlen(inst) == 3 && !ft_strncmp(inst, "sa", 2) && \
			ps_lst_len(a) > 0)
	{
		if (ps_lst_len(a) > 1)
			swap(a, NULL, 0);
	}
	else if (ft_strlen(inst) == 3 && !ft_strncmp(inst, "sb", 2) && \
			ps_lst_len(b) > 0)
	{
		if (ps_lst_len(b) > 1)
			swap(NULL, b, 0);
	}
	else
		return (check_inst2(a, b, inst));
	return (1);
}
