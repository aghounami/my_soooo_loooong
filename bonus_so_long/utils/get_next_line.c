/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:09:27 by aghounam          #+#    #+#             */
/*   Updated: 2023/12/31 17:19:55 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *buffer)
{
	int	le;

	le = 0;
	while (buffer[le] != '\n' && buffer[le])
	{
		le++;
	}
	if (buffer[le] == '\n')
		le++;
	return (le);
}

char	*ft_next(char *data)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	while (data[i] && data[i] != '\n')
		i++;
	if (data[i] == '\n')
		i++;
	if (!data[i])
		return (free(data), NULL);
	next = f_calloc((f_strlen(data) - i + 1), sizeof(char));
	if (!next)
		return (free(data), NULL);
	while (data[i])
		next[j++] = data[i++];
	next[j++] = '\0';
	free(data);
	return (next);
}

char	*ft_line(char *data)
{
	char	*line;
	int		i;

	i = 0;
	while (data[i] && data[i] != '\n')
		i++;
	if (data[i] == '\n')
		i++;
	line = f_calloc(i + 1, sizeof(char));
	i = 0;
	while (data[i] && data[i] != '\n')
	{
		line[i] = data[i];
		i++;
	}
	if (data[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *data)
{
	char	*temp;
	int		byte;

	if (!data)
		data = f_calloc(1, 1);
	temp = f_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte = 1;
	while (byte > 0 && !f_strchr(temp, '\n'))
	{
		byte = read(fd, temp, BUFFER_SIZE);
		if (byte == -1)
		{
			free(data);
			free(temp);
			return (NULL);
		}
		temp[byte] = '\0';
		data = f_strjoin(data, temp);
	}
	free(temp);
	return (data);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	data = read_file(fd, data);
	if (data == NULL)
		return (NULL);
	if (ft_len(data) == 0)
	{
		free(data);
		data = NULL;
		return (NULL);
	}
	line = ft_line(data);
	data = ft_next(data);
	return (line);
}
