/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:34:25 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:54:54 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG

# include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	if (!s || !f)
	{
		ERROR_PARAM("ft_striteri");
		return ;
	}
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

#else

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
#endif
