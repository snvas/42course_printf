/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_star.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:02:55 by snovaes           #+#    #+#             */
/*   Updated: 2021/07/09 18:06:19 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	get_flag_star(t_flags *flags, va_list args, int *star)
{
	*star = va_arg(args, int);
	if (*star < 0)
	{
		if (flags->dot == 0)
		{
			flags->asterisk = 1;
			flags->minus = 1;
			flags->padding = ' ';
			*star = *star * (-1);
		}
		else
			flags->dot = 0;
	}
	flags->count++;
}

void	print_padding(t_flags *flags, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar(flags, flags->padding);
		i++;
	}
}

void	reset_flags(t_flags *flags)
{
	flags->negative = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->minus = 0;
	flags->dot = 0;
	flags->asterisk = 0;
}
