/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:11:12 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/26 12:22:07 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_p(t_ptf *ptf)
{
	unsigned long int	p;

	p = (unsigned long int)va_arg(ptf->vl, void*);
	hex_size(ptf, p);
	ptf->width -= ptf->hex + 1;
	if (ptf->prec != -1 && !p)
		ptf->width++;
	while (!ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(' ');
	ptf->ret += ft_putstr("0x");
	if (ptf->prec < 0 && !p)
		ptf->ret += ft_putchar('0');
	else if (p)
		hex(ptf, p);
	while (ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(' ');
}
