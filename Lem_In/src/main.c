/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:28:16 by lalves            #+#    #+#             */
/*   Updated: 2017/02/06 14:58:36 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static t_env	*init_env(void)
{
	t_env *data;

	data = (t_env*)malloc(sizeof(t_env));
	if (!data)
		ft_error("malloc");
	data->rooms = NULL;
	data->start = NULL;
	data->end = NULL;
	data->ants = 0;
	data->nb_room = 0;
	data->nb_link = 0;
	return (data);
}

int				main(void)
{
	t_env *data;

	data = init_env();
	parsing(data);
	free_fn(data);
	return (0);
}
