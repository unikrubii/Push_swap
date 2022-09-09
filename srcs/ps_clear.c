/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:21:44 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/10 02:22:48 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	free_split(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

void	ps_error(t_ps **lst, int sorted, int code)
{
	if (sorted == 0)
	{
		write(2, "Error\n", 6);
		ps_lstclear(lst);
		exit(code);
	}
	else
	{
		ps_lstclear(lst);
		exit(code);
	}
}
