# include "push_swap.h"

// Push a node from src to dest
void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (src == NULL || (*src) == NULL)
		return;
	
	tmp = (*src); // Set temp to src
	(*src) = (*src)->next; // Move src to next node (might be NULL)
	if (*src)
		(*src)->prev = NULL; // If src is not empty, update its prev pointer

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

