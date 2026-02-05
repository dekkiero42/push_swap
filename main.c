/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:57:22 by dbiletsk          #+#    #+#             */
/*   Updated: 2026/02/05 20:58:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swamp.h"

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2 && !is_sorted(*stack_a))
		s(stack_a, 'a');
	else if (ft_lstsize(*stack_a) == 3)
		tiny_sort(stack_a, 'a');
	else
	{
		while (!is_sorted(*stack_a))
			turk_sort(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	long	*temp;
	t_list	*stack_a;
	t_list	*stack_b;
	int		len;

	temp = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (!is_input_valid(argc, argv))
			return (ft_printf("Error\n"), 0);
		len = parse_input(&temp, argc, argv);
		if (!is_stack_valid(temp, len))
			return (free(temp), ft_printf("Error\n"), 0);
		populate_stack_a(temp, len, &stack_a);
		sort_stack(&stack_a, &stack_b);
		ft_lstclear(&stack_a, free);
		ft_lstclear(&stack_b, free);
	}
	return (0);
}
