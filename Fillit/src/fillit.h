/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 19:38:35 by lalves            #+#    #+#             */
/*   Updated: 2016/05/03 16:26:10 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <libft.h>
# include <fcntl.h>

typedef struct	s_tetriminos
{
	char	letter;
	int		a;
	int		b;
	int		c;
	int		d;
	int		e;
	int		f;
}				t_tetriminos;

typedef struct	s_square
{
	int		size;
	int		total;
	int		total_tmp;
	char	*grid;
}				t_square;

int				find_3(char *s, int i, t_tetriminos *ptr, int total);
void			save_tetriminos(char *buf, t_tetriminos *ptr, int total);
int				read_tetriminos(int fd, t_tetriminos *ptr);
void			init_grid(t_square *sqr);
void			convert(t_tetriminos *ptr, t_square *sqr);
void			solve(t_tetriminos *ptr, t_square *sqr);

#endif
