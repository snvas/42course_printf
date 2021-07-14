/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_charstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:35:39 by nbarreir          #+#    #+#             */
/*   Updated: 2021/07/14 02:32:38 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints chars
*/

void	print_char(t_flags *flags, int c)
{
	flags->count++;
	ft_putchar(flags, c);
	reset_flags(flags);
}

/*
** Prints strings
*/

void	print_str(t_flags *flags, char *s)
{
	int	size;

	if (!s)
		s = "(null)";
	size = (int)ft_strlen(s);
	flags->count++;
	ft_putstr(flags, s, size);
	reset_flags(flags);
}
