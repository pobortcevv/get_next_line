/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <sabra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:36:59 by sabra             #+#    #+#             */
/*   Updated: 2020/11/17 15:13:36 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strrchr(char *str, int c)
{
	int		i;
	int		last_index;
	size_t	len;

	last_index = -1;
	i = 0;
	len = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			last_index = i;
		}
		i++;
	}
	if (last_index != -1)
		return (&str[last_index]);
	else if ((char)c == str[len])
		return (&str[len]);
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*str;

	str = (char *)s;
	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == (char)c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		end_1;
	int		i;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	end_1 = 0;
	i = 0;
	while (s1[end_1])
	{
		result[end_1] = s1[end_1];
		end_1++;
	}
	while (s2[i] != '\n' && s2[i] != '\0')
	{
		result[end_1] = s2[i];
		i++;
		end_1++;
	}
	result[end_1] = '\0';
	return (result);
}