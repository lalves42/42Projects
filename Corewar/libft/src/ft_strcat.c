/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:36:33 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:53:25 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG

# include "libft.h"

char	*ft_strcat(char *s1, char const *s2)
{
	char	*ptr;

	if (!s1 || !s2)
	{
		ERROR_PARAM("ft_strcat");
		return (NULL);
	}
	ptr = s1;
	while (*ptr++)
		;
	ptr--;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (s1);
}

#else

char	*ft_strcat(char *s1, char const *s2)
{
	char	*ptr;

	ptr = s1;
	while (*ptr++)
		;
	ptr--;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (s1);
}
#endif
