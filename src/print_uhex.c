/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:30:32 by snovaes           #+#    #+#             */
/*   Updated: 2021/07/14 14:10:29 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints unsigned int
*/

void	print_du(t_flags *flags, unsigned int num)
{
	int		size;
	char	*number;

	flags->count++;
	if (flags->dot == 1)
	{
		flags->zero = 0;
		flags->padding = ' ';
	}
	number = ft_utoa(num);
	size = (int)ft_strlen(number);
	if (num == 0 && flags->dot == 1)
		size = 0;
	print_uhex(flags, number, size);
	free(number);
}

/*
** Deals with precision for u and hexadecimals
*/

static void	precision_uhex(t_flags *flags, char *number, int size)
{
	if (flags->dot == 1 && flags->precision > size)
	{
		flags->padding = '0';
		print_padding(flags, flags->precision - size);
	}
	if (flags->dot == 1 && flags->precision <= 0 && *number == '0')
	{
		if (flags->width > size && flags->minus == 1)
		{
			flags->padding = ' ';
			if (flags->precision > size)
				flags->width = flags->width - flags->precision;
			else
				flags->width = flags->width - size;
			print_padding(flags, flags->width);
		}
		reset_flags(flags);
	}
}

void	print_uhex(t_flags *flags, char *number, int size)
{
	if (flags->width <= 0)
		flags->width = size;
	else if (flags->width > size && flags->minus == 0)
	{
		if (flags->precision > size)
			flags->width = flags->width - flags->precision;
		else
			flags->width = flags->width - size;
		print_padding(flags, flags->width);
	}
	precision_uhex(flags, number, size);
	ft_putstr(flags, number, size);
	if (flags->width > size && flags->minus == 1)
	{
		flags->padding = ' ';
		if (flags->precision > size)
			flags->width = flags->width - flags->precision;
		else
			flags->width = flags->width - size;
		print_padding(flags, flags->width);
	}
	reset_flags(flags);
}

/*
** Prints hexadecimals x and X
*/

void	print_hex(t_flags *flags, unsigned int num)
{
	int				size;
	char			*number;

	flags->count++;
	if (flags->dot == 1)
	{
		flags->zero = 0;
		flags->padding = ' ';
	}
	number = ft_hextoa(flags, (unsigned long long)num);
	size = (int)ft_strlen(number);
	if (num == 0 && flags->dot == 1)
		size = 0;
	print_uhex(flags, number, size);
	free(number);
}
