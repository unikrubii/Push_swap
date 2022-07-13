/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 03:10:59 by sthitiku          #+#    #+#             */
/*   Updated: 2022/07/13 20:32:01 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_ps
{
	int			num;
	struct s_ps	*next;
}	t_ps;

// void	swap(t_ps **a, t_ps **b);
// void	rotate(t_ps **a, t_ps **b);
// void	r_rotate(t_ps **a, t_ps **b);
void	ps_addfront(t_ps **lst, t_ps *new);
void	ps_addback(t_ps **lst, t_ps *new);
void	ps_lstclear(t_list **lst);

#endif