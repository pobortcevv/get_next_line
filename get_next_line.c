/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <sabra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:37:52 by sabra             #+#    #+#             */
/*   Updated: 2020/11/12 19:32:31 by sabra            ###   ########.fr       */
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

int		cont_check(char *container, char *line)
{
	int len;

	if (container)
	{
		if ((len = ft_strchr(container, '\n')))
		{
			line = ft_strndup(container, len);
			container = ft_substr(container, len + 1, ft_strlen(container));
			return (len);
		}
		line = ft_strjoin(line, container);
		free(container);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char 		*container[1001];
	char				buff[BUFF_SIZE + 1];
	int					len;
	int					count;

	len = cont_check(container[fd], *line);
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while ((count = read(fd, buff, BUFF_SIZE)))
	{
		buff[count] = '\0';
		if ((len = ft_strchr(buff, '\n')))
		{
			*line = ft_strndup(buff, len);
			container[fd] = ft_substr(buff, len + 1, BUFF_SIZE);
			printf("%s", container[fd]);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
	}
	return (0);
}

int	main(void)
{
	int fd;
	char **line;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, line);
	
	printf("\n%s", *line);
	// get_next_line(fd, line);
	// printf("%s", *line);
}