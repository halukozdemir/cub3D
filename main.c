/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:42:14 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 19:59:49 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/cub3d.h"

static int	handle_textures(t_main *main, char *path)
{
	int	fd;

	if (!main->textures)
		return (1);
	fd = fill_textures_struct(main->textures, path);
	if (fd == -1)
	{
		printf("Error: Invalid map.\n");
		free_all(main);
		return (1);
	}
	if (check_image(main->textures) || check_color(main->textures)
		|| is_any_texture_file_empty(main->textures))
	{
		printf("Error: Texture check failed.\n");
		free_all(main);
		return (1);
	}
	return (fd);
}

static int	handle_map(t_main *main, int *fd, char *path)
{
	if (get_map_size(main, fd))
	{
		free_all(main);
		main = NULL;
		printf("Error: Invalid map.\n");
		return (1);
	}
	if (fill_map_struct(main, fd, path))
	{
		free_all(main);
		main = NULL;
		return (1);
	}
	flood_fill(main);
	flood_fill_2(main);
	if (!get_player_pos(main))
	{
		printf("Error: Invalid map.\n");
		free_all(main);
		main = NULL;
		exit(1);
	}
	return (0);
}

static int	handle_errors(t_main *main, int exit_code)
{
	if (exit_code == 1)
		free_all(main);
	return (exit_code);
}

static int	initialize_and_check(t_main **main)
{
	*main = init_all();
	if (!*main)
	{
		ft_putstr_fd("Initialization failed\n", 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	*main;
	int		fd;
	int		exit_code;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./cub3D <map_file>\n", 1);
		return (1);
	}
	av_check(argv[1]);
	exit_code = initialize_and_check(&main);
	if (exit_code)
		return (handle_errors(main, exit_code));
	fd = handle_textures(main, argv[1]);
	if (fd == 1)
		return (handle_errors(main, 1));
	if (handle_map(main, &fd, argv[1]))
		return (handle_errors(main, 1));
	main->mlx.last_tick = 0;
	if (!init_mlx(main, &main->mlx))
		return (handle_errors(main, 1));
	return (0);
}
