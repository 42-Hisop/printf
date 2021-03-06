/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 22:46:06 by khee-seo          #+#    #+#             */
/*   Updated: 2021/02/07 12:17:05 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_check
{
	int			flag;
	int			wid;
	int			pre;
	int			pt;
}				t_check;

char			*ft_itoa(long long n);
char			*itoa(long long cpy, int i, int c);
int				print_char(char c, t_check *f);
int				print_str(char *str, t_check *f);
int				print_int(long long num, t_check *f, int i);
int				print_ptr(long long num, char c, t_check *f);
int				print_hex(unsigned int num, char c, t_check *f);
int				check_pre(const char *str, va_list ap, t_check *c);
int				check_wid(const char *str, va_list ap, t_check *c);
int				check_flag(const char *str, va_list ap, int *a);
int				check_format(const char *str, va_list ap, t_check *c);
int				ft_printf(const char *str, ...);
void			make_hex(char *dex, char c);
char			*ft_itoh(long long num, char c);
int				ft_strlen(char const *str);
int				put_wid(int len, t_check *c);
char			*add_pre(char *str, t_check *c);
char			*zero(void);

#endif
