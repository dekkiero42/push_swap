/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:29:00 by dbiletsk          #+#    #+#             */
/*   Updated: 2025/10/06 18:35:55 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	space_left;
	int		i;

	i = 0;
	space_left = len;
	if (!ft_strlen(little))
		return ((char *)big);
	if (ft_strlen(big) < len)
		space_left = ft_strlen(big);
	while (space_left >= ft_strlen(little))
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(&big[i], little, ft_strlen(little)) == 0)
				return ((char *)&big[i]);
		}
		i++;
		space_left--;
	}
	return (NULL);
}
