/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <dbiletsk@student.42.>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:30:00 by dbiletsk          #+#    #+#             */
/*   Updated: 2026/02/05 20:45:00 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swamp.h"

int	find_elem_position_by_index(t_list *stack, int index)
{
	t_list	*ptr;
	t_item	*node;
	int		i;

	i = 0;
	ptr = stack;
	while (ptr != NULL)
	{
		node = (t_item *)ptr->content;
		if (node->index == index)
			return (i);
		i++;
		ptr = ptr->next;
	}
	return (-1);
}

t_item	*get_lowest_price_node_context(t_list *stack_a)
{
	t_list	*ptr;
	t_item	*lowest;
	t_item	*node;
	int		lowest_price;
	int		node_price;

	ptr = stack_a;
	lowest = (t_item *)ptr->content;
	lowest_price = lowest->price + lowest->target_price;
	ptr = ptr->next;
	while (ptr)
	{
		node = (t_item *)ptr->content;
		node_price = node->price + node->target_price;
		if (node_price < lowest_price)
		{
			lowest = node;
			lowest_price = node_price;
		}
		ptr = ptr->next;
	}
	return (lowest);
}

void	move_cheapest_node(t_list **stack_src, t_list **stack_dst, char src,
		char dst)
{
	t_item	*cheapest_node;

	set_target_nodes(*stack_src, *stack_dst);
	set_price(*stack_src, *stack_dst);
	cheapest_node = get_lowest_price_node_context(*stack_src);
	push_node_to_top(stack_src, cheapest_node->index, src);
	push_node_to_top(stack_dst, cheapest_node->target_node_index, dst);
	p(stack_src, stack_dst, dst);
}

int	is_sorted(t_list *stack)
{
	t_list	*ptr;
	t_item	*current;
	t_item	*next;

	ptr = stack;
	while (ptr && ptr->next)
	{
		current = (t_item *)ptr->content;
		next = (t_item *)ptr->next->content;
		if (current->index > next->index)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	turk_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) < 2)
	{
		p(stack_a, stack_b, 'b');
		p(stack_a, stack_b, 'b');
	}
	while (ft_lstsize(*stack_a) > 3)
	{
		move_cheapest_node(stack_a, stack_b, 'a', 'b');
	}
	tiny_sort(stack_a, 'a');
	while (*stack_b)
	{
		move_cheapest_node(stack_b, stack_a, 'b', 'a');
	}
	push_node_to_top(stack_a, 0, 'a');
}
