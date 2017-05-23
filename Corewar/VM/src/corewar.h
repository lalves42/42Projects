/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:24:20 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/20 18:00:38 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** VNOON POUR LES CORRECTIONS <3
*/

#ifndef COREWAR_H

# define COREWAR_H

# include <op.h>
# include <libft.h>
# include <libftprintf.h>

# define BUFF_SIZE 1024

# define OP_COUNT 16

# define NAME "corewar"
# define STR_USAGE "usage: corewar [OPTION]... %s %s [FILE]...\n%s%s%s%s"
# define USAGE_DUMP "[-d nbr_cycles]"
# define USAGE_CHAMP "[[-n number] champion1.cor] ..."
# define OPTION_DUMP "\t-d, --dump\n\t\tdump nth cycle\n"
# define OPTION_NUMBER "\t-n, --number\n\t\tset champions number\n"
# define OPTION_HIDE "\t-h, --hide\n\t\thides 'aff' output\n"
# define OPTION_CURSES "\t-c, --ncurses\n\t\tncurses display\n"

# define OPTIONS_COUNT	5

# define ERRNO_USAGE	0x1
# define ERRNO_OPEN		0x2
# define ERRNO_EMPTY	0x3
# define ERRNO_HEADER	0x4
# define ERRNO_CHAMP_FILE_TOO_SMALL		0x5
# define ERRNO_CHAMP_FILE_TOO_BIG		0x6
# define ERRNO_PROG_SIZE		0x7
# define ERRNO_CHAMP_NBR		0x8
# define ERRNO_MEMORY			0x9

# define ERR_OPEN "Could not open file"
# define ERR_EMPTY "is empty"

# define ERR_HEADER "has an invalid header"
# define ERR_CHAMP_FILE_TOO_SMALL "is too small to be a champion"
# define ERR_CHAMP_FILE_TOO_BIG "code is too large"
# define ERR_PROG_SIZE "has a code size that differ from what its header says"
# define ERR_CHAMP_NBR "same number cannot be used for different champions"
# define ERR_MEMORY "memory allocation error (%s)\n"
# define ERR_UNDEFINED "undefined error"

# define ERR_TOO_MANY "Too many champions"

/*
** # define STR_PLAYER_INTRO "Introduction des champions...\n"
** # define STR_PLAYER_SUM "* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n"
** # define STR_PLAYER_WIN "le joueur %i (%s) a gagné\n"
** # define STR_LIVE_EXEC "un processus dit que le joueur %i(%s) est en vie\n"
*/

# define STR_PLAYER_INTRO "Introducing contestants...\n"
# define STR_PLAYER_SUM "* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n"
# define STR_PLAYER_WIN "Contestant %i, \"%s\", has won !\n"
# define STR_LIVE_EXEC "A process tells player %i (%s) is alive\n"

typedef char	t_reg[REG_SIZE];

typedef enum	e_state
{
	STATE_PAUSED = 0x0,
	STATE_RUNNING = 0x1,
	STATE_DONE = 0x2,
	STATE_STEP = 0x4
}				t_state;

typedef enum	e_flags
{
	FLAG_NONE = 0x0,
	FLAG_DUMP = 0x1,
	FLAG_VERB = 0x2,
	FLAG_NUMB = 0x4,
	FLAG_NCUR = 0x8,
	FLAG_FULL = 0x10,
	FLAG_HELP = 0x20,
	FLAG_HIDE = 0x40
}				t_flags;

/*
** 8 + {4 + 1 + ...}
** total: 16
** lost: 3
*/

typedef struct	s_option
{
	char	*l;
	t_flags	f;
	char	s;
}				t_option;

/*
** 8 + {4 + 3 + ...} + {4 + 4} + 8 + {4 + 4}
** total: 40
** lost: 1
*/

typedef struct	s_op
{
	const char	*name;
	int			args_count;
	t_arg_type	args_types[3];
	int			value;
	int			cycles;
	const char	*description;
	int			ocp;
	int			dir_short;
}				t_op;

/*
** 8 + {4 + 4} + {1 + ...}
** total: 24
** lost: 7
*/

typedef struct	s_op_arg
{
	char		*arg;
	size_t		size;
	int			value;
	t_arg_type	type;
}				t_op_arg;

/*
** 64 + 8 + 8 + {4 + 4} + {4 + 4}
** total: 96
*/

typedef struct	s_proc
{
	t_reg			reg[REG_NUMBER];
	char			*pc;
	t_op			*op;
	int				carry;
	int				live;
	int				wait;
	unsigned int	id;
}				t_proc;

/*
** 8 + 8 + 8 + {4 + 4} + {4 + 4} + {4 + 1 + ...}
** total: 48
** lost: 3
*/

