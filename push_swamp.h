/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swamp.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:06:08 by dbiletsk          #+#    #+#             */
/*   Updated: 2026/02/03 19:06:10 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libft.h"

typedef struct s_item
{
    long value;
    int index;
	int  target_node_index;
	int price;
	int target_price;
}   t_item;

long	ft_atol(const char *str);
int	is_all_digits(char *s);
int	is_number_in(long *array, int len, long number);
int	is_arrays_are_equal(long *arr1, long *arr2, int len);
int	is_array_in_int_range(long *arr, int len);
int is_input_valid(int argc , char **argv);
int is_stack_valid(long* stack, int len);
void swap(long *a, long *b);
int partition(long *arr, int low , int high);
void quick_sort(long* arr,int low,int high);
int binary_search(long *arr,long numb, int low,int high);
void print_content(void* content);
void s(t_list** stack, char c);
void p(t_list** src, t_list** dst, char c);
void r(t_list** dst, char c);
void rr(t_list** dst, char c);
int find_elem_position_by_index(t_list *stack,int index);
void set_target_nodes(t_list* src,t_list *dst);
void set_price(t_list* src,t_list *dst);
t_item *get_lowest_price_node_context(t_list *stack_a);
void push_node_to_top(t_list **stack,int index,char c);
void tiny_sort(t_list **stack, char c);
void move_cheapest_node(t_list **stack_src, t_list **stack_dst,char src,char dst);
int is_sorted(t_list *stack);
void turk_sort(t_list **stack_a, t_list **stack_b);
void populate_stack_a(long *stack, long len, t_list **stack_a);

#endif