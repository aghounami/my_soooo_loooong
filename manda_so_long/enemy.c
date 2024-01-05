/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:38:11 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/04 15:28:29 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	left(t_vars *image)
{
	image->map[image->x_n][image->y_n - 1] = 'N';
	image->map[image->x_n][image->y_n] = '0';
	randre(image->map, image);
}

void	right(t_vars *image)
{
	image->map[image->x_n][image->y_n + 1] = 'N';
	image->map[image->x_n][image->y_n] = '0';
	randre(image->map, image);
}

int	mouven(t_vars *image)
{
	static int	count = 2000;
	static int	go_back = 0;

	posn(image);
	count--;
	if (count != 0)
		return (0);
	count = 2000;
	if (image->map[image->x_n][image->y_n - 1] == 'P' |
		image->map[image->x_n][image->y_n + 1] == 'P')
	{
		ft_printf("you loooost😞\n");
		closegame(image);
	}
	if (image->map[image->x_n][image->y_n - 1] == '0' && go_back == 0)
		left(image);
	else if (image->map[image->x_n][image->y_n + 1] == '0')
	{
		go_back = 1;
		right(image);
	}
	else
		go_back = 0;
	return (0);
}

int	posn(t_vars *image)
{
	int	x;
	int	y;

	x = 0;
	while (image->map[x])
	{
		y = 0;
		while (image->map[x][y])
		{
			if (image->map[x][y] == 'N')
			{
				image->x_n = x;
				image->y_n = y;
				return (0);
			}
			y++;
		}
		x++;
	}
	return (0);
}
