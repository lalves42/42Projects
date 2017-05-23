/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:51:56 by lalves            #+#    #+#             */
/*   Updated: 2016/10/14 17:15:25 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			len;
	char			*str;

	len = ft_strlen(s);
	len--;
	start = 0;
	str = NULL;
	while ((s[start] == ' ' || s[start] == '\t' ||
			s[start] == '\n') && s[start])
		start++;
	if (s[start] == '\0')
	{
		str = (char*)malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	len = len - start + 1;
	return (ft_strsub(s, start, len));
}
