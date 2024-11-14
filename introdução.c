#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_window
{
	void *ptr;
	void *win;
}	t_window;

int button_press(int keysym, t_window *mlx)
{
	if(keysym == XK_Escape)
	{
		printf("Pressed key: %d\n Closing window.\n", keysym);
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		exit(0);
	}
	printf("Pressed key: %d\n", keysym);
	return 0;
}

int main()
{
	t_window mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr,600,600, "My window");

	mlx_key_hook(mlx.win, button_press, &mlx);
	mlx_loop(mlx.ptr);

}
