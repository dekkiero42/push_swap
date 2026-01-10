/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:37:26 by dbiletsk          #+#    #+#             */
/*   Updated: 2025/10/19 17:39:25 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned int	res;
	int				i;

	if (*nptr == '\0')
		return (0);
	res = 0;
	i = -1;
	while ((*nptr < 14 && *nptr > 8) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		sign = 1;
		if (*nptr++ == '-')
			sign = -1;
	}
	else
		sign = 1;
	while (ft_isdigit(nptr[++i]))
		res = (res * 10) + nptr[i] - '0';
	return (res * sign);
}
