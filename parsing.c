/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:30:00 by dbiletsk          #+#    #+#             */
/*   Updated: 2026/02/05 22:00:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swamp.h"

int	parse_input(long **buffer, int argc, char **argv)
{
	int		i;
	char	**temp;
	int		len;

	len = 0;
	i = -1;
	if (argc > 2)
	{
		temp = ft_calloc(argc, sizeof(char *));
		temp[argc - 1] = NULL;
		while (++i < argc - 1)
			temp[i] = ft_strdup(argv[1 + i]);
		i = -1;
	}
	else
		temp = ft_split(argv[1], ' ');
	while (temp[++i] != NULL)
		len++;
	*buffer = ft_calloc(len, sizeof(long));
	i = -1;
	while (++i < len)
		*(*buffer + i) = ft_atol(temp[i]);
	while (i != -1)
		free(temp[i--]);
	return (free(temp), len);
}

int	is_input_valid(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		if (!is_all_digits(argv[1]))
			return (ft_printf("Error\n"), 0);
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			if (!is_all_digits(argv[i++]))
				return (ft_printf("Error\n"), 0);
		}
	}
	return (1);
}

int	is_stack_valid(long *stack, int len)
{
	long	*uniq;
	int		i;

	if (len == 1)
		return (0);
	if (!is_array_in_int_range(stack, len))
		return (0);
	uniq = ft_calloc(len, sizeof(long));
	i = -1;
	while (++i < len)
	{
		if (!is_number_in(uniq, len, stack[i]))
			uniq[i] = stack[i];
	}
	if (!are_arrays_equal(stack, uniq, len))
		return (free(uniq), 0);
	return (free(uniq), 1);
}

void	populate_stack_a(long *stack, long len, t_list **stack_a)
{
	long	*sorted_stack;
	int		i;
	t_item	*temp;

	sorted_stack = ft_calloc(len, sizeof(long));
	ft_memcpy(sorted_stack, stack, sizeof(long) * len);
	quick_sort(sorted_stack, 0, len - 1);
	i = 0;
	while (i < len)
	{
		temp = ft_calloc(sizeof(t_item), 1);
		temp->value = stack[i];
		temp->index = binary_search(sorted_stack, stack[i], 0, len - 1);
		ft_lstadd_back(stack_a, ft_lstnew(temp));
		i++;
	}
	free(stack);
	free(sorted_stack);
}

void	print_content(void *content)
{
	t_item	*temp;

	temp = (t_item *)content;
	ft_printf("Element: %d, Index: %d\n", temp->value, temp->index);
}
