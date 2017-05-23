/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:56:54 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/20 16:56:54 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <ncurses.h>

# include <libft.h>

# include "../corewar.h"

# define BYTES_PER_LINE 64
# define LINE_LENGTH BYTES_PER_LINE * 3

# define WIN_RATIO 0.2
# define PANEL_HELP_HEIGHT 12

# define COLOR_LIGHT_BLACK 8
# define PAIR_BORDER 100
# define PAIR_GREY 101

# define STR_RUNNING "** RUNNING **        "
# define STR_PAUSED "** PAUSED **         "

# define STR_CYCLE_TO_DIE "CYCLE_TO_DIE : %u          "
# define STR_CYCLE_DELTA "CYCLE_DELTA :  %u"
# define STR_NBR_LIVE "NBR_LIVE :     %u"
# define STR_MAX_CHECKS "MAX_CHECKS :   %u"
# define STR_CYCLE "Cycle: %u          "
# define STR_CYCLE_DURATION "Cycle duration: %u ms          "
# define STR_PROCESS_COUNT "Processes: %u          "

# define STR_PLAYER_NAME "Player %i: "
# define STR_PLAYER_LAST_LIVE "Last live:      %u      "
# define STR_PLAYER_LIVE_COUNT "Lives (period): %u      "

# define STR_AFF "Last 'aff':"
# define STR_AFF_L1 "  process %i"
# define STR_AFF_L2 "  r%i = [%.2x %.2x %.2x %.2x]       "
# define STR_AFF_L3 "  carry = "
# define STR_TRUE "1"
# define STR_FALSE "0"

# define STR_WIN_TOO_SMALL "(window is too small - some lines are hidden)"
# define STR_WINNER "The winner is "
# define STR_PRESS_ANY "Press any key to finish"

# define STR_HELP "HELP"

# define STR_COMMAND_HELP "[h]      Show / hide help"
# define STR_COMMAND_FULL "[f]      Toggle fullscren mode"
# define STR_COMMAND_NEXT "[n/s]    Next step"
# define STR_COMMAND_PAUSE "[SPACE]  Pause / Run"
# define STR_COMMAND_END "[ENTER]  End the game"

typedef struct	s_vec2
{
	int		x;
	int		y;
}				t_vec2;

typedef struct	s_panel
{
	WINDOW	*win;
	t_vec2	size;
}				t_panel;

void			curses_init();
void			curses_loop(int (*cycle_fn)(t_cycle_infos *));

WINDOW			*window_create(t_vec2 size, t_vec2 pos);
void			window_destroy(WINDOW *win);

void			wprint_buf(WINDOW *win, t_vec2 *pos, t_vec2 *max, char *buf);

void			panels_init(t_panel panels[3]);
void			panels_resize(t_panel panels[3]);

void			panel_help_draw(t_panel *panel);
void			panel_infos_draw(t_panel *panel);
void			panel_memory_draw(t_panel *panel, t_cycle_infos *infos);

void			draw(t_panel panels[2], t_cycle_infos *infos);

void			init_memory(t_cycle_infos *infos);

void			load_player_colors();

void			mark_bytes(t_cycle_infos *infos);

#endif
