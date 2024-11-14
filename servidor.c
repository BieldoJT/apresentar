#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct servers
{
	void *serv;
	void *win1;
	void *win2;
}	t_serv;


int main()
{

	t_serv serv1;
	t_serv serv2;
	t_serv serv3;

	serv1.serv = mlx_init();
	serv2.serv = mlx_init();
	serv3.serv = mlx_init();

	serv1.win1 = mlx_new_window(serv1.serv,400,200, "win 1 ,serv 1");
	serv1.win2 = mlx_new_window(serv1.serv,400,200, "win 2 ,serv 1");
	serv2.win1 = mlx_new_window(serv2.serv,400,200, "win 1 ,serv 2");
	serv2.win2 = mlx_new_window(serv2.serv,400,200, "win 2 ,serv 2");
	serv3.win1 = mlx_new_window(serv3.serv,440,200, "win 1 ,serv 3");

	mlx_loop(serv1.serv);
	mlx_loop(serv2.serv);
	mlx_loop(serv3.serv);

}
