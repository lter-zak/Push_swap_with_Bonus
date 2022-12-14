/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:32:47 by syeghiaz          #+#    #+#             */
/*   Updated: 2022/11/05 14:04:10 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (s1 == 0)
		return (0);
	dest = malloc(ft_strlen1(s1) + 1);
	if (dest == NULL)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (c < 0 || c > 127)
		return ((char *)s);
	while (s[i] || c == 0)
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == 0 && s2 == 0)
		return (0);
	dest = malloc(ft_strlen1(s1) + ft_strlen1(s2) + 1);
	if (!dest)
		return (0);
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = 0;
	if (*s1)
		free(s1);
	return (dest);
}

char	*ft_substr(char	*s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!*s || !s)
		return (NULL);
	i = ft_strlen1(s);
	j = 0;
	if (start < i)
		j = i - start;
	if (j > len)
		j = len;
	substr = (char *)malloc(sizeof(char) * (j + 1));
	if (!substr)
		return (0);
	i = 0;
	while (s[start] && i < j)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
