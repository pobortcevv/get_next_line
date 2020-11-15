/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <sabra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:37:52 by sabra             #+#    #+#             */
/*   Updated: 2020/11/15 10:56:23 by sabra            ###   ########.fr       */
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
	char	*len;

	if (container)
	{
		if ((len = ft_strchr(container, '\n')))
		{
			line = ft_strjoin(line, container);
			len++;
			container = ft_strjoin(container, len);
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
	char				*len;
	int					count;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	*line = cont_check(container[fd], *line);
	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((count = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[count] = '\0';
		if ((len = ft_strchr(buff, '\n')))
		{
			len++;
			container[fd] = ft_strjoin(container[fd], len);
			*line = ft_strjoin(*line, buff);
			free(buff);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
	}
	free(buff);
	return (0);
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	
	char *line;
	int i;

	while ((i = get_next_line(fd, &line)))
	{
		printf("i = %d\n%s\n", i, line);
		//free(line);
	}
	printf("i = %d\n%s\n", i, line);
	//free(line);
	return (0);
}









// 	get_next_line(fd, line);

// 	printf("%s\n", *line);
// 	get_next_line(fd, line);
// 	printf("%s\n", *line);
// 	get_next_line(fd, line);
// 	printf("%s\n", *line);
// 	get_next_line(fd, line);
// 	printf("%s\n", *line);
// }