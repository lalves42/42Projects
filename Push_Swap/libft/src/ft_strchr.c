/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:20:40 by lalves            #+#    #+#             */
/*   Updated: 2016/10/14 17:15:23 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char*)s)[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&((char*)s)[i]);
	return (NULL);
}
