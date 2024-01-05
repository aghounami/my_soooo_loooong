/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_adress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:15:50 by aghounam          #+#    #+#             */
/*   Updated: 2023/11/25 16:25:27 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_adress(unsigned long src, int *l)
{
	int		i;
	char	*hexa;
	char	res[255];

	hexa = "0123456789abcdef";
	i = 0;
	ft_putstr("0x", l);
	while (src >= 16)
	{
		res[i] = hexa[src % 16];
		src /= 16;
		i++;
	}
	res[i] = hexa[src];
	while (i >= 0)
	{
		ft_putchar(res[i], l);
		i--;
	}
}
