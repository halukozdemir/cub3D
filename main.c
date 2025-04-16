#include "lib/cub3d.h"

void print_textures(t_textures *textures)
{
    if (!textures) return;

    // keys
    printf("keys: %s\n", textures->keys ? textures->keys : "NULL");

    // texture paths
    printf("NO (North):%s\n", textures->no ? textures->no : "NULL");
    printf("SO (South):%s\n", textures->so ? textures->so : "NULL");
    printf("WE (West):%s\n", textures->we ? textures->we : "NULL");
    printf("EA (East):%s\n", textures->ea ? textures->ea : "NULL");

    // textures array
    printf("Textures array: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", textures->textures[i]);
    }
    printf("\n");

    // colors (c and f)
    if (textures->c)
    {
        printf("c (Ceiling color): ");
        for (int i = 0; textures->c[i]; i++)
        {
            printf("%s ", textures->c[i]);
        }
        printf("\n");
    }
    else
    {
        printf("c (Ceiling color): NULL\n");
    }

    if (textures->f)
    {
        printf("f (Floor color): ");
        for (int i = 0; textures->f[i]; i++)
        {
            printf("%s ", textures->f[i]);
        }
        printf("\n");
    }
    else
    {
        printf("f (Floor color): NULL\n");
    }
}


void	debug_main_info(t_main *main)
{
	printf("=== PLAYER POSITION ===\n");
	printf("Pos:        (x: %.2f, y: %.2f)\n", main->player_pos->x, main->player_pos->y);
	printf("Direction:  (dirx: %.2f, diry: %.2f)\n", main->player_pos->dirx, main->player_pos->diry);
	printf("Plane:      (planex: %.2f, planey: %.2f)\n", main->player_pos->planex, main->player_pos->planey);
	printf("Count:      %d\n", main->player_pos->count);

	printf("\n=== MAP INFO ===\n");
	printf("Max X: %d, Max Y: %d\n", main->map->map_max_x, main->map->map_max_y);
	printf("Map:\n");
	for (int i = 0; main->map->map[i]; i++)
		printf("%s\n", main->map->map[i]);

	printf("\n=== KEYS STATUS ===\n");
	printf("W: %d | S: %d | A: %d | D: %d | Left: %d | Right: %d | ESC: %d\n",
		main->keys.w_pressed, main->keys.s_pressed, main->keys.a_pressed, main->keys.d_pressed,
		main->keys.left_pressed, main->keys.right_pressed, main->keys.esc_pressed);

	printf("\n=== TEXTURE PATHS ===\n");
	printf("NO: %s\n", main->textures->no);
	printf("SO: %s\n", main->textures->so);
	printf("WE: %s\n", main->textures->we);
	printf("EA: %s\n", main->textures->ea);

	printf("\n=== RAY INFO ===\n");
	printf("Camera X: %.2f | RayDir: (%.2f, %.2f)\n", main->ray.camera_x, main->ray.raydir_x, main->ray.raydir_y);
	printf("DeltaDist: (%.2f, %.2f)\n", main->ray.deltadist_x, main->ray.deltadist_y);
	printf("SideDist: (%.2f, %.2f)\n", main->ray.sidedist_x, main->ray.sidedist_y);
	printf("MapPos: (x: %d, y: %d) | Step: (x: %d, y: %d)\n", main->ray.map_x, main->ray.map_y, main->ray.step_x, main->ray.step_y);
	printf("Hit: %d | Side: %d | PerpWallDist: %.2f\n", main->ray.hit, main->ray.side, main->ray.perpwall_dist);
	printf("LineHeight: %d | DrawStart: %d | DrawEnd: %d\n", main->ray.line_height, main->ray.draw_start, main->ray.draw_end);
	printf("TextureX: %d | WallX: %.2f | TextStep: %.2f | TextPos: %.2f\n",
		main->ray.texture_x, main->ray.wall_x, main->ray.textstep, main->ray.textpos);

	printf("\n=== MLX INFO ===\n");
	printf("Window pointer: %p | MLX pointer: %p\n", main->mlx.win, main->mlx.mlx);
	printf("Last tick: %llu\n", main->mlx.last_tick);
	printf("Image Addr: %p | Size Line: %d | Width: %d | Height: %d\n",
		main->mlx.image.addr, main->mlx.image.size_line, main->mlx.image.width, main->mlx.image.height);
}



void print_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    // if (argc != 2)
    //     return (0);
    t_main      *main;
	int			fd;

    main = init_all();
	if (!main->textures)
		return (0);
    fd = fill_textures_struct(main->textures, "maps/map.cub");
    if (fd == -1)
    {
        printf("Invalid map. \n");
        free_all(main);
        return (0);
    }
    if (check_image(main->textures) || check_color(main->textures) || is_any_texture_file_empty(main->textures))
    {
        free_all(main);
        return (0);
    }
	// print_textures(main->textures);//yazdırma fonksiyonu
	if (get_map_size(main, &fd, "maps/map.cub"))
    {
        free_all(main);
        printf("Invalid Map.\n");
		return (0);
    }
    if (fill_map_struct(main, &fd, "maps/map.cub"))
    {
        printf("saddad\n");
        free_all(main);
        return (0);
    }
    // print_map(main->map->map);//yazdırma fonksiyonu
    flood_fill(main);
    flood_fill_2(main); 

    if (!get_player_pos(main))  // 💥 Bunu burada çağır!
    {
        printf("Invalid or multiple player start positions.\n");
        free_all(main);
        return (0);
    }

    // printf("map max x:%d\nmap max y:%d\n", main->map->map_max_x, main->map->map_max_y);
    // printf("dirx:%d\ndiry:%d\n", main->player_pos->dirx, main->player_pos->diry);
    // printf("player pos_x:%d\nplayer pos_y:%d\n", main->player_pos->x, main->player_pos->y);

    // main->map->map = ft_split("111\n101\n101\n101\n101\n101\n101\n101\n101\n101\n101\n101\n101\n101\n101\n101\n101\n101\n1E1\n101\n101\n101\n101\n101\n101\n101\n101\n101\n101\n101\n111", '\n'); 
    // main->map->map_max_x = 2;
    // main->map->map_max_y = 2;
    // main->player_pos->dirx = 0;
    // main->player_pos->diry = 1;
    // main->player_pos->planey = 0;
    // main->player_pos->planex = 0.66;
    // main->player_pos->x = 1 + .5;
    // main->player_pos->y = 1 + .5;

    main->mlx.last_tick = 0;
    // debug_main_info(main);
    if (!init_mlx(main, &main->mlx))
        return (0);
    free_all(main);
}
