/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:23:37 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/19 00:10:44 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void			f_free(char **split_argc);

size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strdup(const char *s);
void			ft_bzero(void *s, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
size_t			ft_strlen(const char *str);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				ft_isascii(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memset(void *s, int c, size_t n);
size_t			ft_strlcpy(char *dst, char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_atoi(const char *nptr);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
char			**ft_split(const char *s, char c);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
int				ft_printf(const char *format, ...);
int				ft_chosehex(int n, const char *format);
int				ft_hexlower(int n, const char *format);
int				ft_hexupper(int n, const char *format);
unsigned long	ft_vptr(unsigned long num, const char *format);
int				ft_putchar_onear(char c);
char			ft_c(const char *format);
int				ft_putchar(char c, const char *format);
int				ft_putstr(char *s, const char *format);
int				ft_putnbr(int n, const char *format);
void			ft_newl(void);
int				ft_putunsint(unsigned int n, const char *format);
int				ft_chosenbr(int n, const char *format);

#endif
