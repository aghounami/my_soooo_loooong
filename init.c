/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:09:17 by aghounam          #+#    #+#             */
/*   Updated: 2023/12/31 17:15:49 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_var(t_vars *size)
{
	size->map = NULL;
	size->total_lenght = 0;
	size->win_h = 0;
	size->win_w = 0;
	size->x_p = 0;
	size->y_p = 0;
	size->i = 0;
	size->c = 0;
	size->height = 0;
	size->width = 0;
	size->count = 0;
	size->limn = "./imagp/limn.xpm";
	size->lisr = "./imagp/lisr.xpm";
	size->lfo9 = "./imagp/lfo9.xpm";
	size->lte7t = "./imagp/asfal.xpm";
	size->close = "./imag/close.xpm";
	size->open = "./imag/open.xpm";
}

int closegame(t_vars *image)
{
	mlx_destroy_window(image->mlx_ptr, image->win_ptr);
	exit(1);
}

void	free_all(char **str)
{
	int	x;

	x = 0;
	while(str[x])
	{
		free(str[x]);
		x++;
	}
	free(str);
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
	if(fd == -1)
	{
		ft_printf("Error opening file");
		exit(1);
	}
	while((line = get_next_line(fd)) != NULL)
	{
		
		join = f_strjoin(join, line);
		free(line);
	}
	return (join);
}