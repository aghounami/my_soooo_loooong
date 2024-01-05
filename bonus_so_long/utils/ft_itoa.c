/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:29:04 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/01 17:49:24 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	cont(int n)
{
	int	degit;

	degit = 0;
	if (n == 0)
		degit++;
	while (n)
	{
		n /= 10;
		degit++;
	}
	return (degit);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*res;
	int		len;

	sign = n < 0;
	len = cont(n) + sign;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = 0;
	if (sign)
	{
		*res = '-';
		res[--len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (len-- - sign)
	{
		res[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
