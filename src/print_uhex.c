/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:30:32 by snovaes           #+#    #+#             */
/*   Updated: 2021/07/14 02:29:26 by snovaes          ###   ########.fr       */
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
	number = ft_utoa(num);
	size = (int)ft_strlen(number);
	if (num == 0)
		size = 0;
	print_uhex(flags, number, size);
	free(number);
}

void	print_uhex(t_flags *flags, char *number, int size)
{
	ft_putstr(flags, number, size);
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
	number = ft_hextoa(flags, (unsigned long long)num);
	size = (int)ft_strlen(number);
	if (num == 0)
		size = 0;
	print_uhex(flags, number, size);
	free(number);
}
