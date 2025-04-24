/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:57:12 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 18:20:33 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

char	cf_count_checker(t_textures *textures)
{
	int	count;

	count = 0;
	while (textures->c[count])
		count++;
	if (count != 3)
		return (EXIT_FAILURE);
	count = 0;
	while (textures->f[count])
		count++;
	if (count != 3)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char	**ft_realloc(char **array, char *new_element)
{
	char	**new_array;
	int		size;

	if (!array)
	{
		new_array = ft_calloc(2, sizeof(char *));
		if (!new_array)
			return (NULL);
		new_array[0] = ft_strdup(new_element);
		return (new_array);
	}
	size = 0;
	while (array[size])
		size++;
	new_array = ft_calloc(size + 2, sizeof(char *));
	if (!new_array)
		return (NULL);
	size = 0;
	while (array[size])
	{
		new_array[size] = array[size];
		size++;
	}
	new_array[size] = ft_strdup(new_element);
	return (free(array), new_array);
}

char	ft_is_empty_line(char *line)
{
	while (*line)
	{
		if (!ft_strchr(" \t\n\v\f", *line))
			return (EXIT_FAILURE);
		line++;
	}
	return (EXIT_SUCCESS);
}

int	count_char(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

void	av_check(char *av)
{
	int	fd;
	int	len;

	fd = open(av, O_RDWR);
	if (fd == -1)
	{
		close(fd);
		ft_putstr_fd("Error\nFile can not open.\n", 1);
		exit(1);
	}
	close(fd);
	len = ft_strlen(av);
	if (av[len - 1] != 'b' || av[len - 2] != 'u' || av
		[len - 3] != 'c' || av[len - 4] != '.')
	{
		ft_putstr_fd("Error\nThe file is not '.cub' extension.\n", 1);
		exit(1);
	}
	special_cont(av);
	check_textures_in_map(av);
}
