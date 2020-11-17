/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <sabra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:37:52 by sabra             #+#    #+#             */
/*   Updated: 2020/11/17 15:38:01 by sabra            ###   ########.fr       */
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

char	*cont_check(char *container, char *line)
{
	char	*mod;

	if (container)
	{
		//printf("%s", container);
		if ((mod = ft_strchr(container, '\n')))
		{
			line = ft_strjoin(line, container);
			mod++;
			//printf("%s", line);
			//printf("%s", mod);
			container = mod;
			//printf("%s", container);
			return (line);
		}
		line = ft_strjoin(line, container);
		container = NULL;
	}
	return (line);
}

int		get_next_line(int fd, char **line)
{
	static char 		*container[1000];
	char				*mod;
	int					count;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	*line = cont_check(container[fd], *line);
	if (*line != NULL && container[fd] != NULL)
		return (1);
	if (container[fd] == NULL)
		container[fd] = malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((count = read(fd, container[fd], BUFF_SIZE)))
	{
		container[fd][count] = '\0';
		if ((mod = ft_strchr(container[fd], '\n')))
		{
			mod++;
			//printf("%s", mod);
			*line = ft_strjoin(*line, container[fd]);
			container[fd] = mod;
			//printf("%s", container[fd]);
			return (1);
		}
		*line = ft_strjoin(*line, container[fd]);
	}
	return (count == -1 ? (-1) : 0);
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	
	char *line[1000];
	// int i;

	// while ((i = get_next_line(fd, &line)))
	// {
	// 	printf("i = %d\n%s\n", i, line);
	// 	//free(line);
	// }
	// printf("i = %d\n%s\n", i, line);
	// //free(line);
	// return (0);










	get_next_line(fd, line);

	printf("%s", *line);
	get_next_line(fd, line);
	printf("%s", *line);
	get_next_line(fd, line);
	printf("%s", *line);
	//get_next_line(fd, line);
	// printf("%s\n", *line);
	//get_next_line(fd, line);
}