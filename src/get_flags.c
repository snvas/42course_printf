/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:14:14 by snovaes           #+#    #+#             */
/*   Updated: 2021/07/14 02:34:09 by snovaes          ###   ########.fr       */
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

void	get_flags(const char *str, t_flags *flags, va_list args)
{
	while (str[flags->count] == '0')
	{
		flags->count++;
	}
	if (is_number(str, flags) == 1)
		flags->width = flags->number;
	get_specs(str, flags, args);
}

int	is_number(const char *str, t_flags *flags)
{
	flags->number = 0;
	if (!(ft_isdigit((int)str[flags->count])))
		return (0);
	while (ft_isdigit((int)str[flags->count]))
	{
		flags->number = ((flags->number) * 10) + (int)str[flags->count] - '0';
		flags->count++;
	}
	return (1);
}

void	reset_flags(t_flags *flags)
{
	flags->negative = 0;
}
