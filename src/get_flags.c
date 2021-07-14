/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:14:14 by snovaes           #+#    #+#             */
/*   Updated: 2021/07/14 14:11:33 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flags(t_flags *flags, va_list args)
{
	if (flags->type == '%')
		print_percent(flags);
	else if (flags->type == 'c')
		print_char(flags, (va_arg(args, int)));
	else if (flags->type == 's')
		print_str(flags, (va_arg(args, char *)));
	else if (flags->type == 'd' || flags->type == 'i')
		print_d_i(flags, (va_arg(args, int)));
	else if (flags->type == 'u')
		print_du(flags, (va_arg(args, unsigned)));
	else if (flags->type == 'x' || flags->type == 'X')
		print_hex(flags, (va_arg(args, unsigned int)));
	else if (flags->type == 'p')
		print_pointer(flags, (va_arg(args, unsigned long)));
}

void	get_specs(const char *str, t_flags *flags, va_list args)
{
	if (str[flags->count] == 'c')
		flags->type = 'c';
	else if (str[flags->count] == 'd')
		flags->type = 'd';
	else if (str[flags->count] == 'i')
		flags->type = 'i';
	else if (str[flags->count] == 's')
		flags->type = 's';
	else if (str[flags->count] == 'p')
		flags->type = 'p';
	else if (str[flags->count] == 'u')
		flags->type = 'u';
	else if (str[flags->count] == 'x')
		flags->type = 'x';
	else if (str[flags->count] == 'X')
		flags->type = 'X';
	else if (str[flags->count] == '%')
		flags->type = '%';
	print_flags(flags, args);
}

void	get_flag_a(const char *str, t_flags *flags, va_list args)
{
	if (str[flags->count] == '.')
	{
		flags->dot = 1;
		flags->count++;
		if (str[flags->count] == '*')
			get_flag_star(flags, args, &flags->precision);
		else if (is_number(str, flags) == 1)
			flags->precision = flags->number;
		else
			flags->precision = 0;
	}
	get_specs(str, flags, args);
}

void	get_flags(const char *str, t_flags *flags, va_list args)
{
	while (str[flags->count] == '0' || str[flags->count] == '-')
	{
		if (str[flags->count] == '0' && flags->minus == 0)
		{
			flags->zero = 1;
			flags->minus = 0;
			flags->padding = '0';
		}
		else if (str[flags->count] == '-')
		{
			flags->zero = 0;
			flags->minus = 1;
			flags->padding = ' ';
		}
		flags->count++;
	}
	if (str[flags->count] == '*')
		get_flag_star(flags, args, &flags->width);
	else if (is_number(str, flags) == 1)
		flags->width = flags->number;
	get_flag_a(str, flags, args);
}
