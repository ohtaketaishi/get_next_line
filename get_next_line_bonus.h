/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:13:45 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/17 19:09:34 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define FIND_N    1
# define ERROR    -1
# define CONTINUE_READ  -2
# define FD_MAX 1024

int		get_next_line(int fd, char **line);
void	free_ptr(char **ptr);
size_t	strlen_gnl(char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*strdup_gnl(char *s1, char c);
char	*strjoin_gnl(char *s1, char *s2);

#endif