typedef struct	s_player
{
	char	*name;
	char	*comment;
	char	*bytecode;
	int		prog_size;
	int		number;
	int		force_number;
	int		last_live;
	int		current_lives;
	char	id;
}				t_player;

/*
** total: 4
** lost: 0
*/

typedef struct	s_byte_infos
{
	char		number;
	char		live;
	char		pc;
	char		op;
}				t_byte_infos;

/*
** size(t_byte_infos) * MEM_SIZE + {4 * 4} + 8 + {4 + 4} + {4 + 4} + {4 + 4}
** 4 * (4 * 1024) = 16384
** total: 16432
** lost: 0
*/

typedef struct	s_cycle_infos
{
	t_byte_infos	byte_infos[MEM_SIZE];
	int				aff[4];
	char			*arena;
	int				last_live;
	unsigned int	speed;
	unsigned int	count;
	unsigned int	cycle_to_die;
	unsigned int	checks_count;
	unsigned int	check_cycle;
}				t_cycle_infos;

/*
** size(t_cycle_infos) + 8 + 8 + {4 + 4} + {4 + 4} + {4 + 4}
** total: 164272
** lost: 0
*/

typedef struct	s_corewar
{
	t_cycle_infos	cycle_infos;
	t_player		*players;
	t_proc			*process;
	t_state			state;
	t_flags			flags;
	int				process_count;
	int				player_count;
	int				dump_cycle;
	int				reg_error;
}				t_corewar;

/*
**	GLOBALS
*/

extern t_corewar	g_corewar;
extern t_op			g_op_tab[OP_COUNT + 1];

/*
** ============================== arguments.c ===============================
*/

void			parse_arguments(int argc, char **argv, t_flags *flags);

/*
** ============================== options.c ===============================
*/

void			match_options(char *arg, t_flags *flags);

/*
** =============================== errors.c =================================
*/

void			error(int errno, char *str);
void			error_max_size(char *path, int size);

/*
** ================================ read.c ==================================
*/

void			read_champion(char *av, int number);

/*
** =============================== convert.c ================================
*/

void			swap_endianess(char *dst, char *value, size_t type_size);

/*
** =============================== players.c ================================
*/

void			load_players_in_mem(char *arena, t_player *players);
t_player		*find_player(int id);

/*
** ================================= dump.c =================================
*/

void			dump_memory(char *memory);

/*
** ================================== vm.c ==================================
*/

void			run_vm(void);

/*
** ================================ cycles.c ================================
*/

void			cycle_handler(void);

/*
** ================================ cycles.c ================================
*/

void			run_processes(void);

/*
** ================================ memory.c ================================
*/

char			*get_addr(char *addr);
char			read_byte(char *addr);
void			read_range(char *dst, char *pc, size_t range);
void			write_range(char *dst, char *pc, size_t range, int id);

/*
** =============================== register.c ===============================
*/
t_reg			*get_register(t_reg *reg, int idx);
void			read_register(t_reg *reg, char *value);
void			store_register(t_reg *reg, char *value);
void			write_register(t_reg *reg, char *pc, int champ_number);
void			copy_register(t_reg *r1, t_reg *r2);

/*
** ============================ op_functions_1.c ============================
*/

void			live_op(t_proc *proc, t_op_arg args[3]);
void			ld_op(t_proc *proc, t_op_arg args[3]);
void			st_op(t_proc *proc, t_op_arg args[3]);
void			add_op(t_proc *proc, t_op_arg args[3]);
void			sub_op(t_proc *proc, t_op_arg args[3]);
void			and_op(t_proc *proc, t_op_arg args[3]);
void			or_op(t_proc *proc, t_op_arg args[3]);
void			xor_op(t_proc *proc, t_op_arg args[3]);
void			zjmp_op(t_proc *proc, t_op_arg args[3]);
void			ldi_op(t_proc *proc, t_op_arg args[3]);
void			sti_op(t_proc *proc, t_op_arg args[3]);
void			fork_op(t_proc *proc, t_op_arg args[3]);
void			lld_op(t_proc *proc, t_op_arg args[3]);
void			lldi_op(t_proc *proc, t_op_arg args[3]);
void			lfork_op(t_proc *proc, t_op_arg args[3]);
void			aff_op(t_proc *proc, t_op_arg args[3]);

/*
** ============================ op_arguments.c =============================
*/

size_t			get_argument_op(t_proc *proc, int opcode, t_op_arg args[3]);

/*
**  ============================ op_value.c ===============================
*/

int				get_value(t_proc *p, t_op_arg *arg, int	idx, int long_op);

/*
** =============================== process.c ================================
*/

t_proc			*process_create(char *pc, t_proc *proc);
int				process_op(t_proc *proc);
char			*process_move(t_proc *proc, int offset);

/*
** ================================= kill.c ================================
*/

void			kill_processes(size_t count);

#endif
