/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_price.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <dbiletsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:30:00 by dbiletsk          #+#    #+#             */
/*   Updated: 2026/02/05 20:45:00 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swamp.h"

long	find_smallest_greater_index(t_item *src_node_item, t_list *dst)
{
	t_list	*ptr_dst;
	long	temp;
	long	closest;

	ptr_dst = dst;
	closest = -1;
	while (ptr_dst)
	{
		temp = ((t_item *)ptr_dst->content)->index;
		if (temp > src_node_item->index)
		{
			if (closest == -1 || temp < closest)
				closest = temp;
		}
		ptr_dst = ptr_dst->next;
	}
	return (closest);
}

long	find_smallest_index(t_list *dst)
{
	t_list	*ptr_dst;
	long	temp;
	long	smallest;

	ptr_dst = dst;
	smallest = ((t_item *)ptr_dst->content)->index;
	while (ptr_dst)
	{
		temp = ((t_item *)ptr_dst->content)->index;
		if (temp < smallest)
			smallest = temp;
		ptr_dst = ptr_dst->next;
	}
	return (smallest);
}

long	find_target_index(t_item *src_node_item, t_list *dst)
{
	long	closest;

	closest = find_smallest_greater_index(src_node_item, dst);
	if (closest == -1)
		closest = find_smallest_index(dst);
	return (closest);
}

void	set_target_nodes(t_list *src, t_list *dst)
{
	t_item	*src_node_item;
	t_list	*ptr_src;

	if (dst == NULL)
		return ;
	ptr_src = src;
	while (ptr_src)
	{
		src_node_item = (t_item *)ptr_src->content;
		src_node_item->target_node_index = find_target_index(src_node_item,
				dst);
		ptr_src = ptr_src->next;
	}
}

void	set_price(t_list *src, t_list *dst)
{
	t_item	*src_node_item;
	t_list	*ptr_a;
	int		node_position;
	int		target_position;

	ptr_a = src;
	while (ptr_a)
	{
		src_node_item = (t_item *)ptr_a->content;
		node_position = find_elem_position_by_index(src, src_node_item->index);
		if (node_position > ft_lstsize(src) / 2)
			node_position = ft_lstsize(src) - node_position;
		target_position = find_elem_position_by_index(dst,
				src_node_item->target_node_index);
		if (target_position > ft_lstsize(dst) / 2)
			target_position = ft_lstsize(dst) - target_position;
		src_node_item->price = node_position;
		src_node_item->target_price = target_position;
		ptr_a = ptr_a->next;
	}
}
