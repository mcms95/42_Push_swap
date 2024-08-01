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
	int		current_position;
	int		final_index;
	int		push_price;
	bool	above_mediam;
	bool	cheapest;

	// Pointers
	struct stack_node *target;
	struct stack_node *prev;
	struct stack_node *next;
}			Node;

// checker.c
void	check_if_arguments_are_numbers(int ac, char **av);
int		is_digit(char *av);

// free.c
void free_array(char **av);

// split.c
char	**split(char *av, char separator);
static char	*get_next_word(char *str, char separator);
int	count_words(char *str, char separator);



#endif