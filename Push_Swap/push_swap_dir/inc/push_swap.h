/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:45:19 by lalves            #+#    #+#             */
/*   Updated: 2016/11/22 00:47:51 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <libft.h>

typedef struct	s_stack
{
	int		*a;
	int		*b;
	int		*sort;
	char	*str;
	int		arg;
}				t_stack;

void			get_sort_tab(t_stack *stack, int size);
void			quick_sort(t_stack *stack, int size);
void			find_smallest(t_stack *stack, int size, int *stack_size);
void			bubble_sort(t_stack *stack, int size);
int				check_sort_tab(t_stack *stack, int size);
void			free_stack(t_stack *stack);
void			print_tab(t_stack *stack, int size, int stack_size);
int				get_tab(char *str, t_stack *stack);
void			check_string(char *str, int ac);
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
