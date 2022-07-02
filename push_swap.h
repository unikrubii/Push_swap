/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <sthitiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 03:10:59 by sthitiku          #+#    #+#             */
/*   Updated: 2022/07/02 11:24:56 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define SA "sa\n"
# define SB "sb\n"
# define RA "ra\n"
# define RB "rb\n"

typedef struct s_ps
{
	int			num;
	struct s_ps	*next;
}	t_ps;

void	swap(t_ps **a, t_ps **b);
void	rotate(t_ps **a, t_ps **b);
void	r_rotate(t_ps **a, t_ps **b);

#endif