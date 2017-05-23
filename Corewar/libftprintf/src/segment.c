/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:51:44 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/09 15:38:59 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int		segment_memset(t_fdata *fdatas, int c, int off, int len)
{
	char			*b;
	unsigned char	uc;

	uc = (unsigned char)c;
	len = (off + len < fdatas->write_size) ? len : fdatas->write_size - off;
	b = &fdatas->out[off];
	while (len--)
		*b++ = uc;
	return (b - &fdatas->out[off]);
}

char	*set_segment_sign(t_fflag flags, char *sign, char stop)
{
	sign[0] = '+';
	sign[1] = '\0';
	if (flags & FLAG_NUMBERSIGN)
	{
		sign[0] = '0';
		if (flags & FLAG_HEX)
		{
			sign[1] = (stop == 'p') ? 'x' : stop;
			sign[2] = '\0';
		}
	}
	else if (flags & FLAG_NEGATIVE)
		sign[0] = '-';
	else if (flags & FLAG_SPACE)
		sign[0] = ' ';
	return (sign);
}

int		set_segment_width(t_fflag flags, int width, int print_len)
{
	if (width <= print_len)
	{
		width = print_len;
		if (flags & FLAG_HEX && flags & FLAG_NUMBERSIGN)
			width += 2;
		else if (flags & FLAG_PREFIXED)
			width++;
	}
	return (width);
}

void	write_padding(t_segment *seg, t_fdata *fdat, int print_len, int str_len)
{
	int		fill_len;

	fill_len = print_len - str_len;
	if (fdat->flag & FLAG_LESS)
	{
		if (fdat->flag & FLAG_HEX && fdat->flag & FLAG_NUMBERSIGN)
			seg->write_offset += 2;
		else if (fdat->flag & FLAG_PREFIXED)
			seg->write_offset++;
		seg->sign_position = seg->write_offset;
	}
	else if (fdat->flag & FLAG_ZERO && fdat->precision < 0)
	{
		seg->sign_position = seg->write_offset + 1;
		if (fdat->flag & FLAG_HEX && fdat->flag & FLAG_NUMBERSIGN)
			seg->sign_position += 1;
		fill_len = seg->width - str_len;
	}
	else
	{
		seg->write_offset += segment_memset(fdat, ' ', seg->start_offset,
														seg->width - print_len);
		seg->sign_position = seg->write_offset;
	}
	seg->write_offset += segment_memset(fdat, '0', seg->write_offset, fill_len);
}

void	write_prefix(t_segment *seg, t_fdata *fdat, int print_len, int str_len)
{
	int		sign_len;

	sign_len = 0;
	if (fdat->flag & FLAG_PREFIXED)
	{
		sign_len =
			(fdat->flag & FLAG_HEX && fdat->flag & FLAG_NUMBERSIGN) ? 2 : 1;
		print_len += sign_len;
		seg->sign_position -= sign_len;
		while (sign_len--)
			fdat->out[seg->sign_position + sign_len] = seg->sign[sign_len];
	}
	if (fdat->flag & FLAG_LESS)
		segment_memset(fdat, ' ', seg->write_offset + str_len,
														seg->width - print_len);
}
