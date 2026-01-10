/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:55:42 by dbiletsk          #+#    #+#             */
/*   Updated: 2025/10/19 19:10:14 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*s;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = -1;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *)malloc(size);
	if (s)
	{
		while (s1[++i])
			s[i] = s1[i];
		i = -1;
		while (s2[++i])
			s[i + ft_strlen(s1)] = s2[i];
		s[i + ft_strlen(s1)] = '\0';
	}
	return (s);
}
