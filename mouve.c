#include "solong.h"

void 	position(char **rest, t_vars *size)
{
	int x;
	int y;
	
	x = 0;
	while (rest[x])
	{
		y = 0;
		while (rest[x][y])
		{
			if (rest[x][y] == 'P')
			{
				size->x_p = x;
				size->y_p = y;
			}
			y++;
		}
		x++;
	}
}

void	mouvea(t_vars *image)
{
	if(image->map[image->x_p][image->y_p - 1] == 'C')
		image->c--;
	if(image->map[image->x_p][image->y_p - 1] == '0' || image->map[image->x_p][image->y_p - 1] == 'C')
	{
		image->map[image->x_p][image->y_p - 1] = 'P';
		image->map[image->x_p][image->y_p] = '0';
		image->count++;
		// randre(image->map, image, image->lisr);
	}
	else if(image->map[image->x_p][image->y_p - 1] == 'E' && image->c == 0)
	{
		image->count++;
		
		mlx_clear_window(image->mlx_ptr, image->win_ptr);
		exit(0);
	}
}
void	mouves(t_vars *image)
{
	if (image->map[image->x_p + 1][image->y_p] == 'C')
		image->c--;
	if (image->map[image->x_p + 1][image->y_p] == '0' || image->map[image->x_p + 1][image->y_p] == 'C')
	{
		image->map[image->x_p + 1][image->y_p] = 'P';
		image->map[image->x_p][image->y_p] = '0';
		image->count++;
		// randre(image->map, image, image->lte7t);
	}
	else if(image->map[image->x_p + 1][image->y_p] == 'E' && image->c == 0)
	{
		image->count++;
		mlx_clear_window(image->mlx_ptr, image->win_ptr);
		exit(0);
	}
}
void	mouvew(t_vars *image)
{
	if(image->map[image->x_p - 1][image->y_p] == 'C')
		image->c--;
	if(image->map[image->x_p - 1][image->y_p] == '0' || image->map[image->x_p - 1][image->y_p] == 'C')
	{
		image->map[image->x_p - 1][image->y_p] = 'P';
		image->map[image->x_p][image->y_p] = '0';
		image->count++;
		// randre(image->map, image, image->lfo9);
	}
	else if(image->map[image->x_p - 1][image->y_p] == 'E' && image->c == 0)
	{
		image->count++;
		mlx_clear_window(image->mlx_ptr, image->win_ptr);
		exit(0);
	}
}

void	mouved(t_vars *image)
{
	if (image->map[image->x_p][image->y_p + 1] == 'C')
		image->c--;
	if (image->map[image->x_p][image->y_p + 1] == '0' || image->map[image->x_p][image->y_p + 1] == 'C')
	{
		image->map[image->x_p][image->y_p + 1] = 'P';
		image->map[image->x_p][image->y_p] = '0';
		image->count++;
		// randre(image->map, image, image->limn);
	}
	else if(image->map[image->x_p][image->y_p + 1] == 'E' && image->c == 0)
	{
		image->count++;
		mlx_clear_window(image->mlx_ptr, image->win_ptr);
		exit(0);
	}
}

// int	handle_key_event(int keycode, t_vars *image)
// {
// 	position(image->map, image);
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(image->mlx_ptr, image->win_ptr);
// 		exit(0);
// 	}
// 	else if (keycode == 123)
// 		mouvea(image);
// 	else if (keycode == 125)
// 		mouves(image);
// 	else if (keycode == 124)
// 		mouved(image);
// 	else if (keycode == 126)
// 		mouvew(image);
// 	mlx_clear_window(image->mlx_ptr, image->win_ptr);
// 	randre(image->map, image, image->limn);
// 	return 0;
// }