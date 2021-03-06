/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 23:32:48 by khee-seo          #+#    #+#             */
/*   Updated: 2021/02/07 12:21:11 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_pre(const char *str, va_list ap, t_check *c)
{
	int		i;

	i = 0;
	if (!(str[i]))
		return (0);
	if (str[i] != '.')
	{
		c->pre = -1;
		return (0);
	}
	i = 1;
	c->pre = 0;
	if (str[i] == '*')
	{
		c->pre = va_arg(ap, int);
		if (c->pre < 0)
			c->pre = -1;
		return (2);
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		c->pre = c->pre * 10;
		c->pre = c->pre + (str[i++] - '0');
	}
	return (i);
}

int		check_wid(const char *str, va_list ap, t_check *c)
{
	int		i;

	i = 0;
	if (!(str[i]))
		return (0);
	if (str[i] == '*')
	{
		c->wid = va_arg(ap, int);
		if (c->wid < 0)
		{
			c->flag = -1;
			c->wid = c->wid * -1;
		}
		return (1);
	}
	c->wid = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		c->wid = c->wid * 10;
		c->wid = c->wid + (str[i] - '0');
		i++;
	}
	return (i);
}

int		check_format(const char *str, va_list ap, t_check *c)
{
	int		i;

	i = 0;
	if (!(str[i]))
		return (0);
	while (str[i])
	{
		if (str[i] == 'c')
			return ((print_char(va_arg(ap, int), c) + i + 1));
		if (str[i] == 's')
			return ((print_str(va_arg(ap, char *), c) + i + 1));
		if (str[i] == 'p')
			return ((print_ptr(va_arg(ap, long long), 'x', c) + i + 1));
		if (str[i] == 'd' || str[i] == 'i')
			return ((print_int(va_arg(ap, int), c, 0) + i + 1));
		if (str[i] == 'u')
			return ((print_int(va_arg(ap, unsigned int), c, 0) + i + 1));
		if (str[i] == 'x' || str[i] == 'X')
			return ((print_hex(va_arg(ap, unsigned int), str[i], c) + i + 1));
		if (str[i] == '%')
			return ((print_char('%', c) + 1));
		i++;
	}
	return (i);
}

int		check_flag(const char *str, va_list ap, int *a)
{
	int			i;
	t_check		*c;

	if (!(str[1]))
		return (1);
	if (!(c = (t_check *)malloc(sizeof(t_check))))
		return (0);
	i = 1;
	c->pt = 0;
	c->flag = 1;
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			c->flag = -1;
		else if (str[i] == '0' && c->flag != -1)
			c->flag = 0;
		i++;
	}
	i += check_wid(&str[i], ap, c);
	i += check_pre(&str[i], ap, c);
	i += check_format(&str[i], ap, c);
	*a = *a + c->pt;
	free(c);
	return (i);
}

int		ft_printf(const char *str, ...)
{
	int			i;
	va_list		ap;
	int			a;

	va_start(ap, str);
	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i += check_flag(&str[i], ap, &a);
		else if (str[i])
		{
			write(1, &str[i], 1);
			i++;
			a++;
		}
	}
	va_end(ap);
	return (a);
}
