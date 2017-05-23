/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 19:02:39 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/09 15:09:06 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static void		buffer_memcpy(void *dst, void const *src, size_t n)
{
	char		*p_dst;
	const char	*p_src;

	p_dst = dst;
	p_src = src;
	while (n--)
		*p_dst++ = *p_src++;
}

/*
** segment.width: nombre d'octets a imprimer
** precision: nombre minimum de caracteres a afficher
** str_len: taille de la chaine à imprimer (sans modificateurs)
** print_len: taille réelle à imprimer (avec modificateurs)
** =========
** str_len = (segment.write_offset + str_len < fdatas->write_size)
**  ? str_len : fdatas->write_size - segment.write_offset;
*/

void			write_format(const void *src, int str_len, t_fdata *fdatas,
							void (*write_fn)(void *dst, const void *, size_t n))
{
	t_fflag		flags;
	t_segment	segment;
	char		sign[3];
	int			print_len;

	flags = fdatas->flag;
	print_len = (fdatas->precision < str_len) ? str_len : fdatas->precision;
	ft_bzero(&segment, sizeof(t_segment));
	segment.start_offset = fdatas->bcount;
	segment.write_offset = fdatas->bcount;
	segment.sign = set_segment_sign(flags, sign, *fdatas->stop);
	segment.width = set_segment_width(flags, fdatas->width, print_len);
	fdatas->bcount += segment.width;
	fdatas->idx = fdatas->stop - fdatas->format + 1;
	parse(&fdatas->format[fdatas->idx], fdatas);
	fdatas->flag = flags;
	write_padding(&segment, fdatas, print_len, str_len);
	write_prefix(&segment, fdatas, print_len, str_len);
	write_fn = (write_fn) ? write_fn : &buffer_memcpy;
	write_fn(&fdatas->out[segment.write_offset], src, str_len);
}

static void		new_buffer(t_fdata *fdatas, int wcount)
{
	if (wcount < fdatas->write_size)
		fdatas->bcount += wcount;
	else
		fdatas->bcount += fdatas->write_size - fdatas->bcount;
	if (!fdatas->out)
		fdatas->out = (char *)malloc(fdatas->bcount + 1);
	fdatas->out[fdatas->bcount] = '\0';
}

void			write_to_buffer(const void *src, t_fdata *fdatas)
{
	const char	*specifier_addr;
	int			idx;
	int			wcount;

	idx = fdatas->bcount;
	if (!(specifier_addr = ft_strchr((char *)src, '%')))
	{
		wcount = ft_strlen(src);
		new_buffer(fdatas, wcount);
	}
	else
	{
		wcount = specifier_addr - (char *)src;
		fdatas->idx += wcount;
		fdatas->bcount += wcount;
		if (fdatas->idx < fdatas->write_size)
			parse(&fdatas->format[fdatas->idx], fdatas);
	}
	if (idx < fdatas->write_size)
	{
		wcount = (idx + wcount < fdatas->write_size)
									? wcount : (int)fdatas->write_size - idx;
		buffer_memcpy(&fdatas->out[idx], src, wcount);
	}
}
