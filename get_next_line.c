/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:45:22 by gabsanch          #+#    #+#             */
/*   Updated: 2023/09/25 20:57:41 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i += (str[i] == '\n');
	line = ft_calloc(sizeof(char), i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*safe_join(char *buff, char *rd)
{
	char	*new;

	new = ft_strjoin(buff, rd);
	if (!new)
		return (clear(&buff, &rd));
	clear (&buff, NULL);
	return (new);
}

char	*read_fd(int fd, char *buff, int whiskers)
{
	char	*tmp;

	tmp = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!tmp)
		return (clear(&buff, NULL));
	while (whiskers > 0)
	{
		whiskers = read(fd, tmp, BUFFER_SIZE);
		if (whiskers < 0)
			return (clear(&buff, &tmp));
		tmp[whiskers] = '\0';
		buff = safe_join(buff, tmp);
		if (!buff)
			return (NULL);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	clear(&tmp, NULL);
	return (buff);
}

char	*new_buff(char *buff)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (buff[j] && buff[j] != '\n')
		j++;
	if (!buff[j])
		return (clear(&buff, NULL));
	tmp = ft_calloc(ft_strlen(buff) - j + 1, 1);
	if (!tmp)
		return (clear(&buff, NULL));
	if (buff[j] == '\n')
		j++;
	i = 0;
	while (buff[j])
		tmp[i++] = buff[j++];
	clear(&buff, NULL);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
		buff = ft_calloc(1, 1);
	if (!buff)
		return (NULL);
	buff = read_fd(fd, buff, 1);
	if (!buff)
		return (NULL);
	line = ft_get_line(buff);
	if (!line || line[0] == '\0')
		return (clear(&buff, &line));
	buff = new_buff(buff);
	return (line);
}
