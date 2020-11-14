/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <sabra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:37:52 by sabra             #+#    #+#             */
/*   Updated: 2020/11/14 21:44:04 by sabra            ###   ########.fr       */
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
			container = ft_substr(buff, len + 1, ft_strlen(buff));
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
			container[fd] = ft_substr(buff, len + 1, count);
			buff = ft_substr(buff, 0, len);
			//printf("\n\n!!%s!!\n\n", container[fd]);
			*line = ft_strjoin(*line, buff);
			free(buff);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
	}
	free(buff);
	return (0);
}

// int	main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
	
// 	char *line;
// 	int i;

// 	while ((i = get_next_line(fd, &line)))
// 	{
// 		printf("i = %d\n%s\n", i, line);
// 		//free(line);
// 	}
// 	printf("i = %d\n%s\n", i, line);
// 	//free(line);
// 	return (0);
	









// 	// get_next_line(fd, line);

// 	// printf("%s\n", *line);
// 	// get_next_line(fd, line);
// 	// printf("%s\n", *line);
// 	// get_next_line(fd, line);
// 	// printf("%s\n", *line);
// 	// get_next_line(fd, line);
// 	// printf("%s\n", *line);
// }