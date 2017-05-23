/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:27:35 by lalves            #+#    #+#             */
/*   Updated: 2016/10/16 20:34:46 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	ptr = (char*)malloc(sizeof(char) * len);
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, s1);
	return (ptr);
}
