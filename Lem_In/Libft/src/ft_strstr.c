/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:08:21 by lalves            #+#    #+#             */
/*   Updated: 2016/10/14 17:15:25 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;

	len = ft_strlen(s2);
	if (len == 0)
		return ((char*)s1);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, len) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
