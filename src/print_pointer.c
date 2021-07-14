/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:23:50 by snovaes           #+#    #+#             */
/*   Updated: 2021/07/14 12:51:31 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(t_flags *flags, char *ptr, int size)
{
	ft_putstr(flags, "0x", 2);
	ft_putstr(flags, ptr, size - 2);
	reset_flags(flags);
}

/*
** Prints pointers
*/

void	print_pointer(t_flags *flags, unsigned long pointer)
{
	int				size;
	char			*ptr;

	flags->count++;
	ptr = ft_hextoa(flags, pointer);
	size = (int)ft_strlen(ptr) + 2;
	if ((pointer == 0))
		size = 2;
	print_ptr(flags, ptr, size);
	free(ptr);
}
