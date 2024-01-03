/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:20:07 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/03 19:20:32 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	position(char **rest, t_vars *size)
{
	int	x;
	int	y;

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
	if (image->map[image->x_p][image->y_p - 1] == 'C')
		image->c--;
	if (image->map[image->x_p][image->y_p - 1] == '0'
		|| image->map[image->x_p][image->y_p - 1] == 'C')
	{
		image->map[image->x_p][image->y_p - 1] = 'P';
		image->map[image->x_p][image->y_p] = '0';
		image->count++;
		printf("moves : %d\n", image->count);
	}
	else if(image->map[image->x_p][image->y_p - 1] == 'E' && image->c == 0)
	{
		image->count++;
		printf("moves : %d\n", image->count);
		mlx_clear_window(image->mlx_ptr, image->win_ptr);
		exit(0);
	}
}

void	mouves(t_vars *image)
{
	if (image->map[image->x_p + 1][image->y_p] == 'C')
		image->c--;
	if (image->map[image->x_p + 1][image->y_p] == '0'
		|| image->map[image->x_p + 1][image->y_p] == 'C')
	{
		image->map[image->x_p + 1][image->y_p] = 'P';
		image->map[image->x_p][image->y_p] = '0';
		image->count++;
		printf("moves : %d\n", image->count);
	}
	else if(image->map[image->x_p + 1][image->y_p] == 'E' && image->c == 0)
	{
		image->count++;
		printf("moves : %d\n", image->count);
		mlx_clear_window(image->mlx_ptr, image->win_ptr);
		exit(0);
	}
}

void	mouvew(t_vars *image)
{
	if (image->map[image->x_p - 1][image->y_p] == 'C')
		image->c--;
	if (image->map[image->x_p - 1][image->y_p] == '0'
		|| image->map[image->x_p - 1][image->y_p] == 'C')
	{
		image->map[image->x_p - 1][image->y_p] = 'P';
		image->map[image->x_p][image->y_p] = '0';
		image->count++;
		printf("moves : %d\n", image->count);
	}
	else if (image->map[image->x_p - 1][image->y_p] == 'E' && image->c == 0)
	{
		image->count++;
		printf("moves : %d\n", image->count);
		mlx_clear_window(image->mlx_ptr, image->win_ptr);
		exit(0);
	}
}

void	mouved(t_vars *image)
{
	if (image->map[image->x_p][image->y_p + 1] == 'C')
		image->c--;
	if (image->map[image->x_p][image->y_p + 1] == '0'
		|| image->map[image->x_p][image->y_p + 1] == 'C')
	{
		image->map[image->x_p][image->y_p + 1] = 'P';
		image->map[image->x_p][image->y_p] = '0';
		image->count++;
		printf("moves : %d\n", image->count);
	}
	if (image->map[image->x_p][image->y_p + 1] == 'E' && image->c == 0)
	{
		image->count++;
		printf("moves : %d\n", image->count);
		mlx_destroy_image(image->mlx_ptr, image->win_ptr);
		mlx_clear_window(image->mlx_ptr, image->win_ptr);
		exit(0);
	}
}
