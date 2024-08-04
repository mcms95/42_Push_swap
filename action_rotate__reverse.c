# include "push_swap.h"

// Rotate last node to the beggining
void	rotate_reverse(t_stack **head)
{
	t_stack	*first_node;
	t_stack	*current;

	if(*head == NULL || (*head)->next == NULL)
		return;
	// Node set to head
	first_node = (*head);
	current = (*head);

	// Iterate through linked list till point to last but one node
	while (current->next->next != NULL)
		current = current->next;
	current->next->next = first_node; // Set last node next to first node
	(*head) = current->next; // Head point to last node, that now is first
	(*head)->prev = NULL; // New head prev point to NULL
	(*head)->next = first_node; // Set new head's next to the previous first node
	first_node->prev = *head; // Set previous first node's prev to new head
	current->next = NULL; // Tail points to NULL
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