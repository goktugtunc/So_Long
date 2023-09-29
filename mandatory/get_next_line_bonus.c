/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:56:30 by gotunc            #+#    #+#             */
/*   Updated: 2023/08/26 13:25:46 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*delete_line(char *left)
{
	char	*buff;
	int		i;

	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	i++;
	buff = ft_substr(left, i, (ft_strlen(left) - i));
	if (!buff)
		return (NULL);
	free(left);
	return (buff);
}

char	*come_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!(buffer[i]))
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		line = ft_substr(buffer, 0, i + 1);
	else
		line = ft_substr(buffer, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*reading_file(int fd, char *buffer)
{
	char	*buff;
	int		byte;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	byte = 1;
	while (!ft_strchr(buffer, '\n') && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			free(buffer);
			return (NULL);
		}
		buff[byte] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
		return (NULL);
	buffer[fd] = reading_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = come_line(buffer[fd]);
	buffer[fd] = delete_line(buffer[fd]);
	return (line);
}
