/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:41:20 by aghounam          #+#    #+#             */
/*   Updated: 2023/12/10 16:26:31 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		l;
	int		i;

	va_start(arg, s);
	l = 0;
	i = 0;
	if (write (1, "", 0) == -1)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				break ;
			ft_format(s[i], arg, &l);
		}
		else
			ft_putchar(s[i], &l);
		i++;
	}
	va_end(arg);
	return (l);
}
