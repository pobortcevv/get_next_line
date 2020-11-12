/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <sabra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:37:52 by sabra             #+#    #+#             */
/*   Updated: 2020/11/12 18:32:50 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*cont_check(char *container, char *line)
{
	int len;

	if (ft_strlen(container))
	{
		if ((len = ft_strchr(container, '\n')))
		{
			line = ft_strndup(container, len);
			container = ft_substr(container, len + 1, ft_strlen(container));
			return (line);
		}
		line = ft_strndup(container, ft_strlen(container));
		free(container);
	}
	return (line);
}

int		get_next_line(int fd, char **line)
{
	static char 		*container[1001];
	char				*buff;
	int					len;
	int					count;

	//*line = cont_check(container[fd], *line);
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((count = read(fd, buff, BUFF_SIZE)))
	{
		if ((len = ft_strchr(buff, '\n')))
		{
			*line = ft_strndup(buff, len);
			container[fd] = ft_substr(buff, len + 1, BUFF_SIZE);
			printf("%s", container[fd]);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
	}
	if (count == -1)
	{
		free(buff);
		return (-1);
	}
	return (0);
}

int	main(void)
{
	int fd;
	char **line;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, line);
	
	//printf("%s", *line);
	// get_next_line(fd, line);
	// printf("%s", *line);
}