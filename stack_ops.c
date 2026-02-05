/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <dbiletsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:30:00 by dbiletsk          #+#    #+#             */
/*   Updated: 2026/02/05 20:45:00 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swamp.h"

void	s(t_list **stack, char c)
{
	t_list	*second;
	t_item	*temp;

	ft_printf("s%c\n", c);
	second = (*stack)->next;
	if (second == NULL)
		return ;
	temp = (*stack)->content;
	(*stack)->content = second->content;
	second->content = temp;
}

void	p(t_list **src, t_list **dst, char c)
{
	t_list	*temp;

	ft_printf("p%c\n", c);
	if (*src == NULL)
		return ;
	temp = (*src)->next;
	if (*dst == NULL)
	{
		*dst = *src;
		(*src)->next = NULL;
	}
	else
		ft_lstadd_front(dst, *src);
	*src = temp;
}

void	r(t_list **dst, char c)
{
	t_list	*first;
	t_list	*second;

	ft_printf("r%c\n", c);
	first = *dst;
	second = (*dst)->next;
	first->next = NULL;
	*dst = second;
	ft_lstadd_back(dst, first);
}

void	rr(t_list **dst, char c)
{
	size_t	i;
	size_t	len;
	t_list	*ptr;

	len = ft_lstsize(*dst);
	ptr = *dst;
	ft_printf("rr%c\n", c);
	i = 0;
	while (i++ < len - 2)
		ptr = ptr->next;
	ft_lstadd_front(dst, ft_lstlast(*dst));
	ptr->next = NULL;
}

void	push_node_to_top(t_list **stack, int index, char c)
{
	int	pos;

	pos = find_elem_position_by_index(*stack, index);
	if (pos > ft_lstsize(*stack) / 2)
	{
		pos = ft_lstsize(*stack) - pos;
		while (pos--)
			rr(stack, c);
		return ;
	}
	while (pos--)
		r(stack, c);
}
