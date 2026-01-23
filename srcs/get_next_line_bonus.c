/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:57:22 by eseragio          #+#    #+#             */
/*   Updated: 2025/11/13 16:50:13 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//acumula dados ate ter uma linha completa
char	*fill_line_buffer(int fd, char *line)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free(line), NULL);
	while (ft_strchr(line, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(line), NULL);
		else if (bytes_read == 0)
			break ;
		else if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			line = ft_strjoin(line, buffer);
			if (line == NULL)
				return (free(buffer), NULL);
		}
	}
	return (free(buffer), line);
}

char	*ft_clean(char *buffer)
{
	int		i;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	new_buffer = ft_substr(buffer, i + 1, ft_strlen(buffer) - i - 1);
	free(buffer);
	if (new_buffer == NULL)
		return (NULL);
	return (new_buffer);
}

char	*ft_next_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		line = ft_substr(buffer, 0, i + 1);
	else
		line = ft_substr(buffer, 0, i);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest_str[4096];
	char		*line;

	if (fd < 0 || fd >= 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	if (rest_str[fd] == NULL)
	{
		rest_str[fd] = ft_strdup("");
		if (rest_str[fd] == NULL)
			return (NULL);
	}
	rest_str[fd] = fill_line_buffer(fd, rest_str[fd]);
	if (!rest_str[fd])
		return (NULL);
	line = ft_next_line(rest_str[fd]);
	if (line == NULL)
	{
		free(rest_str[fd]);
		rest_str[fd] = NULL;
		return (NULL);
	}
	rest_str[fd] = ft_clean(rest_str[fd]);
	return (line);
}
