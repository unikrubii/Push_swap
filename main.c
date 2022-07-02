/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <sthitiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 03:06:07 by sthitiku          #+#    #+#             */
/*   Updated: 2022/07/02 11:00:39 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	*a;
	t_ps	*tmp;
	int		i;

	a = malloc(sizeof(t_ps));
	a->num = 0;
	a->next = NULL;
	tmp = a;
	i = 1;
	while(i <= 5)
	{
		tmp->next = malloc(sizeof(t_ps));
		tmp->next->num = i;
		tmp = tmp->next;
		i++;
	}
	// swap(&a, NULL);
	r_rotate(&a, NULL);
	tmp = a;
	while (tmp)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
	while(a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
