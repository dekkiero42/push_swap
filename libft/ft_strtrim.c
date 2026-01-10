/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:30:40 by dbiletsk          #+#    #+#             */
/*   Updated: 2025/10/19 19:35:53 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	are_in(char const *set, char c)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

static size_t	directional_skip(const char *s, const char *set, int i, int d)
{
	while (s[i])
	{
		if (!are_in(set, s[i]))
			break ;
		i += d;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = directional_skip(s1, set, 0, 1);
	if (start == ft_strlen(s1))
		return ((char *)ft_calloc(1, 1));
	end = directional_skip(s1, set, ft_strlen(s1) - 1, -1);
	str = (char *)ft_calloc(end - start + 2, 1);
	if (str)
		ft_strlcpy(str, &s1[start], end - start + 2);
	return (str);
}
