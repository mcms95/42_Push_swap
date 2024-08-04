# include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*third_node;

	if(*head == NULL || (*head)->next == NULL)
		return;
	
	// Setup
	first_node = (*head);
	second_node = (*head)->next;
	third_node = (*head)->next->next;

	// Point second node to head
	*head = second_node;

	// Setup previous first node to be second node
	first_node->next = third_node;
	first_node->prev = second_node;

	// Setup previous second node to be first node
	second_node->next = first_node;
	second_node->prev = NULL;

	// Check if there is third node
	if (third_node)
		third_node->prev = first_node;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}