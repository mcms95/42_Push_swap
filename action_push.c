/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucardos <nucardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:02:43 by nucardos          #+#    #+#             */
/*   Updated: 2024/08/10 14:05:21 by nucardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (src == NULL || (*src) == NULL)
		return ;
	tmp = (*src);
	(*src) = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = (*dest);
	tmp->prev = NULL;
	if ((*dest))
		(*dest)->prev = tmp;
	(*dest) = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_printf("pb\n");
}
