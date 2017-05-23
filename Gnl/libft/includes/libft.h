/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:02:08 by lalves            #+#    #+#             */
/*   Updated: 2016/05/05 02:04:55 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char			*ft_strdup(const char *s1);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlen(const char *s);

#endif
