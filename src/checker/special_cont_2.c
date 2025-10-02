/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cont_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:39:57 by beyildiz          #+#    #+#             */
/*   Updated: 2025/04/25 11:47:27 by beyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void	validate_map_character(char character, int map_section_started, int fd)
{
	if (map_section_started)
	{
		if (character == '\n' || ft_isspace(character))
			return ;
		if (character != '0' && character != '1'
			&& character != 'N' && character != 'S'
			&& character != 'E' && character != 'W')
		{
			printf("Error: Invalid character in map.\n");
			close(fd);
			exit(1);
		}
	}
}

int	check_map_section_start(char *buffer, int i)
{
	int	j;
	int	wall_count;

	if (buffer[i] == '1')
	{
		wall_count = 0;
		j = i;
		while (buffer[j] && buffer[j] != '\n')
		{
			if (buffer[j] == '1')
				wall_count++;
			j++;
		}
		if (wall_count > 3)
			return (1);
	}
	return (0);
}

void	handle_texture_line(char *line, char *buffer, int line_start, int fd)
{
	int	k;

	k = 0;
	while (line[k] && ft_isspace(line[k]))
		k++;
	if (line[k] == 'F' || line[k] == 'C')
		validate_color(buffer, line_start + k, fd);
}

void	print_error_and_exit(char *message, int fd)
{
	printf("%s\n", message);
	close(fd);
	exit(1);
}
