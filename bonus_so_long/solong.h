/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 08:20:38 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/05 20:25:43 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include "./utils/get_next_line.h"
# include "./printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_vars
{
	int		win_w;
	int		win_h;
	int		x_p;
	int		y_p;
	char	**map;
	int		total_lenght;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		c;
	int		count;
	int		width;
	int		height;
	int		total_c;
	char	*player;
	char	*open;
	char	*close;
	char	*coin;
	char	*wall;
	char	*space;
	char	*enemy;
	int		x_n;
	int		y_n;
	int		posx;
	int		posy;
	int		e;
	int		fd;
}	t_vars;

void	checkmap(char *str, t_vars *size);
void	mouvea(t_vars *vars);
void	mouves(t_vars *image);
void	mouved(t_vars *image);
void	mouvew(t_vars *image);
void	init_var(t_vars *size);
void	checkpos(char **rest, t_vars *size);
char	*arvline(char *str, t_vars *size);
int		closegame(t_vars *image);
void	free_all(char **str);
void	randre(char **str, t_vars *image);
void	put_string(t_vars *image);
char	*join(char *s1, char *s2);
char	*update(char *str);
int		ifcaneat(char **str, int x, int y, t_vars *size);
void	position(char **rest, t_vars *size);
void	window(t_vars *image);
int		handle_key_event(int keycode, t_vars *image);
void	messagelong(char *s);
void	exit_map(char *s, t_vars *image);
void	intilize_xpm(t_vars *image);
void	flood(char **rest, int x, int y, t_vars *size);
int		checkc(char **src);
void	exit_game(t_vars *image);
int		test_v1(char *v);
int		fstrlen(char *p);
int		maploop(char *p, t_vars *size);
void	validmap(char *map, t_vars *size);
int		mouven(t_vars *image);
int		posn(t_vars *image);

#endif