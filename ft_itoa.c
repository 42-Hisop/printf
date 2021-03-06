/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 22:50:34 by khee-seo          #+#    #+#             */
/*   Updated: 2021/02/07 12:11:52 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa(long long cpy, int i, int c)
{
	char	*a;

	if (!(a = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	a[i] = '\0';
	i--;
	if (cpy == 0)
		a[i] = '0';
	while (cpy)
	{
		a[i] = cpy % 10 + '0';
		cpy = cpy / 10;
		i--;
	}
	if (c)
		a[i] = '-';
	return (a);
}

char	*ft_itoa(long long n)
{
	int			i;
	long long	cpy;
	char		*a;

	i = 0;
	cpy = n < 0 ? n * -1 : n;
	if (cpy == 0)
		i++;
	while (cpy)
	{
		cpy = cpy / 10;
		i++;
	}
	if (n < 0)
		a = itoa(n * -1, i + 1, 1);
	else
		a = itoa(n, i, 0);
	return (a);
}
