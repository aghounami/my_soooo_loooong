/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 08:21:14 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/05 15:51:42 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*arvline(char *str, t_vars *size)
{
	char	*line;
	char	*join;

	join = f_calloc(1, 1);
	size->fd = open(str, O_RDONLY);
	if (size->fd == -1)
		exit_map("error opning fd", size);
	line = get_next_line(size->fd);
	while (line != NULL)
	{
		size->win_h++;
		join = f_strjoin(join, line);
		free(line);
		line = get_next_line(size->fd);
	}
	return (join);
}

int	fstrlen(char *p)
{
	int	i;

	i = 0;
	if (!p)
		return (0);
	while (p[i])
		i++;
	return (i);
}

void	checkmap(char *str, t_vars *size)
{
	char	*check;
	char	*res;

	check = arvline(str, size);
	size->total_lenght = f_strlen(check);
	size->win_w = ft_len(check);
	validmap(check, size);
	res = ft_strtrim(check, "10EPCN\n");
	if (!res)
		exit_map("error in allocation", size);
	if ((size->win_w * size->win_h - 1) != size->total_lenght
		|| (res[0] != '\0') || !maploop(check, size))
	{
		free(res);
		free(check);
		exit_map("map not valid", size);
	}
	free(check);
	free(res);
}

void	window(t_vars *image)
{
	image->mlx_ptr = mlx_init();
	if (!image->mlx_ptr)
		exit_map("error in init\n", image);
	image->win_ptr = mlx_new_window(image->mlx_ptr,
			image->width * 48, image->height * 48, "My Image");
	intilize_xpm(image);
	randre(image->map, image);
	mlx_hook(image->win_ptr, 17, 0, &closegame, image);
	mlx_hook(image->win_ptr, 2, 0, &handle_key_event, image);
	mlx_loop_hook(image->mlx_ptr, &mouven, image);
	mlx_loop(image->mlx_ptr);
}

int	main(int argc, char **arv)
{
	t_vars	image;
	char	*src;
	char	**str;

	if (test_v1(arv[1]) == 0 || argc != 2)
		messagelong("very large map");
	init_var(&image);
	checkmap(arv[1], &image);
	src = update(arv[1]);
	str = ft_split(src, '\n');
	if (!str)
		exit_map("error in split\n", &image);
	image.map = str;
	image.width = fstrlen(image.map[0]);
	while (image.map[image.height])
		image.height++;
	if (image.width > 53 || image.height > 29)
		exit_map("very large map", &image);
	window(&image);
}
