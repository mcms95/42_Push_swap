/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucardos <nucardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:04:24 by nucardos          #+#    #+#             */
/*   Updated: 2024/08/10 15:31:32 by nucardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **av)
{
	int	i;

	i = -1;
	if (NULL == av || NULL == *av)
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	if (current->next == NULL)
	{
		free(current);
		return ;
	}
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	free_all(t_stack **stack, char **av, bool ac_is_2_flag)
{
	free_stack(stack);
	if (ac_is_2_flag)
		free_array(av);
	write(2, "Error\n", 6);
	exit(1);
}
