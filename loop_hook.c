#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_data {
    void *mlx;
    void *window;
    int x;
} t_data;

int update(t_data *data) {

    mlx_clear_window(data->mlx, data->window);


    int color = 0x00FF00;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            mlx_pixel_put(data->mlx, data->window, data->x + i, 200 + j, color);
        }
    }

    data->x += 5;
    if (data->x > 800) data->x = 0;

    return 0;
}

int main() {
    t_data data;

    data.mlx = mlx_init();
    data.window = mlx_new_window(data.mlx, 800, 600, "Exemplo mlx_loop_hook");
    data.x = 0;

    mlx_loop_hook(data.mlx, update, &data);


    mlx_loop(data.mlx);

    return 0;
}
