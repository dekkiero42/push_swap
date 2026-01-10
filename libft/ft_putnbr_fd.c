/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:38:48 by dbiletsk          #+#    #+#             */
/*   Updated: 2025/10/16 20:05:02 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	s[12];
	int		is_negative;
	long	temp;
	int		i;

	ft_bzero(s, 12);
	is_negative = 0;
	temp = n;
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		temp *= -1;
		is_negative = 1;
	}
	i = 10;
	while (temp > 0)
	{
		s[i--] = temp % 10 + '0';
		temp /= 10;
	}
	if (is_negative)
		s[i] = '-';
	write(fd, &s[i + !is_negative], ft_strlen(&s[i + !is_negative]));
}
