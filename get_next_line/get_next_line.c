/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyamli <zakariayamli00@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:05:38 by zyamli            #+#    #+#             */
/*   Updated: 2024/01/26 13:32:40 by zyamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_f(int fd, char	*rest)
{
	char	*tmp;
	int		count;

	tmp = malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!tmp)
		return (free(rest), rest = NULL, NULL);
	count = 1;
	while (count > 0 && ft_strchr(rest, '\n') == 0)
	{
		count = read(fd, tmp, BUFFER_SIZE);
		if (count == -1)
			return (free(rest), free(tmp), NULL);
		tmp[count] = '\0';
		rest = ft_strjoin(rest, tmp);
		if (!rest)
			break ;
	}
	return (free(tmp), rest);
}

static char	*edit_line(char *rest)
{
	char	*result;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (rest[len] != '\n' && rest[len] != '\0')
		len++;
	if (rest[len] == '\n')
		len++;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = rest[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*save_rest(char *rest)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (rest[len] != '\n' && rest[len] != '\0')
		len++;
	if (rest[len] == '\n')
		len++;
	str = malloc(((ft_strlen(rest + len)) + 1) * sizeof(char));
	if (!str)
		return (free(rest), rest = NULL, NULL);
	while (rest[len] != '\0')
		str[i++] = rest[len++];
	str[i] = '\0';
	return (free(rest), rest = NULL, str);
}

char	*get_next_line(int fd)
{
	static char	*saved_str;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (!saved_str)
		saved_str = ft_strdup("");
	if (!saved_str)
		return (NULL);
	saved_str = read_f(fd, saved_str);
	if (!saved_str)
		return (NULL);
	if (saved_str[0] == '\0')
		return (free(saved_str), saved_str = NULL, NULL);
	result = edit_line(saved_str);
	if (!result)
		return (free(saved_str), saved_str = NULL, NULL);
	saved_str = save_rest(saved_str);
	return (result);
}
#include<stdio.h>
#include <fcntl.h>
int main ()
{
	// char *line;
	int fd;
	int flags = O_RDWR | O_CREAT;
	for (int i = 0; i < 20; i++)
	{
		fd = open("file", flags, 0755);
		printf("fd , %d\n", fd);
		close(fd);
	}
	// while(line)
	// {
	// 	line = get_next_line(0);
	// 	printf("%s", line);
	// }
	sleep(100);
}
