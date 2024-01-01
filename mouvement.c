/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 08:20:45 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/01 15:14:13 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char *ft_exit(t_vars *image)
{
	if (image->c == 0)
		return (image->open);
	else
		return (image->close);
}

void put_string(t_vars *image)
{
	char *str;
	char *j;

	str = ft_itoa(image->count);
	if (!str)
	{
		mlx_clear_window(image->mlx_ptr, image->win_ptr);
		exit(1);
	}
	j = join("Moves : ", str);
	if (!j)
	{
		free(str);
		exit_map(image);
	}
	mlx_string_put(image->mlx_ptr, image->win_ptr, 5, (image->win_h - 1) * 48 + 48 / 8, 0xFFFFFF, j);
	free(str);
	free(j);
}
void randre(char **str, t_vars *image, char *player)
{
	int i;
	int j;

	i = 0;
	char *exit = ft_exit(image);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				putimage(player, image, i, j);
			else if (str[i][j] == 'C')
				putimage("./imag/makla.xpm", image, i, j);
			else if (str[i][j] == '1')
				putimage("./imag/jidar.xpm", image, i, j);
			else if (str[i][j] == '0')
				putimage("./imag/alll.xpm", image, i, j);
			else
				putimage(exit, image, i, j);
			// put_string(image);
			j++;
		}
		i++;
	}
}

void putimage(char *str, t_vars *image, int i, int j)
{
	image->img = mlx_xpm_file_to_image(image->mlx_ptr, str, &image->height, &image->width);
	if(!image->img)
	{
		mlx_clear_window(image->mlx_ptr, image->win_ptr);
		exit(1);
	}
	mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->img, j * 48, i * 48);
	put_string(image);
}