/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:25:45 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 20:53:11 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static char	process_initial_lines(t_main *main, int *fd, bool *error,
		char **line)
{
	char	*str;

	*line = get_next_line(*fd);
	if (!*line)
		return (EXIT_SUCCESS);
	str = ft_strtrim(*line, " ");
	while (*line && *str == '\n')
	{
		free(str);
		if (check_map_error(main, *line, error))
			return (free(*line), EXIT_FAILURE);
		free(*line);
		*line = get_next_line(*fd);
		if (*line)
			str = ft_strtrim(*line, " ");
	}
	free(str);
	if (*error)
		return (free(*line), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char	get_map_size(t_main *main, int *fd, const char *file_name)
{
	char	*line;
	int		i;
	bool	error;

	i = 1;
	error = false;
	if (process_initial_lines(main, fd, &error, &line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (line)
	{
		process_map_line(main, line, &i);
		free(line);
		line = get_next_line(*fd);
	}
	main->map->map_max_y = i;
	close(*fd);
	return (EXIT_SUCCESS);
}

int	fill_map_struct(t_main *main, int *fd, const char *file_name)
{
	char	*line;
	int		i;
	int		j;

	*fd = open(file_name, O_RDWR);
	if (*fd < 0 || init_map(main->map) == EXIT_FAILURE)
		return (close(*fd), EXIT_FAILURE);
	line = get_next_line(*fd);
	skip_identifiers(*fd, &line);
	i = 0;
	while (line && i < main->map->map_max_y)
	{
		if (!ft_find_in_str(line, "10NSWE\n "))
			break ;
		j = -1;
		while (line[++j] && line[j] != '\n')
			main->map->map[i + 1][j + 1] = line[j];
		free(line);
		line = get_next_line(*fd);
		i++;
	}
	if (line)
		free(line);
	return (close(*fd), EXIT_SUCCESS);
}
