/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <dbiletsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:30:00 by dbiletsk          #+#    #+#             */
/*   Updated: 2026/02/05 20:45:00 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swamp.h"

void swap(long *a, long *b)
{
	long temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(long *arr, int low , int high)
{
	long pivot;
	int i;
	int j;
	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i+1],&arr[high]);
	return i + 1;
}

void quick_sort(long* arr,int low,int high)
{
	if (low < high)
	{
		int pivot_index;
		
		pivot_index = partition(arr, low ,high);
		quick_sort(arr,low,pivot_index - 1);
		quick_sort(arr, pivot_index + 1, high);
	}
}

int binary_search(long *arr,long numb, int low,int high)
{
	if (high>=low)
	{
		int mid = low +(high - low) / 2;
		
		if (arr[mid] == numb)
			return mid;
		if (arr[mid] > numb)
		{
			high = mid -1;
			return binary_search(arr, numb,low, mid - 1);
		}
		return 	binary_search(arr, numb,mid + 1,high);
	}
	return -1;
}

void tiny_sort(t_list **stack, char c)
{
	int first;
	int second;
	int third;
	first = ((t_item *)(*stack)->content)->index;
	second = ((t_item *)(*stack)->next->content)->index;
	third = ((t_item *)(*stack)->next->next->content)->index;
	if (first > second && first < third && second < third)
		s(stack,c);
	else if (first > second && first > third && second > third)
	{
		s(stack,c);
		rr(stack,c);
	}
	else if (first > second && first > third && second < third)
		r(stack,c);
	else if (first < second && first < third && second > third)
	{
		s(stack,c);
		r(stack,c);
	}
	else if (first < second && first > third && second > third)
		rr(stack,c); 
}
