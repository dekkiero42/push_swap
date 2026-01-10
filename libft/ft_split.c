/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:57:33 by dbiletsk          #+#    #+#             */
/*   Updated: 2025/10/21 20:37:40 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_size(char const *str, char c)
{
	char	*iptr;
	size_t	size;
	int		flag;

	iptr = ft_strchr(str, c);
	if (!iptr)
		return (1);
	size = 1;
	flag = 1;
	while (*iptr)
	{
		if (*iptr == c && flag)
		{
			size++;
			flag = 0;
		}
		if (*iptr != c)
			flag = 1;
		iptr++;
	}
	return (size);
}

static int	separate(char const *str, char c, char **arr)
{
	size_t	start;
	size_t	end;
	int		flag;

	flag = 1;
	start = 0;
	end = -1;
	while (str[++end])
	{
		if (str[end] == c && flag)
		{
			*arr = ft_substr(str, start, end - start);
			if (!*arr++)
				return (0);
			flag = 0;
		}
		if (str[end] != c && !flag)
		{
			start = end;
			flag = 1;
		}
	}
	*arr = ft_substr(str, start, end - start);
	return (1);
}

static char	**wrap_up(char *arr_to_free)
{
	char	**arr;

	if (arr_to_free)
		free(arr_to_free);
	arr = ft_calloc(1, sizeof(char *));
	if (!arr)
		return (NULL);
	arr[0] = NULL;
	return (arr);
}

static void	free_2d(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**arr;
	char	*t;
	char	x[2];

	x[0] = c;
	x[1] = '\0';
	if (!s)
		return (NULL);
	t = ft_strtrim(s, x);
	if (!t || *t == '\0')
		return (wrap_up(t));
	size = find_size(t, c);
	if (!size)
		return (wrap_up(t));
	arr = ft_calloc(size + 1, sizeof(char *));
	if (!arr)
		return (wrap_up(t));
	arr[size] = NULL;
	if (!separate(t, c, arr))
	{
		free_2d(arr);
		return (wrap_up(t));
	}
	return (free(t), arr);
}
