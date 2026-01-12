/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:57:22 by dbiletsk          #+#    #+#             */
/*   Updated: 2026/01/12 23:17:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// typedef struct s_item
// {
//     long value;
//     int index;
// }   t_item;

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
		print_char(len);
		printf("Stack is ready\n");
		
		/*---------------------------------INPUT VALIDATION END---------------------------------*/
		
		//Cpy stack
		long *sorted_stack;
		sorted_stack = ft_calloc(len, sizeof(long));
		ft_memcpy(sorted_stack,stack,sizeof(long) * len);
		quick_sort(sorted_stack,0,len - 1);
		int i = 0;
		while (i < len)
		{
			ft_printf("%d\n",sorted_stack[i++]);
		}

		

		free(sorted_stack);
		free(stack);
	}

	return (0);
}