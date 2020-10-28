/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_piu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 03:33:07 by adeburea          #+#    #+#             */
/*   Updated: 2020/10/28 17:57:20 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_hex(int n)
{
	if (n >= 0 && n < 10)
		return '0' + n;
	else
		return 'a' + n - 10;
}

int		ft_putaddress(void* ptr)
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
		count += ft_putchar(ft_hex((p >> i) & 0xf));
		i -= 4;
	}
	return (count);
}
