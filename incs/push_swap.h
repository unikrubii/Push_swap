/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 03:10:59 by sthitiku          #+#    #+#             */
/*   Updated: 2022/08/31 05:01:51 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define MALLOC_ERR 1
# define CONV_ERR 2
# define DUP_SORT 3

typedef struct s_ps
{
	int			num;
	int			index;
	struct s_ps	*next;
}	t_ps;

void	ps_addfront(t_ps **lst, t_ps *new);
void	ps_addback(t_ps **lst, t_ps *new);
void	ps_lstclear(t_ps **lst);
int		ps_check_sort(t_ps **lst);
int		ps_check_dup(t_ps **lst);
int		ps_lst_len(t_ps **lst);
int		ps_find_median(t_ps **lst);
void	ps_error(t_ps **lst, int sorted);
void	ps_pushback(t_ps **b, t_ps **a);
void	ps_put_index(t_ps **lst);

void	push(t_ps **from, t_ps **to, char dest);
void	rotate(t_ps **a, t_ps **b);
void	r_rotate(t_ps **a, t_ps **b);
void	swap(t_ps **a, t_ps **b);

int		find_highest(t_ps **lst);

void	show_list(t_ps **lst);

#endif