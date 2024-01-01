/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 08:21:31 by aghounam          #+#    #+#             */
/*   Updated: 2023/12/31 17:38:04 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int checkc(char **src)
{
	int i = 0;
	int j = 0;
	while (src[i])
	{
		while (src[i][j])
		{
			if (src[i][j] != '1' && src[i][j] != 'P' && src[i][j] != 'E' && src[i][j] != '0')
				return 0;
			j++;
		}
		i++;
		j = 0;
	}
	return 1;
}

int ifcaneat(char **str, int x, int y, t_vars *e)
{
	if (str[x + 1][y] == 'E' || str[x - 1][y] == 'E' || str[x][y - 1] == 'E' || str[x][y + 1] == 'E')
	{
		e->i = 1;
	}
	if (str[x + 1][y] == 'C' || (str[x + 1][y] == '0'))
	{
		str[x + 1][y] = 'P';
		ifcaneat(str, x + 1, y, e);
	}
	if (str[x - 1][y] == 'C' || (str[x - 1][y] == '0'))
	{
		str[x - 1][y] = 'P';
		ifcaneat(str, x - 1, y, e);
	}
	if (str[x][y + 1] == 'C' || (str[x][y + 1] == '0'))
	{
		str[x][y + 1] = 'P';
		ifcaneat(str, x, y + 1, e);
	}
	if (str[x][y - 1] == 'C' || (str[x][y - 1] == '0'))
	{
		str[x][y - 1] = 'P';
		ifcaneat(str, x, y - 1, e);
	}
	return 0;
}

void checkpos(char **rest, t_vars *size)
{
	int x = 0;
	int y = 0;
	t_vars e;
	e.i = 0;
	while (rest[x])
	{
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
		y = 0;
	}
	ifcaneat(rest, size->x_p, size->y_p, &e);
	if (checkc(rest) == 0)
	{
		ft_printf("cant eat C\n");
		free_all(rest);
		exit(0);
	}
	if (e.i != 1)
	{
		ft_printf("cant exit\n");
		free_all(rest);
		mlx_clear_window(size->mlx_ptr, size->win_ptr);
		exit(1);
	}
	free_all(rest);
}

int validmap(char *map, t_vars *size)
{
	int p = 0;
	int e = 0;
	while (*map)
	{
		if (*map == 'C')
		{
			size->c++;
		}
		else if (*map == 'P')
			p++;
		else if (*map == 'E')
			e++;
		map++;
	}
	if (size->c <= 0 || p != 1 || e != 1)
		return 0;
	else
		return (1);
}

int maploop(char *p, t_vars *size)
{
	t_vars data;
	int i = 0;
	char **res = ft_split(p, '\n');
	// free(p);
	int len = size->win_w - 2;
	int ol = size->win_h - 1;
	while (res[0][i] && res[ol][i])
	{
		if (res[0][i] != '1' || res[ol][i] != '1')
			return (0);
		i++;
	}
	while (ol >= 0)
	{
		if (res[ol][0] != '1' || res[ol][len] != '1')
			return (0);
		ol--;
	}
	checkpos(res, &data);
	return (1);
}

void	checkmap(char *str, t_vars *size)
{
	char *check;
	check = arvline(str, size);
	size->total_lenght = f_strlen(check);
	size->win_w = ft_len(check);
	char *res = ft_strtrim(check, "10EPC\n");
	if ((size->win_w * size->win_h - 1) != size->total_lenght || (res[0] != '\0')
		|| !validmap(check, size) || !maploop(check, size))
	{
		ft_printf("check map\n");
		free(res);
		free(check);
		mlx_clear_window(size->mlx_ptr, size->win_ptr);
		exit(1);
	}
	free(check);
	free(res);
}
