/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:08:54 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/22 21:41:11 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_s(t_ptf *ptf)
{
	char	*str;

	str = va_arg(ptf->vl, char*);
	str = str ? str : ptf->nul;
	ptf->width -= ft_strlen_prec(ptf, str);
	while (!ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(ptf->pad);
	ptf->ret += ft_putstr_prec(ptf, str);
	while (ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(' ');
}
