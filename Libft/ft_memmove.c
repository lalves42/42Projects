/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:26:34 by lalves            #+#    #+#             */
/*   Updated: 2015/12/15 17:17:53 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;

	temp = (char*)malloc(len);
	if (temp == NULL)
		return (NULL);
	ft_memcpy((void*)temp, src, len);
	ft_memcpy(dst, (const void*)temp, len);
	free(temp);
	return (dst);
}
