/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:51:38 by dbiletsk          #+#    #+#             */
/*   Updated: 2025/10/19 19:07:28 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	space_left;
	char	*cpy;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	space_left = slen - start;
	if (!(start < slen) || !slen)
		return (ft_calloc(1, 1));
	if (space_left > len)
		space_left = len;
	cpy = (char *)ft_calloc(space_left + 1, 1);
	if (cpy)
		ft_strlcpy(cpy, &s[start], space_left + 1);
	return (cpy);
}
