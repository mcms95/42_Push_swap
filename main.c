/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucardos <nucardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:03:51 by nucardos          #+#    #+#             */
/*   Updated: 2024/08/10 14:12:47 by nucardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	bool	ac_is_2_flag;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = push_swap_split(av[1], ' ');
		if (!av)
			return (1);
		ac_is_2_flag = true;
	}
	initiate_stack(&a, av + 1, ac_is_2_flag);
	if (!(check_if_stack_is_sorted(a)))
	{
		push_swap(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
