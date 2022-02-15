/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seucho <seucho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:10:59 by seucho            #+#    #+#             */
/*   Updated: 2022/02/16 00:34:20 by seucho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save = iter_read(save, fd);
	if (save == NULL)
		return (NULL);
	line = get_line(save);
	if (line == NULL)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = update_remain(&save, ft_strlen(line));
	if (save == NULL)
		return (NULL);
	return (line);
}

char	*iter_read(char *save, int fd)
{
	char	*temp;
	char	*buf;
	char	*new;
	ssize_t	num_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	new = save;
	num_read = 0;
	while (new == NULL || !ft_strchr(new, '\n'))
	{
		num_read = read(fd, buf, BUFFER_SIZE);
		if (num_read <= 0)
			break ;
		buf[num_read] = '\0';
		temp = new;
		new = append_str(new, buf);
		free(temp);
	}
	free(buf);
	buf = NULL;
	if (num_read < 0)
		return (NULL);
	return (new);
}

char	*get_line(char const *save)
{
	size_t	len;
	char	*line;

	if (ft_strchr(save, '\n'))
	{
		len = ft_strchr(save, '\n') - save + 1;
	}
	else
	{
		len = ft_strchr(save, '\0') - save;
	}
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, save, len + 1);
	return (line);
}

char	*update_remain(char **save, size_t offset)
{
	char	*new;

	new = malloc(ft_strlen(*save + offset) + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, *save + offset, ft_strlen(*save + offset) + 1);
	free(*save);
	*save = NULL;
	return (new);
}
