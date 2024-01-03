/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 08:21:31 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/03 18:11:52 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	checkc(char **src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (src[i])
	{
		while (src[i][j])
		{
			if (src[i][j] != '1' && src[i][j] != 'P'
				&& src[i][j] != 'E' && src[i][j] != '0')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	ifcaneat(char **str, int x, int y, t_vars *size)
{
	if (str[x + 1][y] == 'E' || str[x - 1][y] == 'E'
		|| str[x][y - 1] == 'E' || str[x][y + 1] == 'E')
		size->e = 1;
	if (str[x + 1][y] == 'C' || (str[x + 1][y] == '0'))
	{
		str[x + 1][y] = 'P';
		ifcaneat(str, x + 1, y, size);
	}
	if (str[x - 1][y] == 'C' || (str[x - 1][y] == '0'))
	{
		str[x - 1][y] = 'P';
		ifcaneat(str, x - 1, y, size);
	}
	if (str[x][y + 1] == 'C' || (str[x][y + 1] == '0'))
	{
		str[x][y + 1] = 'P';
		ifcaneat(str, x, y + 1, size);
	}
	if (str[x][y - 1] == 'C' || (str[x][y - 1] == '0'))
	{
		str[x][y - 1] = 'P';
		ifcaneat(str, x, y - 1, size);
	}
	return (0);
}

void	checkpos(char **rest, t_vars *size)
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
				break ;
			y++;
		}
		if (rest[x][y] == 'P')
			break ;
		x++;
	}
	flood(rest, x, y, size);
	free_all(rest);
}

int	validmap(char *map, t_vars *size)
{
	int	p;
	int	e;

	p = 0;
	e = 0;
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
		return (0);
	else
		return (1);
}

int	maploop(char *p, t_vars *size)
{
	t_vars	data;
	int		i ;
	char	**res;
	int		ol;
	int		len;

	i = 0;
	res = ft_split(p, '\n');
	len = size->win_w - 2;
	ol = size->win_h - 1;
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
	char	*check;
	char	*res;

	check = arvline(str, size);
	size->total_lenght = f_strlen(check);
	size->win_w = ft_len(check);
	res = ft_strtrim(check, "10EPC\n");
	if ((size->win_w * size->win_h - 1) != size->total_lenght
		|| (res[0] != '\0') || !validmap(check, size) || !maploop(check, size))
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
