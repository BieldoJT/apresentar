
#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>



int handle_mouse(int button, int x, int y) {
    if (button == 1)
	{
        printf("Clique do mouse na posição (%d, %d)\n", x, y);
    }
    return 0;
}

int main()
{
typedef struct s_serv
{
	void *ptr;
	void *win;

}	t_serv;


    t_serv mlx;

    mlx.ptr = mlx_init();
    mlx.win = mlx_new_window(mlx.ptr, 800, 600, "Exemplo mlx_mouse_hook");

    mlx_mouse_hook(mlx.win, handle_mouse, &mlx);


    mlx_loop(mlx.ptr);

    return 0;
}
