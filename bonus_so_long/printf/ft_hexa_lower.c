/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_lower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:25:28 by aghounam          #+#    #+#             */
/*   Updated: 2023/11/30 14:46:10 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_lower(unsigned int src, int *l)
{
	int		i;
	char	*hexa;
	char	res[255];

	hexa = "0123456789abcdef";
	i = 0;
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
