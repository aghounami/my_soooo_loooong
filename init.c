/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:09:17 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/03 19:48:26 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_var(t_vars *size)
{
	size->total_lenght = 0;
	size->win_h = 0;
	size->win_w = 0;
	size->x_p = 0;
	size->y_p = 0;
	size->c = 0;
	size->height = 0;
	size->width = 0;
	size->count = 0;
	size->e = 0;
}
char	*join(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (free(s1), NULL);
	i = 0;
	res = malloc(sizeof(char) * (f_strlen(s1) + f_strlen(s2) + 1));
	if (!res)
		return (free(s1), NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*update(char *str)
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
		join = f_strjoin(join, line);
		free(line);
	}
	return (join);
}

void	flood(char **rest, int x, int y, t_vars *size)
{
	ifcaneat(rest, x, y, size);
	if (checkc(rest) == 0)
	{
		ft_printf("cant eat C\n");
		free_all(rest);
		exit(1);
	}
	if (size->e != 1)
	{
		ft_printf("cant exit\n");
		free_all(rest);
		mlx_clear_window(size->mlx_ptr, size->win_ptr);
		exit(1);
	}
}