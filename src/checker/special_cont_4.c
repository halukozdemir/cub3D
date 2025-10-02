/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cont_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:23:37 by beyildiz          #+#    #+#             */
/*   Updated: 2025/04/25 12:27:57 by beyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static void	check_color_validity(int color_value, int color_count, int fd)
{
	if (color_value < 0 || color_value > 255 || color_count != 2)
	{
		printf("Error: Invalid color value.\n");
		close(fd);
		exit(1);
	}
}

static void	process_color_character(char buffer_char, int *color_value,
								int *color_count, int fd)
{
	if (ft_isdigit(buffer_char))
	{
		*color_value = *color_value * 10 + (buffer_char - '0');
	}
	else if (buffer_char == ',')
	{
		if (*color_value < 0 || *color_value > 255)
		{
			printf("Error: Invalid color value.\n");
			close(fd);
			exit(1);
		}
		(*color_count)++;
		*color_value = 0;
	}
	else if (!ft_isspace(buffer_char))
	{
		printf("Error: Invalid character in color.\n");
		close(fd);
		exit(1);
	}
}

void	validate_color(char *buffer, int i, int fd)
{
	int	j;
	int	color_value;
	int	color_count;

	color_value = 0;
	color_count = 0;
	j = i + 1;
	while (buffer[j] && ft_isspace(buffer[j]))
		j++;
	while (buffer[j] && buffer[j] != '\n')
	{
		process_color_character(buffer[j], &color_value, &color_count, fd);
		j++;
	}
	check_color_validity(color_value, color_count, fd);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != '1')
		return (0);
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& !ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}
