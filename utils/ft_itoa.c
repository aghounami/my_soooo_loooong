/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:29:04 by aghounam          #+#    #+#             */
/*   Updated: 2023/12/30 16:05:54 by aghounam         ###   ########.fr       */
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
