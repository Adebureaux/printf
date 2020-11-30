/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:11:12 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/29 16:28:33 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	p_hex(int n)
{
	if (n >= 0 && n < 10)
		return ('0' + n);
	else
		return ('a' + n - 10);
}

int		display_p(void *ptr)
{
	int			count;
	int			i;
	uintptr_t	p;

	count = 0;
	p = (uintptr_t)ptr;
	count += ft_putstr("0x");
	if (!p)
		return ((count += ft_putchar('0')));
	i = (sizeof(p) << 3) - 20;
	while (i >= 0)
	{
		count += ft_putchar(p_hex((p >> i) & 0xf));
		i -= 4;
	}
	return (count);
}
