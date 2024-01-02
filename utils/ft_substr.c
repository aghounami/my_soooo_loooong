/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:49:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/01 17:49:46 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(const char *s, int start, int len)
{
	int	i;
	char	*str;
	char	*sub;

	if (!s)
		return (NULL); 
	str = (char *)s;
	if (start >= f_strlen(s))
		return (ft_strdup(""));
	if (len > (f_strlen(s) - start))
		len = f_strlen(s) - start;
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
