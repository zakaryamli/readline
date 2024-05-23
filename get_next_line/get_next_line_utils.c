/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyamli <zakariayamli00@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:02:40 by zyamli            #+#    #+#             */
/*   Updated: 2023/12/05 15:28:08 by zyamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *result, char c)
{
	int	i;

	i = 0;
	while (result[i] != '\0')
	{
		if (result[i] == c)
			return (&result[i]);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
		return (free(s1), s1 = NULL, NULL);
	ft_memmove(result, s1, s1_len);
	ft_memmove(result + s1_len, s2, s2_len + 1);
	return (free(s1), s1 = NULL, result);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
