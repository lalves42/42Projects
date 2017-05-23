/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_towstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 21:45:24 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/08 18:03:13 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

/*
**	Unicode characters will be 4-bytes long max
**	but UTF-8 can go up to 6-bytes long characters
**	=========================
**	wchar length:
**	0x80-0xc0		==> 2-bytes
**	0xc1-0x7ff		==> 3-bytes
**	0x800-0xffff	==> 4-bytes
**	0x10000-
**	=========================
**	forbidden characters:
**	0xc0, 0xc1, 0xfe, 0xff
**	=========================
**	|raw_byte|
**	|utf_byte|
**	 h+3	  h+2	   h+1		h
**	|00000000|00000000|00000000|0xxxxxxx|
**	|0xxxxxxx|
**	 h+3	  h+2	   h+1		h
**	|00000000|00000000|00000yyy|yyxxxxxx|
**	|110yyyyy|10xxxxxx|
**	 h+3	  h+2	   h+1		h
**	|00000000|00000000|zzzzyyyy|yyxxxxxx|
**	|1110zzzz|10yyyyyy|10xxxxxx|
**	 h+3	  h+2	   h+1		h
**	|00000000|000wwwzz|zzzzyyyy|yyxxxxxx|
**	|11110www|10zzzzzz|10yyyyyy|10xxxxxx|
**	=====================================
**	More than 4-bytes characters
**	 h+3	  h+2	   h+1		h
**	|000000vv|wwwwwwzz|zzzzyyyy|yyxxxxxx|
**	|111110vv|10wwwwww|10zzzzzz|10yyyyyy|10xxxxxx|
**	 h+3	  h+2	   h+1		h
**	|0uvvvvvv|wwwwwwzz|zzzzyyyy|yyxxxxxx|
**	|1111110u|10vvvvvv|10wwwwww|10zzzzzz|10yyyyyy|10xxxxxx|
*/

/*
**	mask12 = 0b00000000000000000000100000000000; <=> (1 << 11)
**	mask17 = 0b00000000000000010000000000000000; <=> (1 << 16)
*/

static int	convert_long(unsigned char *h, char *str, int len)
{
	int		i;

	i = 0;
	if (len <= 5)
		str[i++] = (((*(h + 3) & 0b00000011)) | 0b11111000);
	else
	{
		str[i++] = (((*(h + 3) & 0b01000000)) | 0b11111100);
		str[i++] = (((*(h + 3) & 0b00111111)) | 0b10000000);
	}
	str[i++] = (((*(h + 2) & 0b11111100) >> 2) | 0b10000000);
	return (i);
}

static void	convert(unsigned char *h, char *str, int len)
{
	int		i;

	i = 0;
	if (len <= 2)
		str[i++] = ((((*h & 0xc0) >> 6) | ((*(h + 1) << 2) & 0x1f)) | 0xc0);
	else
	{
		if (len <= 3)
			str[i++] = (((*(h + 1) & 0b11110000) >> 4) | 0b11100000);
		else
		{
			if (len <= 4)
				str[i++] = (((*(h + 2) & 0b00011100) >> 2) | 0b11110000);
			else
				i += convert_long(h, &str[i], len);
			str[i++] = ((((*(h + 1) & 0b11110000) >> 4) | ((*(h + 2) << 4)
							& 0b00111111)) | 0b10000000);
		}
		str[i++] = ((((*h & 0b11000000) >> 6) | ((*(h + 1) << 2)
							& 0b00111111)) | 0b10000000);
	}
	str[i++] = ((*h & 0b00111111) | 0b10000000);
}

/*
**	6-bytes extension
**	=================
**	else if (c <= MASK26)
**		wchar_size = 5;
**	else if (c <= MASK31)
**		wchar_size = 6;
*/

int			ft_wstrcpy(char *dst, wchar_t *src, int count)
{
	char	*end_ptr;
	int		wchar_size;
	wchar_t	c;

	end_ptr = &dst[count];
	while (dst < end_ptr)
	{
		c = *src++;
		if (c < 0 || c > MASK21)
			return (-1);
		if (c <= MASK7)
		{
			*dst++ = c;
			continue ;
		}
		wchar_size = 4;
		if (c <= MASK11)
			wchar_size = 2;
		else if (c <= MASK16)
			wchar_size = 3;
		convert((unsigned char *)&c, dst, wchar_size);
		dst += wchar_size;
	}
	return (count);
}
