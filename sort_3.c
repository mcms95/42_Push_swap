/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucardos <nucardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:04:06 by nucardos          #+#    #+#             */
/*   Updated: 2024/08/10 14:20:00 by nucardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = get_stack_highest_value_node(*a);
	if (highest_node == (*a))
		ra(a);
	if (highest_node == (*a)->next)
		ra(&(*a)->next);
	if (!check_if_stack_is_sorted(*a))
		sa(a);
}
