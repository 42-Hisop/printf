/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:48:18 by khee-seo          #+#    #+#             */
/*   Updated: 2021/02/07 11:47:57 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char const *str)
{
	int		i;

	if (str == NULL)
		return (6);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		put_wid(int len, t_check *c)
{
	int		i;

	len = c->wid - len;
	i = 0;
	while (i < len)
	{
		if (c->flag == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
	return (i);
}

char	*add_pre(char *str, t_check *c)
{
	char	*new;
	int		i;
	int		j;

	if (str[0] == '-')
		c->pre = c->pre + 1;
	if (!(new = (char *)malloc(sizeof(char) * (c->pre + 1))))
		return (0);
	i = 0;
	j = 0;
	if (str[j] == '-')
	{
		new[i++] = str[j++];
		c->pre = c->pre + 1;
	}
	while (i < (c->pre - ft_strlen(str)))
		new[i++] = '0';
	while (str[j])
		new[i++] = str[j++];
	new[i] = '\0';
	free(str);
	return (new);
}
