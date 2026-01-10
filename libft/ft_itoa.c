/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:08:51 by dbiletsk          #+#    #+#             */
/*   Updated: 2025/10/17 18:20:05 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_len(int n)
{
	size_t	size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10 != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	temp;
	size_t	size;

	size = nbr_len(n);
	temp = n;
	if (n < 0)
		temp *= -1;
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (--size > 0)
	{
		str[size] = temp % 10 + '0';
		temp /= 10;
	}
	if (n < 0)
		str[0] = '-';
	else
		str[0] = temp + '0';
	return (str);
}
