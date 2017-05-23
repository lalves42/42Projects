/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 20:40:18 by lalves            #+#    #+#             */
/*   Updated: 2016/11/10 20:41:22 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <wchar.h>
# include <limits.h>
# include <locale.h>

typedef struct	s_data
{
	int sharp;
	int zero;
	int minus;
	int plus;
	int space;
	int width;
	int precision;
	int length;
	int save;
}				t_data;

void			ft_bzero(void *s, size_t n);
int				convert_smaj(va_list *ap, t_data *data, int *i);
int				convert_cmaj(va_list *ap, t_data *data, int *i);
int				convert_percent(t_data *data, int *i);
int				convert_c(va_list *ap, t_data *data, int *i,
				unsigned char check);
int				convert_s(va_list *ap, t_data *data, int *i);
int				convert_p(va_list *ap, t_data *data, int *i);
int				convert_unsigned(va_list *ap, t_data *data, int *i, char c);
int				convert_signed(va_list *ap, t_data *data, int *i);
int				ft_wstrlen(wchar_t *str);
int				ft_wcharlen(wchar_t c);
int				ft_strcmp(const char *s1, const char *s2);
char			*apply_precision_neg(char *str, int i);
int				ft_putwstr(wchar_t *str);
int				ft_putwchar(wchar_t c);
uintmax_t		get_arg(va_list *ap, int length, char c);
int				ft_printf(const char *restrict format, ...);
int				fonction(va_list *ap, const char *restrict format,
				t_data *data, int *i);
int				get_conv(va_list *ap, const char *restrict format,
				t_data *data, int *i);
char			*apply_precision_s(char *str, t_data *data);
wchar_t			*apply_precision_ls(wchar_t *str, int precision);
char			*apply_precision(char *str, int i);
char			*apply_width_s(char *str, t_data *data);
char			*apply_width_p(char *str, t_data *data);
char			*apply_width(char *str, t_data *data, int i);
char			*ft_strnew_c(size_t size, char c);
void			ft_memdel(void **as);
int				ft_isdigit(int c);
void			ft_putendl(char const *s);
void			ft_strmaj(char *str);
char			*ft_itoa_base(uintmax_t nb, char c);
void			ft_error(char *reason);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
int				ft_atoi(const char *str);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(intmax_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);

#endif
