/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:18:47 by aglinski          #+#    #+#             */
/*   Updated: 2024/04/24 18:18:48 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buffer_tmp, int *eol_loc)
{
	size_t	len;
	char	*str;

	len = 0;
	while (buffer_tmp[len] && buffer_tmp[len] != '\n')
		len++;
	len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_memcpy(str, buffer_tmp, len);
	str[len] = '\0';
	if (len > 0 && str[len - 1] == '\n')
		*eol_loc = len - 1;
	return (str);
}

size_t	find_eol_position(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (i < BUFFER_SIZE || str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*read_extract_line(char *line, char *buffer_tmp, int *eol_loc, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	len;
	ssize_t	bytes_read;

	while (*eol_loc == -1)
	{
		ft_bzero(buffer, (BUFFER_SIZE + 1));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			ft_bzero(buffer_tmp, (BUFFER_SIZE + 1));
			return (0);
		}
		len = find_eol_position(buffer);
		ft_strlcpy_gnl(buffer_tmp, &buffer[len], (BUFFER_SIZE + 1));
		buffer[len] = '\0';
		line = ft_strjoin_gnl(line, buffer, eol_loc);
		if (bytes_read == 0)
		{
			ft_bzero(buffer_tmp, BUFFER_SIZE + 1);
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer_tmp[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			eol_loc;

	eol_loc = -1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (0);
	line = ft_get_line(buffer_tmp[fd], &eol_loc);
	if (!line)
		return (0);
	ft_strlcpy_gnl(buffer_tmp[fd], &buffer_tmp[fd][eol_loc + 1],
		BUFFER_SIZE + 1);
	line = read_extract_line(line, buffer_tmp[fd], &eol_loc, fd);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}
