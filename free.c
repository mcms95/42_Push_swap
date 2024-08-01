# include "push_swap.h"


void free_array(char **av)
{
	int i = 0;
	if (av == NULL)
		return;
	while(av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
