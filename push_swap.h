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
	int		value;
	int		index;
	int		push_cost;
	bool	above_median;
	bool	is_cheapest_move;

	// Pointers
	struct stack_node *target_node;
	struct stack_node *prev;
	struct stack_node *next;
}			t_stack;

// checker.c
int		is_digit(char *av);
int		check_duplicates(t_stack *stack, int number);
int		check_if_stack_is_sorted(t_stack *head);

// free.c
void	free_array(char **av);
void	free_stack(t_stack **stack);
void	free_all(t_stack **stack, char **argv, bool ac_is_2_flag);

// split.c
char	**push_swap_split(char *av, char separator);
int		count_words(char *str, char separator);

// push_swap.c
void	initiate_stack(t_stack	**a, char **av, bool ac_is_2_flag);

// utils.c
long	ft_atol(char *str);
void	append_node(t_stack **head, int number);
void	initialize_node_variables(t_stack *new_node);
void	print_stack(t_stack *head);

// stack_get.c
int		get_stack_len(t_stack *stack);
t_stack	*get_stack_highest_value_node(t_stack *stack);
t_stack	*get_stack_lowest_value_node(t_stack *stack);


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

// action_rotate_reverse.c
void	rotate_reverse(t_stack **head);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// action_push.c
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

// sort_3.c
void	sort_3(t_stack **stack);

// initiate_nodes_for_swap.c
void	initiate_nodes(t_stack *a, t_stack *b);
void	set_current_index_and_check_median(t_stack *stack);
void	set_target_node(t_stack *a, t_stack *b);
void	set_push_cost(t_stack *a, t_stack *b);
void	set_cheapest_node(t_stack *b);

#endif