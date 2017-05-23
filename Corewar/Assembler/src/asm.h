/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 18:00:16 by lalves            #+#    #+#             */
/*   Updated: 2017/03/16 18:18:56 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

# define ASM_H

# include <op.h>
# include <libft.h>
# include <libftprintf.h>

# define USAGE error("Usage: ./asm Champion.s\n", -1)
# define ERROR_OPEN_SRC error("asm: Could not open source file\n", -2)
# define ERROR_READ_SRC error("asm: Could not read source file\n", -3)
# define ERROR_EMPTY_FILE error("asm: Empty file\n", -4)
# define ERROR_NAME error("asm: Invalid name\n", -5)
# define ERROR_COMMENT error("asm: Invalid comment\n", -6)
# define ERROR_NO_OPCODE error("asm: Champion needs at least 1 opcode\n", -7)
# define NAME_SYNTAX error("asm: The name has wrong syntax\n", -8)
# define COMMENT_SYNTAX error("asm: The comment has wrong syntax\n", -9)
# define ERROR_OPEN_DST error("asm: Could not create/open dest file\n", -10)
# define ERROR_MALLOC error("asm: Could not allocate memory with malloc\n", -11)

typedef struct	s_label
{
	char			*label;
	off_t			pos;
	off_t			pos_to_write;
	int				done;
	int				bytes;
	struct s_label	*next;
}				t_label;

typedef struct	s_env
{
	t_label	*declare;
	t_label	*use;
	int		src_fd;
	int		dst_fd;
	int		name;
	int		comment;
	int		opcode;
}				t_env;

typedef struct	s_op_conv
{
	char	*name;
	char	code;
	int		(*fn)(t_env *, char *, char);
}				t_op_conv;

typedef struct	s_op_check
{
	char	*name;
	int		(*fn)(char *, t_env *);
}				t_op_check;

int				error(char *str, int errno);
int				name_error(void);
int				comment_error(void);
int				wrong_arg(char *opcode, char *arg);
int				wrong_line(char *str);

void			convert_file(char *src_path);
t_label			*init_label(char *line, size_t i);
t_env			*init_env(char *src_path);
void			clear_env(t_env **env);
char			*convert_path(char *path);

void			write_ocp(int fd, char *arg, int arg_nb);

void			parse_line(char *line, t_env *env);
void			parse_helper(char **line, t_env *env);
void			get_label_declare_offset(char *line, t_env *env);
void			clean_split_line(char ***tab, char **line);

int				name_fn(int fd, char *arg);
int				comment_fn(int fd, char *arg);
int				live_fn(t_env *env, char *arg, char c);
int				ld_fn(t_env *env, char *arg, char c);
int				st_fn(t_env *env, char *arg, char c);

int				add_fn(t_env *env, char *arg, char c);
int				sub_fn(t_env *env, char *arg, char c);
int				and_fn(t_env *env, char *arg, char c);
int				or_fn(t_env *env, char *arg, char c);
int				xor_fn(t_env *env, char *arg, char c);

int				zjmp_fn(t_env *env, char *arg, char c);
int				ldi_fn(t_env *env, char *arg, char c);
int				sti_fn(t_env *env, char *arg, char c);
int				fork_fn(t_env *env, char *arg, char c);
int				lld_fn(t_env *env, char *arg, char c);

int				lldi_fn(t_env *env, char *arg, char c);
int				lfork_fn(t_env *env, char *arg, char c);
int				aff_fn(t_env *env, char *arg, char c);

int				get_arg(char **arg, int *nb, t_env *env, int modifier);
int				save_used_label(char *arg, t_env *env, int type, int modifier);
void			write_arg(int fd, int *nb, int byte_to_write);
void			write_prog_size(int fd);

void			check_invalid_file(t_env *env);
int				type_of_line(char *line);
char			**get_op_tab(int i);
void			check_cmd_length(int fd);
char			*save_label(char *line, t_env *env);
void			check_opcode(char *line, t_env *env);
void			check_empty_file(int fd);

char			**split_line(char *str);
int				before_space(char *str, int i);
int				after_space(char *str, int i);

char			*next_arg(char *arg);
int				check_reg(char *arg);
int				check_ind(char *arg, t_env *env);
int				check_dir(char *arg, t_env *env);
int				check_live(char *arg, t_env *env);

int				check_ld(char *arg, t_env *env);
int				check_st(char *arg, t_env *env);
int				check_add(char *arg, t_env *env);
int				check_sub(char *arg, t_env *env);
int				check_and(char *arg, t_env *env);

int				check_or(char *arg, t_env *env);
int				check_xor(char *arg, t_env *env);
int				check_zjmp(char *arg, t_env *env);
int				check_ldi(char *arg, t_env *env);
int				check_sti(char *arg, t_env *env);

int				check_fork(char *arg, t_env *env);
int				check_lld(char *arg, t_env *env);
int				check_lldi(char *arg, t_env *env);
int				check_lfork(char *arg, t_env *env);
int				check_aff(char *arg, t_env *env);

void			check_label_fill(t_env *env);

void			write_labels(t_env *env);
void			get_label_use_offset(char *arg, t_env *env);
void			save_label_data(t_label *lst, int type, int modifier, int fd);

#endif
