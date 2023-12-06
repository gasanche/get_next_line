/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:36:22 by gabsanch          #+#    #+#             */
/*   Updated: 2023/09/25 20:58:19 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = ((char *)s1)[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = ((char *)s2)[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	new_size;
	size_t	i;

	new_size = count * size;
	mem = malloc(new_size);
	if (!mem)
		return (0);
	i = 0;
	while (i < new_size)
		((char *)mem)[i++] = 0;
	return (mem);
}

char	*clear(char **p1, char **p2)
{
	if (p1 && *p1)
	{
		free (*p1);
		*p1 = NULL;
	}
	if (p2 && *p2)
	{
		free (*p2);
		*p2 = NULL;
	}
	return (NULL);
}
