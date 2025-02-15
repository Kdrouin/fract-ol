#include "minilibx/mlx.h"
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Fract-ol"

typedef struct s_data {
	void    *mlx_ptr;
	void    *win_ptr;
}              t_data;

int close_window(int keycode, t_data *data)
{
	if (keycode == 65307) // Escape key code
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	return (0);
}

int main(void)
{
	t_data  data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (data.win_ptr == NULL)
	{
		free(data.mlx_ptr);
		return (1);
	}
	mlx_key_hook(data.win_ptr, close_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}