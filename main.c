#include "lib/cub3d.h"

int main()
{
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, HEIGHT, WIDTH, "Hello World!");
    mlx_loop(mlx);
}
