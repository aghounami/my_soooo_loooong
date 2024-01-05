/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:14:01 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/05 15:55:06 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	messagelong(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

void	free_all(char **str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		free(str[x]);
		x++;
	}
	free(str);
}

int	closegame(t_vars *image)
{
	ft_printf("The window is being closed\n");
	mlx_clear_window(image->mlx_ptr, image->win_ptr);
	mlx_destroy_window(image->mlx_ptr, image->win_ptr);
	exit(0);
}

void	exit_game(t_vars *image)
{
	close(image->fd);
	mlx_clear_window(image->mlx_ptr, image->win_ptr);
	mlx_destroy_window(image->mlx_ptr, image->win_ptr);
	exit(1);
}

int	test_v1(char *v)
{
	int	i;

	i = fstrlen(v);
	if (i < 5)
		return (0);
	if (v[i - 1] != 'r' || v[i - 2] != 'e' || v[i - 3] != 'b'
		|| v[i - 4] != '.')
		return (0);
	return (1);
}
