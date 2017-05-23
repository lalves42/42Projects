/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:23:20 by lalves            #+#    #+#             */
/*   Updated: 2016/10/16 20:34:45 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	size++;
	str = (char*)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	ft_bzero((void*)str, size);
	return (str);
}
