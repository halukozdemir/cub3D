/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cont.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:28:12 by beyildiz          #+#    #+#             */
/*   Updated: 2025/04/25 12:28:12 by beyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	validate_line(char *line, int *map_section_started,
					int *texture_ended)
{
	if (is_map_line(line))
	{
		*texture_ended = 1;
		*map_section_started = 1;
	}
	else if (!is_empty_line(line) && *texture_ended
		&& !(*map_section_started))
	{
		printf("Error: Invalid character in map.\n");
		exit(1);
	}
	else if (!is_empty_line(line) && !is_texture_line(line)
		&& !(*map_section_started))
	{
		printf("Error: Invalid character in map.\n");
		exit(1);
	}
}

void	check_map_characters(char *buffer, int line_start,
						int map_section_started, int fd)
{
	int	k;

	if (map_section_started)
	{
		k = line_start;
		while (buffer[k] && buffer[k] != '\n')
		{
			validate_map_character(buffer[k], map_section_started, fd);
			k++;
		}
	}
}

void	process_buffer(char *buffer, int *map_section_started, int fd)
{
	int		i;
	int		texture_ended;
	int		line_start;
	int		j;
	char	line[1024];

	i = 0;
	texture_ended = 0;
	while (buffer[i])
	{
		line_start = i;
		j = 0;
		while (buffer[i] && buffer[i] != '\n')
			line[j++] = buffer[i++];
		line[j] = '\0';
		if (buffer[i] == '\n')
			i++;
		if (is_texture_line(line))
			handle_texture_line(line, buffer, line_start, fd);
		else
			validate_line(line, map_section_started, &texture_ended);
		check_map_characters(buffer, line_start, *map_section_started, fd);
	}
}

void	special_cont(const char *file_name)
{
	int		fd;
	char	buffer[1024];
	int		bytes_read;
	int		map_section_started;

	map_section_started = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		process_buffer(buffer, &map_section_started, fd);
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	close(fd);
}
