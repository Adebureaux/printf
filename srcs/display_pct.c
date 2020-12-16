/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_pct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:28:33 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/16 20:46:50 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void display_pct(t_ptf *ptf)
{
	if (ptf->align)
		ptf->pad = ' ';
	while (!ptf->align && ptf->width-- > 1)
		ptf->ret += ft_putchar(ptf->pad);
	ptf->ret += ft_putchar('%');
	while (ptf->align && ptf->width-- > 1)
		ptf->ret += ft_putchar(ptf->pad);
}
