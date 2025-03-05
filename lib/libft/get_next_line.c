/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:46:39 by halozdem          #+#    #+#             */
/*   Updated: 2025/03/05 15:46:35 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../cub3d.h"

size_t	ft_strlens(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdups(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc((ft_strlens(src) + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoins(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc((ft_strlens(s1) + ft_strlens(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substrs(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_strchrs(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

char	*read_line(int fd, char *buffer, char *stack)
{
	int		read_byte;
	char	*temp;

	while (1)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (0);
		else if (read_byte == 0)
			break ;
		buffer[read_byte] = '\0';
		if (!stack)
			stack = ft_strdups("");
		temp = stack;
		stack = ft_strjoins(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchrs(buffer, '\n'))
			break ;
	}
	return (stack);
}

char	*clean_stack(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	str = ft_substrs(line, i + 1, ft_strlens(line) - i);
	if (str == NULL)
		return (NULL);
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;
	char		*buffer;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, stack);
	free(buffer);
	if (line == NULL)
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	stack = clean_stack(line);
	return (line);
}