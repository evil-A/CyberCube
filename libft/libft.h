/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:07:01 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/11 22:08:27 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LIBFT_H
# define _FT_LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>

# define MAX_SIZE		4096
# define BUFFER_SIZE	500

typedef struct			s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef struct			s_some
{
	const char			*sline;
	va_list				args;
	char				*str;
	int					len;
	int					width;
	int					precision;
	int					zero;
	int					point;
	int					hyphen;
	int					pos;
	int					posline;
	int					val;
}						t_some;

int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isascii(int c);
int						ft_isalnum(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
						size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int						ft_atoi(const char *str);
void					*ft_calloc(size_t count, size_t size);
char					*ft_strdup(const char *s1);
char					*ft_substr(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_itoa(int n);
char					*ft_itoab(int n);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
						char));
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_lstadd_front(t_list **alst, t_list *new);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list	*lst);
void					ft_lstadd_back(t_list **alst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstnew(void *content);
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int						get_next_line(int fd, char **line);
int						ft_printf(const char *line, ...);
void					init_struct(t_some *some);
void					clean_struct(t_some *some);
char					*ft_itu(unsigned int n);
char					*ft_itox(unsigned long n);
char					*ft_itoxx(unsigned int n);
int						len(long nb);
int						lenx(unsigned long nb);
void					p_zero(t_some *some);
void					p_space(t_some *some);
void					zero_flag(t_some *some);
void					gotoparser(t_some *some);
void					strhyp(t_some *some);
void					putspa(t_some *some);
void					putpo(t_some *some);
void					putze(t_some *some);
void					neg(t_some *some);
void					p_hyp(t_some *some);
void					z_val(t_some *some);
void					fix(t_some *some);
void					inter(t_some *some);
void					f_hyp(t_some *some);
void					f_z(t_some *some);
void					f_left(t_some *some);
void					unsign(t_some *some);
void					hex(t_some *some);
void					hexx(t_some *some);
void					ponter(t_some *some);
void					per(t_some *some);
void					p_val(t_some *some);
void					pz(t_some *some);
void					cha(t_some *some);
void					stringer(t_some *some);
void					init_string(t_some *some);
void					point_string(t_some *some);

#endif
