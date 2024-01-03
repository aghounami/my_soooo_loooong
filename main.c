/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 08:21:14 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/03 19:47:20 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*arvline(char *str, t_vars *size)
{
	int		fd;
	char	*line;
	char	*join;

	join = f_calloc(1, 1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file");
		exit(1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		size->win_h++;
		join = f_strjoin(join, line);
		free(line);
	}
	return (join);
}

void	exit_map(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

int	fstrlen(char *p)
{
	int i;

	i = 0;
	if (!p)
		return (0);
	while (p[i])
		i++;
	return (i);
}

int	test_v1(char *v)
{
	int i;

	i = fstrlen(v);
	if (i < 5)
		return (0);
	if (v[i - 1] != 'r' || v[i - 2] != 'e' || v[i - 3] != 'b' || v[i - 4] != '.')
		return (0);
	return (1);
}

int	handle_key_event(int keycode, t_vars *image)
{
	position(image->map, image);
	if (keycode == 53)
	{
		mlx_destroy_window(image->mlx_ptr, image->win_ptr);
		exit(0);
	}
	else if (keycode == 123)
		mouvea(image);
	else if (keycode == 125)
		mouves(image);
	else if (keycode == 124)
		mouved(image);
	else if (keycode == 126)
		mouvew(image);
	randre(image->map, image);
	return (0);
}

void	window(t_vars *image)
{
	image->mlx_ptr = mlx_init();
	if (!image->mlx_ptr)
		exit(1);
	image->win_ptr = mlx_new_window(image->mlx_ptr, image->width * 48, image->height * 48, "My Image");
	intilize_xpm(image);
	mlx_hook(image->win_ptr, 17, 0, &closegame, image);
	mlx_hook(image->win_ptr, 2, 0, &handle_key_event, image);
	randre(image->map, image);
	mlx_loop(image->mlx_ptr);
}

int main(int argc, char **arv)
{
	t_vars	image;
	char	*src;
	char	**str;

	if (test_v1(arv[1]) == 0 || argc != 2)
		exit_map("error");
	init_var(&image);
	checkmap(arv[1], &image);
	src = update(arv[1]);
	str = ft_split(src, '\n');
	if (!str)
		exit(1);
	image.map = str;
	image.width = fstrlen(image.map[0]);
	while (image.map[image.height])
		image.height++;
	if(image.width > 53 || image.height > 29)
		messagelong("map not valid");
	window(&image);
}
