/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:27:09 by snovaes           #+#    #+#             */
/*   Updated: 2021/06/30 15:27:11 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints %
*/

void	print_percent(t_flags *flags)
{
	int	size;

	size = 1;
	flags->count++;
	if (flags->width <= 0)
		flags->width = size;
	else if (flags->width > size && flags->minus == 0)
	{
		flags->width = flags->width - size;
		print_padding(flags, flags->width);
	}
	ft_putchar(flags, '%');
	if (flags->width > size && flags->minus == 1)
	{
		flags->width = flags->width - size;
		print_padding(flags, flags->width);
	}
	reset_flags(flags);
}
