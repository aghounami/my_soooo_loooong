/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 08:20:45 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/03 19:30:10 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	put_string(t_vars *image)
{
	char	*str;
	char	*j;

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
		exit_map("error in putmoves");
	}
	mlx_string_put(image->mlx_ptr, image->win_ptr, 24,
		(image->win_h - 1) * 50, 0xFFFFFF, j);
	free(str);
	free(j);
}

char	*get_image(char **str, t_vars *image, int i, int j)
{
	if (str[i][j] == '0')
		return (image->space);
	if (str[i][j] == 'P')
		return (image->player);
	if (str[i][j] == 'C')
		return (image->coin);
	if (str[i][j] == '1')
		return (image->wall);
	if (str[i][j] == 'E')
	{
		if(image->c == 0)
			return (image->open);
		else
			return (image->close);
	}
	return NULL;
}
void	randre(char **str, t_vars *image)
{
	int		i;
	int		j;
	char	*rendred;

	i = 0;
	mlx_clear_window(image->mlx_ptr, image->win_ptr);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			rendred = get_image(str, image, i, j);
			mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, rendred, j * 48, i * 48);
			j++;
		}
		i++;
	}
	put_string(image);
}

void	intilize_xpm(t_vars *image)
{
	image->close = mlx_xpm_file_to_image(image->mlx_ptr, "./imag/close.xpm",
			&image->height, &image->width);
	image->open = mlx_xpm_file_to_image(image->mlx_ptr, "./imag/open.xpm",
			&image->height, &image->width);
	image->wall = mlx_xpm_file_to_image(image->mlx_ptr, "./imag/wall.xpm",
			&image->height, &image->width);
	image->coin = mlx_xpm_file_to_image(image->mlx_ptr, "./imag/coin.xpm",
			&image->height, &image->width);
	image->player = mlx_xpm_file_to_image(image->mlx_ptr, "./imag/player.xpm",
			&image->height, &image->width);
	image->space = mlx_xpm_file_to_image(image->mlx_ptr, "./imag/space.xpm",
			&image->height, &image->width);
	if (!image->close || !image->open || !image->wall
		|| !image->coin || !image->player)
	{
		ft_printf("check xpmfile");
		exit_game(image);
	}
}
