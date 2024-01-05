/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:47:19 by aghounam          #+#    #+#             */
/*   Updated: 2023/12/04 21:54:44 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(char spec, va_list arg, int *l)
{
	if (spec == 'c')
		ft_putchar(va_arg(arg, int), l);
	else if (spec == 's')
		ft_putstr(va_arg(arg, char *), l);
	else if (spec == 'p')
		ft_hexa_adress(va_arg(arg, unsigned long), l);
	else if (spec == 'd' || spec == 'i')
		ft_putnbr(va_arg(arg, int), l);
	else if (spec == 'u')
		ft_putpositive(va_arg(arg, unsigned int), l);
	else if (spec == 'x')
		ft_hexa_lower(va_arg(arg, unsigned int), l);
	else if (spec == 'X')
		ft_hexa_upper(va_arg(arg, unsigned int), l);
	else if (spec == '%')
		ft_putchar('%', l);
	else
		ft_putchar(spec, l);
}
