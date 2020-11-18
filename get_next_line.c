/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <sabra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:37:52 by sabra             #+#    #+#             */
/*   Updated: 2020/11/18 20:00:27 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_mod(int fd, char **container)
{
	char	*result;
	int		end_1;
	int 	i;

	end_1 = 0;
	i = 0;
	result = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (container[fd][end_1] != '\n' && container[fd][end_1] != '\0')
	{
		end_1++;
	}
	if (container[fd][end_1] == '\n')
		end_1++;
	while(container[fd][end_1] != '\0')
	{
		result[i] = container[fd][end_1];
		i++;
		end_1++;
	}
	if (container[fd])
		free(container[fd]);
	result[i] = '\0';
	return (result);
}

int		ft_readfile(int fd, char **line, char **container)
{
	int		count;
	char	*mod;
	int		result;

	while ((count = read(fd, container[fd], BUFFER_SIZE)) > 0)
	{
		container[fd][count] = '\0';
		if ((mod = ft_strchr(container[fd], '\n')))
		{
			mod++;
			*line = (!(*line) ? ft_strdup(container[fd]) : ft_strjoin(*line, container[fd]));
			if(!(*line))
				return (-1);
			container[fd] = ft_mod(fd, container);
			return (1);
		}
		*line = ft_strjoin(*line, container[fd]);
	}
	return (count == -1 ? (-1) : 0);
}

int		get_next_line(int fd, char **line)
{
	static char 		*container[1000];
	char				*mod;
	int					result;

	*line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (container[fd])
	{
		if ((mod = ft_strchr(container[fd], '\n')))
		{
			if (!(*line = ft_strdup(container[fd])))
				return (-1);
			mod++;
			container[fd] = ft_mod(fd, container);
			return (1);
		}
		else
		{
			if (!(*line = ft_strdup(container[fd])))
				return (-1);
		}
	}
	else
	{
		container[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	}
	result = ft_readfile(fd, line, container);
	if (result < 1)
	{
		free(container[fd]);
		container[fd] = NULL;
	}
	return (result);
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	
	char *line;
	int i;

	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("i = %d\n%s\n", i, line);
		free(line);
	}
	printf("i = %d\n%s\n", i, line);
	free(line);
	return (0);










// 	// printf("1) %d\n", get_next_line(fd, line));

// 	// printf("%s", *line);
// 	// printf("\n2) %d\n", get_next_line(fd, line));
// 	// printf("%s", *line);
// 	// //get_next_line(fd, line);
// 	// //printf("%s", *line);
// 	// //get_next_line(fd, line);
// 	// // printf("%s\n", *line);
// 	// //get_next_line(fd, line);
}