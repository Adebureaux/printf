/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:07:44 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/16 20:10:29 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_c(t_ptf *ptf)
{
	while (!ptf->align && ptf->width-- > 1)
		ptf->ret += ft_putchar(' ');
	ptf->ret += ft_putchar(va_arg(ptf->vl, int));
	while (ptf->align && ptf->width-- > 1)
		ptf->ret += ft_putchar(' ');
}
