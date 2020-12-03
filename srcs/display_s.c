/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:08:54 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/03 03:49:56 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_s(t_ptf *ptf)
{
	char	*str;
	int		len;

	str = va_arg(ptf->vl, char*);
	len = str ? ft_strlen(str) : 6;
	while (!ptf->align && ptf->padding-- > len)
		ptf->ret += ft_putchar(' ');
	if (!str)
		ptf->ret += ft_putstr_prec(ptf, "(null)");
	else
		ptf->ret += ft_putstr_prec(ptf, str);
	while (ptf->align && ptf->padding-- > len)
		ptf->ret += ft_putchar(' ');
}
