# include "push_swap.h"

void rotate_reverse(t_stack **head)
{
	t_stack *first_node;
	t_stack *current;

	if (*head == NULL || (*head)->next == NULL)
		return;
	first_node = (*head);
	current = (*head);
	while (current->next->next != NULL)
		current = current->next;
	current->next->next = first_node;
	(*head) = current->next;
	(*head)->prev = NULL;
	(*head)->next = first_node;
	first_node->prev = *head;
	current->next = NULL;
}

void	rra(t_stack **a)
{
	rotate_reverse(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	rotate_reverse(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rotate_reverse(a);
	rotate_reverse(b);
	ft_printf("rrr\n");
}

void	reverse_rotate_both_stacks(t_stack **main_stack, t_stack **target_stack, t_stack *cheapest_node)
{
	while(*target_stack != cheapest_node->target_node && *main_stack != cheapest_node)
		rrr(main_stack, target_stack);
	set_current_index_and_check_median(*main_stack);
	set_current_index_and_check_median(*target_stack);
}