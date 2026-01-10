/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:15:48 by dbiletsk          #+#    #+#             */
/*   Updated: 2025/10/25 15:28:27 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	append_to(char **stash, char *buffer)
{
	char	*temp;

	if (!*stash)
	{
		*stash = ft_strdup(buffer);
		return ;
	}
	temp = ft_strdup(*stash);
	free(*stash);
	*stash = ft_strjoin(temp, buffer);
	free(temp);
}

static char	*find_nl(int fd, char **stash)
{
	char	*buffer;
	int		bread;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bread = 1;
	while (bread && !ft_strchr(buffer, '\n'))
	{
		bread = read(fd, buffer, BUFFER_SIZE);
		if (bread == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (bread == 0)
			break ;
		buffer[bread] = '\0';
		append_to(stash, buffer);
	}
	free(buffer);
	return (*stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*remains;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = find_nl(fd, &stash);
	if (stash == NULL || *stash == '\0')
		return (free(stash), NULL);
	if (ft_strchr(stash, '\n'))
	{
		line = ft_substr(stash, 0, ft_strchr(stash, '\n') - stash + 1);
		remains = ft_substr(stash, ft_strchr(stash, '\n') - stash + 1,
				ft_strlen(stash) - (ft_strchr(stash, '\n') - stash));
	}
	else
	{
		line = ft_strdup(stash);
		remains = ft_strdup("");
	}
	free(stash);
	stash = ft_strdup(remains);
	return (free(remains), line);
}
