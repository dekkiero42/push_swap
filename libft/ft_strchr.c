/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:42:11 by dbiletsk          #+#    #+#             */
/*   Updated: 2025/10/04 13:39:22 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	chr;

	chr = (unsigned char)c;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == chr)
			return (ptr);
		ptr++;
	}
	if (chr == '\0')
		return (ptr);
	return (NULL);
}
