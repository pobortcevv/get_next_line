/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <sabra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:37:52 by sabra             #+#    #+#             */
/*   Updated: 2020/11/14 00:21:15 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

char		*cont_check(char *container, char *line)
{
	int		len;
	char	*buff;

	if (container)
	{
		buff = container;
		if ((len = ft_strchr(container, '\n')))
		{
			container = ft_substr(buff, len, ft_strlen(buff));
			buff = ft_substr(buff, 0, len);
			line = ft_strjoin(line, buff);
			return (line);
		}
		line = ft_strjoin(line, container);
		free(container);
	}
	return (line);
}

int		get_next_line(int fd, char **line)
{
	static char 		*container[1000];
	char				*buff;
	int					len;
	int					count;

	*line = cont_check(container[fd], *line);
	// else
	// 	read(fd, buff, len);
	buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while ((count = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[count] = '\0';
		if ((len = ft_strchr(buff, '\n')) != -1)
		{
			container[fd] = ft_substr(buff, len + 1, BUFF_SIZE);
			buff = ft_substr(buff, 0, len);
			*line = ft_strjoin(*line, buff);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
	}
	//free(buff);
	return (0);
}

int	main(void)
{
	int fd;
	char *line[100000];

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, line);
	
	printf("%s\n", *line);
	get_next_line(fd, line);
	printf("%s\n", *line);
	get_next_line(fd, line);
	printf("%s\n", *line);
}