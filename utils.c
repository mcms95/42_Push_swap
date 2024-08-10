/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucardos <nucardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:04:19 by nucardos          #+#    #+#             */
/*   Updated: 2024/08/10 14:27:22 by nucardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	number;
	int		i;
	int		flag;

	i = 0;
	number = 0;
	flag = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' )
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (flag * number);
}

void	initialize_node_variables(t_stack *new_node)
{
	new_node->index = 0;
	new_node->push_cost = 0;
	new_node->above_median = false;
	new_node->is_cheapest_move = false;
	new_node->target_node = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
}

void	print_stack(t_stack *head)
{
	t_stack	*current;

	current = head;
	if (head == NULL)
		return ;
	while (current != NULL)
	{
		ft_printf("Value is: %d\n", current->value);
		current = current->next;
	}
}
