/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:43:23 by aghounam          #+#    #+#             */
/*   Updated: 2023/12/10 17:05:30 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *l)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", l);
	}
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-', l);
		ft_putnbr(n, l);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, l);
		ft_putnbr(n % 10, l);
	}
	else
		ft_putchar((n + '0'), l);
}
