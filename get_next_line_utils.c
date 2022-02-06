/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:06:01 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/17 19:11:38 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

size_t	strlen_gnl(char *s, char c)
{
	size_t		i;

	i = 0;
	if (s)
		while (s[i] && s[i] != c)
			i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}

char	*strdup_gnl(char *s1, char c)
{
	char	*s2;
	size_t	i;

	if (c != '\n' && c != '\0')
		return (NULL);
	i = strlen_gnl(s1, c);
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s2[i] = '\0';
	while (i-- > 0)
		s2[i] = s1[i];
	return (s2);
}

char	*strjoin_gnl(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	i = strlen_gnl(s1, '\0');
	j = strlen_gnl(s2, '\n');
	if (!(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	s3[i + j] = '\0';
	while (j-- > 0)
		s3[i + j] = s2[j];
	while (i-- > 0)
		s3[i] = s1[i];
	return (s3);
}
