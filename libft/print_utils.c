/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <dbiletsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:44:19 by dbiletsk          #+#    #+#             */
/*   Updated: 2025/11/16 13:42:16 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	are_in(char c, char *s)
{
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}*/

int	print_string(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	print_char(unsigned int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	return (write(1, &ch, 1));
}

int	print_uint(unsigned int n)
{
	char	s[11];
	int		i;

	i = 9;
	s[10] = '\0';
	if (n == 0)
		return (print_string("0"));
	while (n > 0)
	{
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	return (print_string(&s[++i]));
}
