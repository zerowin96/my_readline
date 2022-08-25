/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:20:52 by yeham             #+#    #+#             */
/*   Updated: 2022/08/23 21:31:55 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_check(char *storage)
{
	int	i;

	i = 0;
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*line_maker(int fd, char *buf, char *storage)
{
	int	r_size;

	r_size = read(fd, buf, BUFFER_SIZE);
	while (r_size > 0)
	{
		buf[r_size] = '\0';
		if (!storage)
			storage = gnl_strdup(buf);
		else
			storage = gnl_strjoin(storage, buf);
		if (storage == NULL)
			return (NULL);
		if (gnl_check(storage) != -1)
			return (storage);
		r_size = read(fd, buf, BUFFER_SIZE);
	}
	return (storage);
}

char	*namuji(char *line)
{
	unsigned int		i;
	char				*tmp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	tmp = gnl_strdup(line + i + 1);
	if (tmp == NULL)
		return (NULL);
	if (*tmp == '\0')
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	char		*temp2;
	static char	*storage[10240];

	if (fd < 0 || fd > 10240 || BUFFER_SIZE < 1)
		return (NULL);
	line = line_maker(fd, buf, storage[fd]);
	if (line == 0)
		return (NULL);
	storage[fd] = namuji(line);
	temp2 = gnl_strdup(line);
	free(line);
	line = NULL;
	return (temp2);
}
