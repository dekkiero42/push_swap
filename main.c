/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <dbiletsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:57:22 by dbiletsk          #+#    #+#             */
/*   Updated: 2026/01/29 18:29:46 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

typedef struct s_item
{
    long value;
    int index;
	int  target_node_index;
	int price;
	int target_price;
}   t_item;

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_all_digits(char *s)
{
	char	*ptr;

	ptr = s;
	while (*ptr)
	{
		if (!ft_isdigit(*ptr) && !are_in("+- ", *ptr))
			return (0);
		ptr++;
	}
	return (1);
}

int	is_number_in(long *array, int len, long number)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (array[i] == number)
			return (1);
	}
	return (0);
}

int	is_arrays_are_equal(long *arr1, long *arr2, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (arr1[i] != arr2[i])
			return (0);
	}
	return (1);
}
int	is_array_in_int_range(long *arr, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if ((arr[i] > INT_MAX) || (arr[i] < INT_MIN))
			return (0);
	}
	return (1);
}

static int	parse_input(long **buffer, int argc, char **argv)
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
int is_input_valid(int argc , char **argv)
{
	int i;
	
	if (argc == 2)
	{
		if (!is_all_digits(argv[1]))
			return (printf("Error\n"), 0);
	}
	else
	{
		i = 1;
		while(argv[i])
		{
			if (!is_all_digits(argv[i++]))
				return (printf("Error\n"), 0); 
		}
	}
	return 1;
}

int is_stack_valid(long* stack, int len)
{
	long *uniq;
	int i;

	if (len == 1)
		return (printf("Already sorted"), 0);
	// Check for numbers  exceeding limits of int
	if (!is_array_in_int_range(stack, len))
		return (printf("Exceeding limits of int"), 0);
	// Checking for unique numbers
	uniq = ft_calloc(len, sizeof(long));
	i = -1;
	while (++i < len)
	{
		if (!is_number_in(uniq, len, stack[i]))
			uniq[i] = stack[i];
	}
	if (!is_arrays_are_equal(stack, uniq, len))
		return printf("Array are not unique"), 0;
	return free(uniq), 1;
}

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



// low and high here are bassicly indexex that represent the slice of array ,
//we ned this two cause we will call it recoursevly
void quick_sort(long* arr,int low,int high)
{
	//This one is here cause we need basecase to leave recursion.
	//It will fires when recursion would dive so deep that parts have len 1
	if (low < high)
	{
		int pivot_index;
		
		pivot_index = partition(arr, low ,high);

		quick_sort(arr,0, pivot_index - 1);
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

void print_content(void* content)
{
	t_item *temp = (t_item *)content;
	ft_printf("Element: %d, Index: %d\n",temp->value,temp->index);
}

void s(t_list** stack)
{
	t_list *second;
	t_item *temp;

	second = (*stack)->next;

	if (second == NULL)
		return;
	temp = (*stack)->content;
	(*stack)->content = second->content;
	second ->content = temp;
}

void p(t_list** src, t_list** dst)
{
	t_list *temp;

	temp = (*src)->next;
	if (*src == NULL)
		return;
	if (*dst == NULL)	
	{
		*dst = *src;
		(*src)->next = NULL;
	}
	else
		ft_lstadd_front(dst,*src);
	*src = temp; 


}

void r(t_list** dst)
{
	t_list *first;
	t_list *second;

	first = *dst;
	second = (*dst)->next;
	first->next = NULL;
	*dst = second;
	ft_lstadd_back(dst,first);
}

void rr(t_list** dst)
{
	size_t i;
	size_t len = ft_lstsize(*dst);

	t_list *ptr = *dst;
	i = 0;
	while (i++ < len - 2)
		ptr = ptr->next;
	ft_lstadd_front(dst, ft_lstlast(*dst));
	
	ptr->next = NULL;
	
}

int find_elem_position_by_index(t_list *stack,int index)
{
	t_list* ptr;
	t_item* node;
	int i;
	
	i = 0;
	ptr = stack;
	while(ptr != NULL)
	{
		node = (t_item *)ptr->content;
		if(node->index == index)
			return i;
		i++;
		ptr = ptr->next;
	}
	
	return -1;
}

void set_target_nodes(t_list* src,t_list *dst)
{
	t_item* src_node_item;
	t_list *ptr_src;
	t_list *ptr_dst;
	long temp;
	long closest;
	
	closest = ((t_item *)dst->content)->index;
	ptr_src = src;
	while(ptr_src)
	{
		//Current node t_item which is needed to compare indexes and to change target node in end
		src_node_item = (t_item *)ptr_src->content;
		//Pointer to itterate trought b;
		ptr_dst = dst;
		while(ptr_dst)
		{
			temp = ((t_item *)dst->content)->index;
			if ((src_node_item->index < temp ) && (temp< closest))
			closest = temp;
			ptr_dst = ptr_dst->next;
		}
		src_node_item->target_node_index = closest;
		ptr_src = ptr_src->next;
	}
}
//src is stack for which node we defining price, dst where we would be moving them
//Function sets price value in each node of src, price respresen how much operation u should do to transfer node from src on top of target node
//CALL AFTER TARGET NODES ARE SET 
void set_price(t_list* src,t_list *dst)
{
	t_item* src_node_item;
	t_list *ptr_a;
	int node_position;
	int target_position;

	ptr_a = src;
	while(ptr_a)
	{	
		src_node_item = (t_item *)ptr_a->content;
		node_position = find_elem_position_by_index(src,src_node_item->index);
		
		if (node_position > ft_lstsize(src)/2)
			node_position = ft_lstsize(src) - node_position;

		target_position = find_elem_position_by_index(dst, src_node_item->target_node_index);

		if (target_position > ft_lstsize(dst)/2)
			target_position = ft_lstsize(dst) - target_position;
		src_node_item->price = node_position;
		src_node_item->target_price = target_position;
		ptr_a = ptr_a->next;
	}
}

t_item *get_lowest_price_node_context(t_list *stack_a)
{
	t_list* ptr;
	t_item* lowest;
	t_item* node;
	int lowest_price;
	int node_price;
	
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

void push_node_to_top(t_list *stack,int index)
{
	int pos;

	pos = find_elem_position_by_index(stack,index);
	if (pos > ft_lstsize(stack)/2)
	{
		pos = ft_lstsize(stack) - pos;
		//MAYBE HERE WILL BE A BAG
		while(pos--)
			rr(&stack);
	}
	//MAYBE HERE WILL BE A BAG
	while(pos--)
			r(&stack);
}

int	main(int argc, char **argv)
{
	// t_list stack;
    long *stack;
    stack = NULL;
	/*---------------------------------INPUT VALIDATION---------------------------------*/
	if (argc >= 2)
	{
		int len;
		if (!is_input_valid(argc,argv))
			return (printf("Input is not valid"), 0);
		len = parse_input(&stack, argc, argv);
		if(!is_stack_valid(stack,len))
			return (free(stack), printf("Stack is not valid"), 0);
		//printf("Stack is valid\n");
		
	/*---------------------------------INPUT VALIDATION END---------------------------------*/
		
		//Cpy stack
		long *sorted_stack;
		sorted_stack = ft_calloc(len, sizeof(long));
		ft_memcpy(sorted_stack,stack,sizeof(long) * len);
		quick_sort(sorted_stack,0,len - 1);
		int i = 0;
		t_list *stack_a;
		stack_a = NULL;

		t_list *stack_b;
		stack_a = NULL;
		stack_b = NULL;
		while(i < len)
		{
			t_item *temp;
			temp = ft_calloc(sizeof(t_item),1);
			temp->value = stack[i];
			temp->index = binary_search(sorted_stack,stack[i], 0, len - 1);
			ft_lstadd_back(&stack_a,ft_lstnew(temp));
			i++;
		}



		/*---------------------------------Algorithm---------------------------------*/
		//Find smallest number position
		//Choose direction of rotation
		//Rotatte it to the top
		//Push it to b
		//Repeat until thete is no elems
		//Push all stack b elems to a
		i = 0;
		while (ft_lstsize(stack_a) > 3)
		{
			if (ft_lstsize(stack_b) >=2)
			{
				set_target_nodes(stack_a,stack_b);
				set_price(stack_a,stack_b);
				t_item* cheapest_node = get_lowest_price_node_context(stack_a);
				push_node_to_top(stack_a,cheapest_node->index);
				push_node_to_top(stack_b,cheapest_node->target_node_index);
				p(&stack_a,&stack_b);
			}
			else
			{
				p(&stack_a,&stack_b);
				p(&stack_a,&stack_b);
			}
		}

		//ft_lstiter(stack_a,print_content);
		ft_lstiter(stack_b,print_content);
		ft_lstclear(&stack_a,free);
		ft_lstclear(&stack_b,free);

		free(sorted_stack);
		free(stack);
	}

	return (0);
}