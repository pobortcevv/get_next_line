/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <sabra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:37:52 by sabra             #+#    #+#             */
/*   Updated: 2020/11/11 19:30:07 by sabra            ###   ########.fr       */
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

int		get_next_line(int fd, char **line)
{
	char 		*container[1000];
	int 		len;
	int			end;
	char		*buff;
	char		*sub;

	if (ft_strlen(buff) == 0)
		*line = ft_strnew(1);
	while ((len = read(fd, buff, BUFF_SIZE)))
	{
		if ((end = ft_strchr(buff, '\0')))
		{
			sub = ft_substr(buff, 0, end);
			*line = ft_strjoin(*line, sub);
			buff[fd] = ft_substr(buff, end + 1, len - end);
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
	printf("%s", *line);
}