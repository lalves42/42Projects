/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 20:40:18 by lalves            #+#    #+#             */
/*   Updated: 2016/11/14 16:10:55 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <libft.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <locale.h>

typedef struct	s_flags
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
}				t_flags;

int				convert_smaj(va_list *ap, t_flags *data, int *i);
int				convert_cmaj(va_list *ap, t_flags *data, int *i);
int				convert_percent(t_flags *data, int *i);
int				convert_c(va_list *ap, t_flags *data, int *i,
				unsigned char check);
int				convert_s(va_list *ap, t_flags *data, int *i);
int				convert_p(va_list *ap, t_flags *data, int *i);
int				convert_unsigned(va_list *ap, t_flags *data, int *i, char c);
int				convert_signed(va_list *ap, t_flags *data, int *i);
int				ft_wstrlen(wchar_t *str);
int				ft_wcharlen(wchar_t c);
int				ft_putwstr(wchar_t *str);
int				ft_putwchar(wchar_t c);
uintmax_t		get_arg(va_list *ap, int length, char c);
int				ft_printf(const char *restrict format, ...);
int				get_flags(va_list *ap, const char *restrict format,
				t_flags *data, int *i);
int				get_conv(va_list *ap, const char *restrict format,
				t_flags *data, int *i);
char			*apply_precision_s(char *str, t_flags *data);
wchar_t			*apply_precision_ls(wchar_t *str, int precision);
char			*apply_precision_neg(char *str, int i);
char			*apply_precision(char *str, int i);
char			*apply_width_s(char *str, t_flags *data);
char			*apply_width_p(char *str, t_flags *data);
char			*apply_width(char *str, t_flags *data, int i);
char			*ft_itoa_base_printf(uintmax_t nb, char c);
char			*ft_strcpy_printf(char *dst, const char *src);

#endif
