/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:49:18 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/16 15:58:42 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static void	f_fill(t_map *map, int y, int x);
static void	flf_check(t_main *main);
static void	copy_row(char *dest, char *src);

void	player_pos(t_main *main)
{
	int	i;
	int	j;

	i = -1;
	main->player_pos->count = 0;
	while (main->map->map[++i])
	{
		j = -1;
		while (main->map->map[i][++j])
		{
			if (ft_strchr("NSEW", main->map->map[i][j]))
			{
				main->player_pos->x = j;
				main->player_pos->y = i;
				main->player_pos->count++;
			}
		}
	}
}

void	flood_fill(t_main *game)
{
	game->map->copy_map = ft_map_dup(game->map->map);
	player_pos(game);
	f_fill(game->map, game->player_pos->y, game->player_pos->x);
	flf_check(game);
	free_copy_map(game->map);
}

static void	f_fill(t_map *map, int y, int x)
{
	if (y < 0 || x < 0 || y >= map->map_max_y + 2 || x >= map->map_max_x + 2)
		return ;
	if (map->copy_map[y][x] == 'F' || map->copy_map[y][x] == ' '
		|| map->copy_map[y][x] == 'B')
		return ;
	map->copy_map[y][x] = 'F';
	f_fill(map, y - 1, x);
	f_fill(map, y + 1, x);
	f_fill(map, y, x - 1);
	f_fill(map, y, x + 1);
}

static void	check_map_error(t_main *main, int i, int j)
{
	if (ft_strchr("10", main->map->copy_map[i][j])
		|| main->player_pos->count > 1)
	{
		printf("Error: Invalid map.\n");
		free_copy_map(main->map);
		free_all(main);
		exit(1);
	}
}

static void	flf_check(t_main *main)
{
	int	i;
	int	j;

	i = -1;
	while (main->map->copy_map[++i])
	{
		j = -1;
		while (main->map->copy_map[i][++j])
			check_map_error(main, i, j);
	}
}

static void	copy_row(char *dest, char *src)
{
	int	j;

	j = -1;
	while (src[++j])
		dest[j] = src[j];
	dest[j] = '\0';
}

char	**ft_map_dup(char **src)
{
	char	**dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (src[++i])
	{
		dest[i] = (char *)malloc(sizeof(char) * (ft_strlen(src[i]) + 1));
		if (!dest[i])
			return (NULL);
		copy_row(dest[i], src[i]);
	}
	dest[i] = NULL;
	return (dest);
}
