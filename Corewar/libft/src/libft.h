/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 19:13:17 by tdefresn          #+#    #+#             */
/*   Updated: 2016/10/01 19:13:17 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

# define ABS(x) ((x < 0) ? -x : x)
# define HEX_TABLE(x) "0123456789abcdef"[x]

/*
** 8 + 8 + 4 -> lost: 4 bytes
*/
typedef struct	s_list
{
	struct s_list	*next;
	void			*content;
	size_t			content_size;
}				t_list;

/*
** 8 + 8 + 8 + 4 -> lost: 4 bytes
*/
typedef struct	s_dl_list
{
	struct s_dl_list	*next;
	struct s_dl_list	*prev;
	void				*content;
	size_t				content_size;
}				t_dl_list;

/*
** 8 + 8 + 4 -> lost: 4 bytes
*/
typedef struct	s_queue
{
	struct s_queue	*next;
	void			*content;
	size_t			content_size;
}				t_queue;

/*
** 8 + 8 + 4 -> lost: 4 bytes
*/
/*
** TODO
** @rename
** prev -> next
*/
typedef struct	s_stack
{
	struct s_stack	*prev;
	void			*content;
	size_t			content_size;
}				t_stack;

/*
**	MEMORY
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
/*
**	STRINGS
*/

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
intmax_t		ft_atoimax(const char *str);

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void(*f)(char *));
void			ft_striteri(char *s, void(*f)(unsigned int, char *));
char			*ft_strmap(const char *s, char(*f)(char));
char			*ft_strmapi(const char *s, char(*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strnjoin(const char *s1, const char *s2, int n);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(const char *s, char c);
char			*ft_itoa(int n);

char			*ft_itoa_base(intmax_t n, int base);
char			*ft_imaxtoa(intmax_t n);
char			*ft_uitoa(uintmax_t n);

char			*ft_strconcat(char *s1, const char *s2);
char			*ft_strnconcat(char *s1, const char *s2, int n);
void			ft_strprepend(char **str, char *prefix);
char			*ft_strpbrk(const char *s1, const char *s2);

/*
**	CHECKS
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_islower(int c);

/*
**	OUTPUT
*/

void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

void			ft_putaddr(const void *addr);

/*
**	FORWARD LISTS
*/

t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int				ft_lstsize(t_list *lst);
t_list			*ft_lstgetat(t_list *lst, int idx);
t_list			*ft_lstsort(t_list *lst, int (*cmp)(void *, void *));

/*
**	DOUBLE LINKED LISTS
*/

t_dl_list		*ft_dl_lstnew(const void *content, size_t content_size);
void			ft_dl_lstclear(t_dl_list **alst);
t_dl_list		*ft_dl_lstfront(t_dl_list *lst);
t_dl_list		*ft_dl_lstback(t_dl_list *lst);
void			ft_dl_lstpushfront(t_dl_list **alst, t_dl_list *new);
void			ft_dl_lstpushback(t_dl_list *lst, t_dl_list *new);
void			ft_dl_lstpopfront(t_dl_list **alst);
void			ft_dl_lstpopback(t_dl_list **alst);
void			ft_dl_lstiter(t_dl_list *lst, void (*f)(t_dl_list *elem));
t_dl_list		*ft_dl_lstmap(t_dl_list *lst, t_dl_list *(*f)(t_dl_list *elem));
int				ft_dl_lstsize(t_dl_list *lst);

/*
**	QUEUES
*/

t_queue			*ft_queuenew(const void *content, size_t content_size);
t_queue			*ft_queueback(t_queue *queue);
void			ft_queuepush(t_queue *queue, t_queue *new);
void			ft_queuepop(t_queue **aqueue);
int				ft_queuesize(t_queue *queue);

/*
**	STACKS
*/

t_stack			*ft_stacknew(const void *content, size_t content_size);
void			ft_stackpush(t_stack **astack, t_stack *new);
t_stack			*ft_stackpop(t_stack **astack);
int				ft_stacksize(t_stack *stack);

/*
**	MATH
*/

int				ft_pow(int b, int e);

# ifdef DEBUG

void			ft_debug_error_param(const char *fn_name);
void			ft_debug_error_free(const char *fn_name);

#  define ERROR_PARAM(fn_name) ft_debug_error_param(fn_name)
#  define ERROR_FREE(fn_name) ft_debug_error_free(fn_name)
# endif
#endif
