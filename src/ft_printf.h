/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:11:20 by snovaes           #+#    #+#             */
/*   Updated: 2021/07/14 14:14:00 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>

/*
**  Struct Part
*/

typedef struct s_flags
{
	char	type;
	int		count;
	int		len;
	int		number;
	char	negative;
	char	minus;
	char	zero;
	int		width;
	char	padding;
	int		precision;
	char	dot;
	char	asterisk;
}				t_flags;

/*
** Printf functions
*/

int				ft_printf(const char *input, ...);
void			reset_types(t_flags *flags);
void			get_flags(const char *str, t_flags *flags, va_list args);
void			get_flag_a(const char *str, t_flags *flags, va_list args);
void			get_flag_star(t_flags *flags, va_list args, int *star);
int				is_number(const char *str, t_flags *flags);
void			reset_flags(t_flags *flags);

void			print_percent(t_flags *flags);
void			print_char(t_flags *flags, int c);
void			print_padding(t_flags *flags, int len);
void			print_str(t_flags *flags, char *s);
void			print_int(t_flags *flags, char *number, int size);
void			print_d_i(t_flags *flags, long int num);
void			print_du(t_flags *flags, unsigned int num);
void			print_hex(t_flags *flags, unsigned int num);
void			print_uhex(t_flags *flags, char *number, int size);
void			print_pointer(t_flags *flags, unsigned long pointer);
void			print_ptr(t_flags *flags, char *ptr, int size);

/*
**  Utils functions
*/

void			ft_putchar(t_flags *flags, char c);
char			*ft_strdup(const char *s1);
int				ft_isdigit(int c);
void			ft_putstr(t_flags *flags, char *s, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_itoa(long int n);
char			*ft_hextoa(t_flags *flags, unsigned long long nb);
char			*ft_utoa(unsigned int n);
char			*ft_otoa(t_flags *flags, unsigned long long nb);

#endif
