/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:25:45 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/18 19:44:22 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

char	get_map_size(t_main *main, int *fd, const char *file_name)
{
	char	*line;
	char	*line2;
	int		i;
	bool	error;

	error = false;
	i = 1;
	line = get_next_line(*fd);
	while (line && *ft_strtrim(line, " ") == '\n')
	{
		if (check_map_error(main, line, &error))
			return (free(line), EXIT_FAILURE);
		free(line);
		line = get_next_line(*fd);
	}
	if (error)
		return (free(line), EXIT_FAILURE);
	while (line)
	{
		process_map_line(main, line, &i);
		free(line);
		line = get_next_line(*fd);
	}
	main->map->map_max_y = i;
	return ((close(*fd)), EXIT_SUCCESS);
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
