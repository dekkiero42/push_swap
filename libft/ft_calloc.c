/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:33:26 by dbiletsk          #+#    #+#             */
/*   Updated: 2025/10/09 20:45:42 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb != 0)
	{
		if (size > SIZE_MAX / nmemb)
			return (NULL);
		ptr = (void *)malloc(size * nmemb);
		if (ptr)
			ft_memset(ptr, 0, nmemb * size);
	}
	else
		ptr = (void *)malloc(1);
	return (ptr);
}
