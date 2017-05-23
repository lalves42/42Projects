/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:54:21 by lalves            #+#    #+#             */
/*   Updated: 2016/11/22 00:39:52 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H
# include <libft.h>

typedef struct	s_stack
{
	int		*a;
	int		*b;
	char	*str;
	int		arg;
	int		flag;
	int		count;
}				t_stack;

void			print_num_cmd(t_stack *stack);
void			print_last(t_stack *stack, int size);
int				get_flag(char *str);
void			free_stack(t_stack *stack);
void			print_stacks(t_stack *stack, int size, int s_size, char *cmd);
int				get_tab(char *str, t_stack *stack, int f);
void			check_string(char *str, int ac, int flag);
void			check_int(char *str, t_stack *stack);
void			check_double(t_stack *stack, int size);
void			error_fn(char *str, int ac);
void			error_fn2(t_stack *stack);
void			error_fn3(char *reason, t_stack *stack);
void			error_fn4(t_stack *stack, char *line);
void			error_fn5(char *reason, t_stack *stack);
int				apply_command(t_stack *s, int si, int *ssi, char *cmd);
int				apply_sa(int *tab, int size, int *stack_size);
int				apply_sb(int *stack, int *stack_size);
int				apply_ss(int *tab, int *stack, int size, int *stack_size);
int				apply_pa(int *tab, int *stack, int size, int *stack_size);
int				apply_pb(int *tab, int *stack, int size, int *stack_size);
int				apply_ra(int *tab, int size, int *stack_size);
int				apply_rb(int *stack, int *stack_size);
int				apply_rr(int *tab, int *stack, int size, int *stack_size);
int				apply_rra(int *tab, int size, int *stack_size);
int				apply_rrb(int *stack, int *stack_size);
int				apply_rrr(int *tab, int *stack, int size, int *stack_size);
char			*get_string(int ac, char **av);

#endif
