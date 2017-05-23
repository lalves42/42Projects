/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:26:43 by lalves            #+#    #+#             */
/*   Updated: 2016/11/09 15:26:46 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	four_bytes(unsigned char *c)
{
	unsigned char bit1;
	unsigned char bit2;
	unsigned char bit3;
	unsigned char bit4;

	bit1 = *c;
	bit2 = (*(c + 1) << 4) | (bit1 >> 4);
	bit2 = (bit2 >> 2) | 0b10000000;
	bit3 = (*(c + 2) << 4) | (*(c + 1) >> 4);
	bit3 = bit3 << 2;
	bit3 = (bit3 >> 2) | 0b10000000;
	bit4 = (*(c + 2) >> 2) | 0b11110000;
	bit1 = bit1 << 2;
	bit1 = (bit1 >> 2) | 0b10000000;
	write(1, &bit4, 1);
	write(1, &bit3, 1);
	write(1, &bit2, 1);
	write(1, &bit1, 1);
	return (4);
}

static int	three_bytes(unsigned char *c)
{
	unsigned char bit1;
	unsigned char bit2;
	unsigned char bit3;

	bit1 = *c;
	bit2 = *(c + 1);
	bit3 = bit2;
	bit2 = (bit2 << 2) | (bit1 >> 6);
	bit2 = bit2 << 2;
	bit2 = (bit2 >> 2) | 0b10000000;
	bit3 = (bit3 >> 4) | 0b11100000;
	bit1 = bit1 << 2;
	bit1 = (bit1 >> 2) | 0b10000000;
	write(1, &bit3, 1);
	write(1, &bit2, 1);
	write(1, &bit1, 1);
	return (3);
}

static int	two_bytes(unsigned char *c)
{
	unsigned char	bit1;
	unsigned char	bit2;

	bit1 = *c;
	bit2 = *(c + 1);
	bit2 = bit2 << 2;
	bit2 = bit2 | (bit1 >> 6);
	bit1 = bit1 << 2;
	bit1 = bit1 >> 2;
	bit1 = bit1 | 0b10000000;
	bit2 = bit2 | 0b11000000;
	write(1, &bit2, 1);
	write(1, &bit1, 1);
	return (2);
}

int			ft_putwchar(wchar_t c)
{
	if (c <= 127)
	{
		ft_putchar((char)c);
		return (1);
	}
	else if (c <= 2047)
		return (two_bytes((unsigned char*)&c));
	else if (c <= 65535)
		return (three_bytes((unsigned char*)&c));
	else if (c <= 1114111)
		return (four_bytes((unsigned char*)&c));
	return (-1);
}
