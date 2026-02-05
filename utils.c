/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <dbiletsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:30:00 by dbiletsk          #+#    #+#             */
/*   Updated: 2026/02/05 20:45:00 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swamp.h"

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

int	are_arrays_equal(long *arr1, long *arr2, int len)
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
