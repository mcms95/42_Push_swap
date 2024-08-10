# include "push_swap.h"

void rotate(t_stack **head)
{
	t_stack	*first_node;
	t_stack	*current;

	if(*head == NULL || (*head)->next == NULL)
		return;
	first_node = (*head);
	current = (*head);
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	while (current->next != NULL)
		current = current->next;
	first_node->prev = current;
	current->next = first_node;
	first_node->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	rotate_both_stacks(t_stack **main_stack, t_stack **target_stack, t_stack *cheapest_node)
{
	while(*target_stack != cheapest_node->target_node && *main_stack != cheapest_node)
		rr(main_stack, target_stack);
	set_current_index_and_check_median(*main_stack);
	set_current_index_and_check_median(*target_stack);
}