/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:01:21 by khee-seo          #+#    #+#             */
/*   Updated: 2021/02/07 12:12:55 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*zero(void)
{
	char	*p;

	if (!(p = (char *)malloc(sizeof(char) * 2)))
		return (0);
	p[0] = '0';
	p[1] = '\0';
	return (p);
}

void	make_hex(char *hex, char c)
{
	int		i;
	char	a;

	i = 0;
	a = '0';
	while (i < 16)
	{
		hex[i] = a;
		i++;
		a++;
		if (i == 10 && c == 'x')
			a = 'a';
		else if (i == 10 && c == 'X')
			a = 'A';
	}
}

char	*ft_itoh(long long num, char c)
{
	char		hex[16];
	int			i;
	long long	cpy;
	char		*p;

	if (num == 0)
		return (zero());
	make_hex(hex, c);
	cpy = num;
	i = 0;
	while (cpy > 0)
	{
		cpy = cpy / 16;
		i++;
	}
	if (!(p = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	p[i--] = '\0';
	while (num > 0)
	{
		p[i] = hex[num % 16];
		num = num / 16;
		i--;
	}
	return (p);
}
