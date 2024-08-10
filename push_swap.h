/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucardos <nucardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:28:43 by nucardos          #+#    #+#             */
/*   Updated: 2024/08/10 16:01:24 by nucardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>

typedef struct stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				is_cheapest_move;

	// Pointers
	struct stack_node	*target_node;
	struct stack_node	*prev;
	struct stack_node	*next;
}	t_stack;

// main.c 
void	main_sort(t_stack **a, t_stack **b);

// split.c
char	**push_swap_split(char *av, char separator);
int		count_words(char *str, char separator);

// stack_init.c
void	initiate_stack(t_stack **a, char **av, bool ac_is_2_flag);
void	append_node(t_stack **head, int number);

// checker.c
int		is_digit(char *av);
int		check_duplicates(t_stack *stack, int number);
int		check_if_stack_is_sorted(t_stack *head);

// utils.c
long	ft_atol(char *str);
void	initialize_node_variables(t_stack *new_node);
void	print_stack(t_stack *head);

// free.c
void	free_array(char **av);
void	free_stack(t_stack **stack);
void	free_all(t_stack **stack, char **argv, bool ac_is_2_flag);

// push_swap.c
void	initiate_stack(t_stack	**a, char **av, bool ac_is_2_flag);

// stack_get.c
int		get_stack_len(t_stack *stack);
t_stack	*get_stack_highest_value_node(t_stack *stack);
t_stack	*get_stack_lowest_value_node(t_stack *stack);
t_stack	*get_cheapest_node(t_stack *stack);

// ---------------------- ACTIONS ----------------------
// action_swap.c
void	swap(t_stack **head);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// action_rotate.c
void	rotate(t_stack **head);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rotate_both_stacks(t_stack **main_stack,
			t_stack **target_stack, t_stack *cheapest_node);

// action_rotate_reverse.c
void	rotate_reverse(t_stack **head);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	reverse_rotate_both_stacks(t_stack **main_stack,
			t_stack **target_stack, t_stack *cheapest_node);

// action_push.c
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

// ---------------------- SORTING ----------------------
// sort_3.c
void	sort_3(t_stack **stack);

// push_swap.c
void	push_swap(t_stack **a, t_stack **b);
void	put_lowest_node_on_top(t_stack **a, t_stack *lowest_node);
void	set_current_index_and_check_median(t_stack *stack);

// setup_a_to_b.c
void	setup_a_to_b(t_stack *a, t_stack *b);
void	set_target_for_a(t_stack *a, t_stack *b);
void	set_a_push_cost(t_stack *a, t_stack *b);
void	set_a_cheapest_node(t_stack *a);

// setup_b_to_a.c
void	setup_b_to_a(t_stack *a, t_stack *b);
void	set_target_node_for_b(t_stack *a, t_stack *b);
void	set_b_push_cost(t_stack *a, t_stack *b);
void	set_b_cheapest_node(t_stack *b);

// move_stacks.c
void	move_a_to_b(t_stack **a, t_stack **b);
void	finish_a_rotation(t_stack **a, t_stack *cheapest_node);
void	move_b_to_a(t_stack **a, t_stack **b);
void	finish_b_rotation(t_stack **b, t_stack *target_node);

#endif