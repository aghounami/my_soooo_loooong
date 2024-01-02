/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 08:20:38 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/02 11:47:52 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
#define SOLONG_H

#include <mlx.h>
#include "./utils/get_next_line.h"
#include "./printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <libc.h>

typedef struct s_vars
{
	int		win_w;
	int 	win_h;
	int		x_p;
	int		y_p;
	char	**map;
	int		total_lenght;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		i;
	int		c;
	int		count;
	int		width;
	int		height;
	int		total_c;
	char	*player;
	char	*open;
	char	*close;
	int		posx;
	int		posy;
} t_vars;

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
char	*ft_exit(t_vars *image);
void randre(char **str, t_vars *image);
void	put_string(t_vars *image);
char	*join(char *s1, char *s2);
void	exit_map(t_vars *image);
char	*update(char *str);
void	putimage(char *str, t_vars *image, int i, int j);
void 	position(char **rest, t_vars *size);
void	window(t_vars *image);
int		handle_key_event(int keycode, t_vars *image);
// char	*ft_substr(const char *s, int start, int len);
// char	*ft_strtrim(char const *s1, char const *set);
// char	*ft_strdup(const char *s1);
// char	**ft_split(char const *s, char c);
// char	*ft_itoa(int n);
#endif