/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_interger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:26:58 by snovaes           #+#    #+#             */
/*   Updated: 2021/07/14 02:32:00 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints decimal and int
*/

static void	verify_print_d_i(t_flags *flags, char *number, int size)
{
	if (flags->negative == 1)
		size = size + 1;
	if (flags->negative == 1)
	{
		ft_putchar(flags, '-');
		print_int(flags, number, size);
	}
	else
		print_uhex(flags, number, size);
	free(number);
}

void	print_d_i(t_flags *flags, long int num)
{
	int		size;
	char	*number;

	flags->count++;
	if (num == INT_MIN)
	{
		num = 2147483648;
		flags->negative = 1;
	}
	if (num < 0)
	{
		flags->negative = 1;
		num = num * (-1);
	}
	number = ft_itoa(num);
	size = (int)ft_strlen(number);
	verify_print_d_i(flags, number, size);
}

void	print_int(t_flags *flags, char *number, int size)
{
	ft_putstr(flags, number, size - 1);
	reset_flags(flags);
}
