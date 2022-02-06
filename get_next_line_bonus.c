/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:05:40 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/28 14:41:55 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static ssize_t	save_in_line(char **save, char **line)
{
	char *tmp;

	if (!(*line = strdup_gnl(*save, '\n')))
		return (ERROR);
	if (ft_strchr(*save, '\n'))
	{
		tmp = *save;
		if (!(*save = strdup_gnl((char *)(ft_strchr(*save, '\n') + 1), '\0')))
		{
			free_ptr(line);
			return (ERROR);
		}
		free_ptr(&tmp);
		return (FIND_N);
	}
	else
	{
		free_ptr(save);
		return (CONTINUE_READ);
	}
}

static ssize_t	buf_join_line(char *buf, char **save, char **line)
{
	char *tmp;

	tmp = *line;
	if (!(*line = strjoin_gnl(*line, buf)))
	{
		free_ptr(line);
		return (ERROR);
	}
	free_ptr(&tmp);
	if (ft_strchr(buf, '\n'))
	{
		if (!(*save = strdup_gnl((char *)(ft_strchr(buf, '\n') + 1), '\0')))
		{
			free_ptr(line);
			return (ERROR);
		}
		return (FIND_N);
	}
	else
		return (CONTINUE_READ);
}

static size_t	read_process(int fd, char *buf, char **save, char **line)
{
	ssize_t ret;
	int		flag;

	flag = 0;
	ret = CONTINUE_READ;
	while (ret == CONTINUE_READ)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (!(flag == 0 && ret == 0) && ret <= 0)
			break ;
		buf[ret] = '\0';
		ret = buf_join_line(buf, save, line);
		flag = 1;
	}
	free_ptr(&buf);
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	ssize_t		ret;
	static char *save[FD_MAX];

	if (!line || FD_MAX <= fd ||
			read(fd, save[fd], 0) < 0 || BUFFER_SIZE <= 0 ||
			!(buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1))))
		return (ERROR);
	*line = NULL;
	if (!save[fd])
		return (ret = read_process(fd, buf, &save[fd], line));
	if ((ret = save_in_line(&save[fd], line)) == CONTINUE_READ)
		return (ret = read_process(fd, buf, &save[fd], line));
	free_ptr(&buf);
	return (ret);
}
