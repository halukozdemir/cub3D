/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:46:39 by halozdem          #+#    #+#             */
/*   Updated: 2025/02/24 17:54:32 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../cub3d.h"
int	ft_strlens(const char *str)
{
	if (str == NULL)
		return (0);
	if (*str == 0)
		return (0);
	return (1 + ft_strlen(str + 1));
}

int	ft_linesize(const char *str)
{
	if (str == NULL)
		return (0);
	if (*str == 0 || *str == '\n')
		return (0);
	return (1 + ft_linesize(str + 1));
}

char	*ft_strchrs(const char *s, int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	if (s == NULL)
		return (NULL);
	if (*s == 0)
		return (NULL);
	if (*s == chr)
		return ((char *)s);
	return (ft_strchrs((s + 1), c));
}

char	*ft_strjoins(char *s1, const char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	s1_len = ft_strlens(s1);
	s2_len = ft_strlens(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (free(s1), NULL);
	str[s1_len + s2_len] = '\0';
	while (s2_len--)
		str[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
		str[s1_len] = s1[s1_len];
	return (free(s1), str);
}

char	*ft_substrs(char *s, int start, int len)
{
	char	*substr;
	int		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlens(s);
	if (s_len < start)
		return (NULL);
	if (s_len < len + start)
		len = s_len - start;
	substr = (char *)malloc((sizeof(char) * len + 1));
	if (!substr)
		return (free(s), NULL);
	substr[len] = '\0';
	while (len--)
		substr[len] = s[start + len];
	return (free(s), substr);
}

int	set_initial_fdata(char **data)
{
	*data = (char *) malloc(sizeof(char));
	if (*data)
		**data = '\0';
	return (*data != 0);
}

void	swap_str_and_free(char **str, char *newStr)
{
	free(*str);
	*str = newStr;
}

char	*free_fdata(char	**fdata)
{
	if (*fdata)
	{
		free(*fdata);
		*fdata = 0;
	}
	return (0);
}

char	*get_line(char *file_data)
{
	size_t	len;

	len = 0;
	while (file_data[len])
		if (file_data[len++] == '\n')
			break ;
	return (ft_substr(file_data, 0, len));
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	static char	*file_data;

	if (fd < 0 || (!file_data && !set_initial_fdata(&file_data)))
		return (0);
	while (file_data && !ft_strchr(file_data, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0 || bytes_read == -1)
			break ;
		buffer[bytes_read] = '\0';
		swap_str_and_free(&file_data, ft_strjoin(file_data, buffer));
	}
	if (!file_data || !*file_data || bytes_read == -1)
		return (free_fdata(&file_data));
	line = get_line(file_data);
	if (!line)
		return (free_fdata(&file_data));
	swap_str_and_free(&file_data, \
	ft_substr(file_data, ft_strlen(line), \
	ft_strlen(file_data) - ft_strlen(line)));
	if (!file_data || !*file_data)
	{
		free(file_data);
		file_data = NULL;
	}
	return (line);
}