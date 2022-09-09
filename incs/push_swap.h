/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <sthitiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 03:10:59 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/10 04:10:50 by sthitiku         ###   ########.fr       */
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
# define INPUT_ERR 4

typedef struct s_ps
{
	int			num;
	int			index;
	struct s_ps	*next;
}	t_ps;

void	push_swap(t_ps **a, t_ps **b);
void	ps_addfront(t_ps **lst, t_ps *new);
void	ps_addback(t_ps **lst, t_ps *new);
void	ps_lstclear(t_ps **lst);
void	lst_init(t_ps **a, char *num, char **split);
void	ps_args_to_lst(char *str, t_ps **a);
int		ps_check_sort(t_ps **lst);
int		ps_check_dup(t_ps **lst);
int		ps_lst_len(t_ps **lst);
int		ps_find_median(t_ps **lst);
int		ps_atoi(const char *str, t_ps **lst, char **split, t_ps *new);
void	ps_error(t_ps **lst, int sorted, int code);
void	ps_pushback(t_ps **b, t_ps **a);
void	ps_put_index(t_ps **lst);

void	push(t_ps **from, t_ps **to, char dest, int print);
void	rotate(t_ps **a, t_ps **b, int print);
void	r_rotate(t_ps **a, t_ps **b, int print);
void	swap(t_ps **a, t_ps **b, int print);
void	quicksort(int *num, int first, int last);
int		*lst_to_arr(t_ps **lst);

int		find_highest(t_ps **lst);
void	free_split(char **to_free);
void	ps_btoa(t_ps **b, t_ps **a, int max);
int		lowest_index(t_ps **lst);

void	show_list(t_ps **lst);
int		check_inst(t_ps **a, t_ps **b, char *inst);

#endif