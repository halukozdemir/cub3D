/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:26:48 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/25 14:52:10 by beyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static int	assign_texture_content(t_line_parse *p, char *content, int idx)
{
	if (idx == 0)
		p->textures->no = content;
	else if (idx == 1)
		p->textures->so = content;
	else if (idx == 2)
		p->textures->we = content;
	else if (idx == 3)
		p->textures->ea = content;
	return (1);
}

static int	handle_texture(t_line_parse *p, char *prefix, int idx)
{
	char	*content;
	int		prefix_len;
	int		start_pos;
	char	*str;

	prefix_len = ft_strlen(prefix) - 1;
	if (!ft_strncmp(p->line, prefix, prefix_len) && !p->textures->textures[idx])
	{
		start_pos = p->index + prefix_len;
		while (p->line[start_pos] && ft_isspace(p->line[start_pos]))
			start_pos++;
		str = ft_strdup(p->line + start_pos);
		p->textures->textures[idx] = 1;
		content = ft_strtrim(str, " \n");
		free(str);
		return (assign_texture_content(p, content, idx));
	}
	return (0);
}

static int	handle_color(t_line_parse *p, char *prefix, int idx)
{
	int	prefix_len;
	int	start_pos;

	prefix_len = ft_strlen(prefix) - 1;
	if (!ft_strncmp(p->line, prefix, prefix_len)
		&& !p->textures->textures[idx] && count_char(p->line, ',') == 2)
	{
		start_pos = p->index + prefix_len;
		while (p->line[start_pos] && ft_isspace(p->line[start_pos]))
			start_pos++;
		p->textures->textures[idx] = 1;
		if (idx == 4)
			p->textures->c = ft_split(p->line + start_pos, ',');
		else if (idx == 5)
			p->textures->f = ft_split(p->line + start_pos, ',');
		return (1);
	}
	return (0);
}

int	process_texture_lines(t_line_parse *p)
{
	if (handle_texture(p, "NO ", 0))
		return (1);
	if (handle_texture(p, "SO ", 1))
		return (1);
	if (handle_texture(p, "WE ", 2))
		return (1);
	if (handle_texture(p, "EA ", 3))
		return (1);
	if (handle_color(p, "C ", 4))
		return (1);
	if (handle_color(p, "F ", 5))
		return (1);
	return (0);
}
