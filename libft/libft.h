/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:08:47 by rloos             #+#    #+#             */
/*   Updated: 2023/02/16 13:03:08 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <math.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <strings.h>
# include <sys/stat.h>
# include <sys/types.h>

# define BUFFER_SIZE 10000

char	*ft_itoa(int n);
int		ft_isascii(int c);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
int		ft_isdigit(int arg);
int		ft_isprint(int arg);
int		ft_isalpha(int argument);
int		ft_isalnum(int argument);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void    ft_two_d_array_printer (char **array);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *str, int c, size_t n);
void	ft_int_array_printer(int *arr, int *size_a);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memchr(const void *str, int c, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *s, int searched_item);
char	*ft_strrchr(const char *s, int searched_item);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);

//ft_printf-functions
int		pr_putnbr(int e, int cnt);
int		pr_putstr(char *b, int cnt);
int		pr_putchar(char a, int cnt);
int		ft_printf(const char *str, ...);
int		pr_hexa_lo(unsigned int n, int cnt);
int		pr_hexa_up(unsigned int n, int cnt);
int		pr_pointer(unsigned long long n, int cnt);
int		pr_putunsigned_nbr(unsigned int e, int cnt);
int		ptr_write(unsigned long long dingdong, int cnt);

//get_next_line-functions
size_t	get_strlen(char *s);
char	*get_next_line(int fd);
char	*get_line(char *left_str);
char	*get_strchr(char *s, int c);
char	*get_new_left_str(char *left_str);
char	*get_strjoin(char *left_str, char *buff);
char	*get_read_to_left_str(int fd, char *left_str);

#endif
