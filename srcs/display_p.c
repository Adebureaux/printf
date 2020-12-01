/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:11:12 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/01 22:59:46 by adeburea         ###   ########.fr       */
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

void	display_p(t_ptf *ptf)
{
	int			i;
	uintptr_t	p;

	p = (uintptr_t)va_arg(ptf->vl, void*);
	ptf->ret += ft_putstr("0x");
	if (!p)
	{
		ptf->ret += ft_putchar('0');
		return ;
	}
	i = (sizeof(p) << 3) - 20;
	while (i >= 0)
	{
		ptf->ret += ft_putchar(p_hex((p >> i) & 0xf));
		i -= 4;
	}
}
