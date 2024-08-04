# include "push_swap.h"

// Push a node from src to dest
void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (src == NULL || (*src) == NULL)
		return;
	
	// Store the top node of the source stack
	tmp = (*src);

	// Update source stack's head to the next node (might be NULL if src had only one node)
	(*src) = (*src)->next;

	// If source stack is not empty after removal, update its new top node's prev pointer
	if (*src)
		(*src)->prev = NULL;

	// Connect the moved node to the top of the destination stack
	tmp->next = (*dest);
	tmp->prev = NULL;

	// If destination stack was not empty, update its old top node's prev pointer
	if ((*dest))
		(*dest)->prev = tmp;

	// Set the moved node as the new top of the destination stack
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

