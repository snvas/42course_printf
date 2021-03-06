/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:12:00 by snovaes           #+#    #+#             */
/*   Updated: 2021/07/14 02:26:22 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	reset_types(t_flags *flags)
{
	flags->type = 0;
	flags->count = 0;
	flags->len = 0;
	flags->number = 0;
	flags->negative = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->padding = ' ';
	flags->precision = -1;
	flags->dot = 0;
	flags->asterisk = 0;
}

int	ft_printf(const char *input, ...)
{
	const char	*str;
	t_flags		flags;
	va_list		args;

	va_start(args, input);
	reset_types(&flags);
	str = ft_strdup(input);
	if (!str)
		return (0);
	while (str[flags.count])
	{
		if (str[flags.count] == '%')
		{
			flags.count++;
			get_flags(str, &flags, args);
		}
		else
		{
			ft_putchar(&flags, str[flags.count]);
			flags.count++;
		}
	}
	free((char *)str);
	va_end(args);
	return (flags.len);
}
