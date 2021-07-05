/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:35:31 by snovaes           #+#    #+#             */
/*   Updated: 2021/07/01 22:06:09 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Converts input into octal o
*/

static char	*otoa_a(char *str, t_flags *flags, unsigned long long temp,
					int count)
{
	while (temp != 0)
	{
		if ((flags->type == 'o') && (temp % 8) >= 10)
			str[count - 1] = (temp % 8) + 87;
		else
			str[count - 1] = (temp % 8) + 48;
		temp = temp / 8;
		count--;
	}
	return (str);
}

char	*ft_otoa(t_flags *flags, unsigned long long nb)
{
	int					count;
	char				*str;
	unsigned long long	temp;

	temp = nb;
	count = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb != 0)
	{
		nb = nb / 8;
		count++;
	}
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	str = otoa_a(str, flags, temp, count);
	return (str);
}
