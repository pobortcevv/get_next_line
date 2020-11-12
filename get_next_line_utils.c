/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <sabra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:36:59 by sabra             #+#    #+#             */
/*   Updated: 2020/11/12 17:48:14 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(char *src, int index)
{
	char	*dest;
	int 	i;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (i != index)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	char	*string;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(1);
		substr[0] = '\0';
		return (substr);
	}
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	string = (char *)s;
	i = 0;
	while (len-- && string[start])
	{
		substr[i] = string[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

int		ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*str;

	str = (char *)s;
	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == (char)c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		end_1;
	int		i;

	if (!s1)
		return ((char *)s2);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	end_1 = 0;
	i = 0;
	while (s1[end_1])
	{
		result[end_1] = s1[end_1];
		end_1++;
	}
	while (s2[i])
	{
		result[end_1] = s2[i];
		i++;
		end_1++;
	}
	result[end_1] = '\0';
	return (result);
}