/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:19:59 by lalves            #+#    #+#             */
/*   Updated: 2017/02/06 15:09:09 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include <libft.h>

typedef struct	s_room
{
	char			*name;
	int				weight;
	struct s_room	**link;
	struct s_room	*next;
}				t_room;

typedef struct	s_path
{
	t_room			*room;
	int				cur_ant;
	int				gone_ant;
	struct s_path	*next;
	struct s_path	*prev;

}				t_path;

typedef struct	s_env
{
	t_room			*rooms;
	char			*start;
	char			*end;
	int				ants;
	int				nb_room;
	int				nb_link;
}				t_env;

int				parsing(t_env *data);
void			parsing_error(t_env *data, char *line);
int				check_line(char **line, t_env *data);
int				check_room(char *line, t_env *data, int cmd);
int				check_link(char *line, t_env *data);
int				save_link(t_room *first, t_room *second, t_env *data);
void			free_fn(t_env *data);
int				solve(t_env *data);
void			print_solve(t_path *begin, t_env *data);

#endif
