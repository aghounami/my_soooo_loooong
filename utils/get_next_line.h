/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:39:36 by aghounam          #+#    #+#             */
/*   Updated: 2023/12/30 16:06:28 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 214
# endif

char	*ft_itoa(int n);
char	*ft_next(char *data);
char	*ft_line(char *data);
char	*read_file(int fd, char *data);
char	*get_next_line(int fd);
char	*f_strjoin(char *s1, char *s2);
char	*f_strchr(const char *s, int c);
void	*f_calloc(int count, int size);
void	f_bzero(void *s, int n);
int		f_strlen(const char *str);
int		ft_len(char *buffer);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(const char *s, int start, int len);


#endif
