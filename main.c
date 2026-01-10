/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <dbiletsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:57:22 by dbiletsk          #+#    #+#             */
/*   Updated: 2026/01/10 17:51:08 by dbiletsk         ###   ########.fr       */
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

int	is_arrays_are_same(long *arr1, long *arr2, int len)
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
	while (--argc)
		free(temp[argc]);
	return (free(temp), len);
}

int	main(int argc, char **argv)
{
	// t_list stack;
    long *stack;
    stack = NULL;
	/*---------------------------------INPUT VALIDATION---------------------------------*/
	if (argc >= 2)
	{
		// Checking for not digits in string
        if (argc == 2)
        {
            if (!is_all_digits(argv[1]))
			    return (printf("Error\n"), 0);
        }
        else
        {
            int i = 1;
            while(argv[i])
            {
                if (!is_all_digits(argv[i]))
			        return (printf("Error\n"), 0); 
            }
        }
		int len;
		int i;
        long *uniq;

		i = -1;
		len = parse_input(&stack, argc, argv);
		if (len == 1)
			return (free(stack), printf("Already sorted"), 0);
		// Check for numbers  exceeding limits of int
		if (!is_array_in_int_range(stack, len))
			return (free(stack), printf("exceeding limits of int\n"), 0);
		// Checking for unique numbers
        uniq = ft_calloc(len, sizeof(long));
		i = -1;
		while (++i < len)
		{
			if (!is_number_in(uniq, len, stack[i]))
				uniq[i] = stack[i];
			ft_printf("%i\n", uniq[i]);
		}
		if (is_arrays_are_same(stack, uniq, len))
			printf("Array are unique");
		else
			printf("Array are not unique");
		free(stack);
		free(uniq);

		/*---------------------------------INPUT VALIDATION END---------------------------------*/
	}

	return (0);
}