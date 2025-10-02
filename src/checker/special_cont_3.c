/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cont_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:08:19 by beyildiz          #+#    #+#             */
/*   Updated: 2025/04/25 12:10:08 by beyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static int	check_identifier(char *line, int i, char *identifier, int len)
{
	int	j;

	j = 0;
	while (j < len && line[i + j] == identifier[j])
		j++;
	if (j == len && ft_isspace(line[i + len]))
		return (1);
	return (0);
}

static int	check_single_char_identifier(char *line, int i)
{
	if ((line[i] == 'F' || line[i] == 'C') && ft_isspace(line[i + 1]))
		return (1);
	return (0);
}

static int	check_double_char_identifiers(char *line, int i)
{
	if (check_identifier(line, i, "NO", 2))
		return (1);
	if (check_identifier(line, i, "SO", 2))
		return (1);
	if (check_identifier(line, i, "EA", 2))
		return (1);
	if (check_identifier(line, i, "WE", 2))
		return (1);
	return (0);
}

int	is_texture_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (check_single_char_identifier(line, i))
		return (1);
	if (check_double_char_identifiers(line, i))
		return (1);
	return (0);
}
