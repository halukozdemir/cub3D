/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:25:45 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/25 14:59:35 by beyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

char	process_initial_lines(t_main *main, int *fd, char **line)
{
	bool	error;
	char	*str;

	error = false;
	*line = get_next_line(*fd);
	str = ft_strtrim(*line, " ");
	while (*line && *str == '\n')
	{
		free(str);
		if (check_map_error(main, *line, &error))
			return (free(*line), EXIT_FAILURE);
		free(*line);
		*line = get_next_line(*fd);
		str = ft_strtrim(*line, " ");
	}
	free(str);
	if (error)
		return (free(*line), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char	get_map_size(t_main *main, int *fd)
{
	char	*line;
	int		i;
	char	result;

	i = 1;
	result = process_initial_lines(main, fd, &line);
	if (result == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (line)
	{
		process_map_line(main, line, &i);
		free(line);
		line = get_next_line(*fd);
	}
	main->map->map_max_y = i;
	return ((close(*fd)), EXIT_SUCCESS);
}

int	init_and_skip_headers(t_main *main, int *fd, const char *file_name,
	char **line)
{
	*fd = open(file_name, O_RDWR);
	if (*fd < 0 || init_map(main->map) == EXIT_FAILURE)
		return (close(*fd), EXIT_FAILURE);
	*line = get_next_line(*fd);
	skip_identifiers(*fd, line);
	return (EXIT_SUCCESS);
}

int	fill_map_struct(t_main *main, int *fd, const char *file_name)
{
	char	*line;
	int		i;
	int		j;
	int		result;

	result = init_and_skip_headers(main, fd, file_name, &line);
	if (result == EXIT_FAILURE)
		return (EXIT_FAILURE);
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
