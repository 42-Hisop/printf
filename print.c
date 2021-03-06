/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:16:47 by khee-seo          #+#    #+#             */
/*   Updated: 2021/02/07 12:17:35 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(char c, t_check *f)
{
	if (f->flag != -1 && f->wid > 1)
		f->pt = f->pt + put_wid(1, f);
	write(1, &c, 1);
	f->pt = f->pt + 1;
	if (f->flag == -1 && f->wid > 1)
		f->pt = f->pt + put_wid(1, f);
	return (0);
}

int		print_str(char *str, t_check *f)
{
	int		i;
	int		max;

	max = ft_strlen(str);
	if (f->pre < ft_strlen(str) && f->pre != -1)
		max = f->pre;
	if (f->flag != -1 && f->wid > max)
		f->pt = f->pt + put_wid(max, f);
	i = 0;
	if (str == 0)
	{
		write(1, "(null)", max);
		f->pt = f->pt + max;
	}
	while (str != 0 && i < max)
	{
		write(1, &str[i], 1);
		f->pt = f->pt + 1;
		i++;
	}
	if (f->flag == -1 && f->wid > max)
		f->pt = f->pt + put_wid(max, f);
	return (0);
}

int		print_ptr(long long num, char c, t_check *f)
{
	char	*p;
	int		i;

	p = ft_itoh(num, c);
	if (num == 0 && f->pre == 0)
		p[0] = '\0';
	if (ft_strlen(p) < f->pre)
		p = add_pre(p, f);
	if (f->flag != -1 && f->wid > (ft_strlen(p) + 2))
		f->pt = f->pt + put_wid(ft_strlen(p) + 2, f);
	i = 0;
	write(1, "0x", 2);
	f->pt = f->pt + 2;
	while (p[i])
	{
		write(1, &p[i], 1);
		f->pt = f->pt + 1;
		i++;
	}
	if (f->flag == -1 && f->wid > (ft_strlen(p) + 2))
		f->pt = f->pt + put_wid(ft_strlen(p) + 2, f);
	free(p);
	return (0);
}

int		print_int(long long num, t_check *f, int i)
{
	char	*p;

	p = ft_itoa(num);
	if ((num == 0 && f->pre == 0))
		p[0] = '\0';
	if (ft_strlen(p) <= f->pre)
		p = add_pre(p, f);
	if (f->pre != -1 && f->flag == 0)
		f->flag = 1;
	if (f->flag == 0 && num < 0)
	{
		write(1, &p[i++], 1);
		f->pt = f->pt + 1;
	}
	if (f->flag != -1 && f->wid > ft_strlen(p))
		f->pt = f->pt + put_wid(ft_strlen(p), f);
	while (p[i])
	{
		write(1, &p[i++], 1);
		f->pt = f->pt + 1;
	}
	if (f->flag == -1 && f->wid > ft_strlen(p))
		f->pt = f->pt + put_wid(ft_strlen(p), f);
	free(p);
	return (0);
}

int		print_hex(unsigned int num, char c, t_check *f)
{
	char	*p;
	int		i;

	p = ft_itoh(num, c);
	if (num == 0 && f->pre == 0)
		p[0] = '\0';
	if (ft_strlen(p) < f->pre)
		p = add_pre(p, f);
	if (f->pre != -1 && f->flag == 0)
		f->flag = 1;
	if (f->flag != -1 && f->wid > ft_strlen(p))
		f->pt = f->pt + put_wid(ft_strlen(p), f);
	i = 0;
	while (p[i])
	{
		write(1, &p[i], 1);
		f->pt = f->pt + 1;
		i++;
	}
	if (f->flag == -1 && f->wid > ft_strlen(p))
		f->pt = f->pt + put_wid(ft_strlen(p), f);
	free(p);
	return (0);
}
