/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:07:44 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/03 03:49:26 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_c(t_ptf *ptf)
{
	while (!ptf->align && ptf->padding-- > 1)
		ptf->ret += ft_putchar(' ');
	ptf->ret += ft_putchar(va_arg(ptf->vl, int));
	while (ptf->align && ptf->padding-- > 1)
		ptf->ret += ft_putchar(' ');
}
