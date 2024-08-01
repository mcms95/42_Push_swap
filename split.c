/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:34:41 by nuno              #+#    #+#             */
/*   Updated: 2024/08/02 00:16:58 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str, char separator)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == separator)
			i++;
		if (str[i] != '\0')
		{
			counter++;
			while (str[i] && str[i] != separator)
			{
				i++;
			}
		}
	}
	return (counter);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*string_holder;
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (str[cursor] == separator)
		++cursor;
	while (str[cursor + len] != separator && str[cursor + len])
		++len;
	string_holder = (char *)malloc(sizeof(char) * (len + 1));
	if (string_holder == NULL)
		return (NULL);
	while (str[cursor] != separator && str[cursor])
		string_holder[i++] = str[cursor++];
	string_holder[i++] = '\0';
	return (string_holder);
}

char	**push_swap_split(char *av, char separator)
{
	int		word_count;
	char	**array;
	int		i;

	i = 1;
	word_count = count_words(av, separator);
	array = (char **)malloc(sizeof(char *) * (word_count + 2));
	if (array == NULL)
		return (NULL);
	array[0] = ft_strdup("");
	if (array[0] == NULL)
		return (NULL);
	while (word_count-- > 0)
		array[i++] = get_next_word(av, separator);
	array[i] = NULL;
	return (array);
}
