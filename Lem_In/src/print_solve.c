/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:59:42 by lalves            #+#    #+#             */
/*   Updated: 2017/02/06 15:00:49 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		free_path(t_path *begin)
{
	t_path *ptr;

	while (begin)
	{
		ptr = begin;
		begin = begin->next;
		ft_memdel((void**)&(ptr));
	}
}

static void		all_forward(t_path *begin, t_path *end_room)
{
	t_path *ptr;

	ptr = end_room->prev;
	while (!(ptr->cur_ant))
		ptr = ptr->prev;
	while (ptr != begin && ptr->cur_ant)
	{
		ft_printf("L%i-%s ", ptr->cur_ant, ptr->next->room->name);
		if (ptr->next == end_room)
			(end_room->gone_ant)++;
		else
			ptr->next->cur_ant = ptr->cur_ant;
		ptr->cur_ant = 0;
		ptr = ptr->prev;
	}
}

static void		introduce_ant(t_path *begin, t_path *end_room, int round)
{
	ft_printf("L%i-%s ", round + 1, begin->next->room->name);
	if (begin->next != end_room)
		begin->next->cur_ant = round + 1;
	else
		(end_room->gone_ant)++;
}

static void		play_round(t_path *begin, t_path *end, t_env *data, int round)
{
	if (round && begin->next != end)
		all_forward(begin, end);
	if (round < data->ants)
		introduce_ant(begin, end, round);
}

void			print_solve(t_path *begin, t_env *data)
{
	t_path	*end_room;
	int		round;

	end_room = begin;
	round = 0;
	while (end_room->next)
		end_room = end_room->next;
	while (end_room->gone_ant < data->ants)
	{
		play_round(begin, end_room, data, round);
		round++;
		ft_putchar('\n');
	}
	free_path(begin);
}
