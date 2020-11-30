/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:40:36 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/30 02:10:49 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse_str(va_list vl, t_ptf ptf, char *str)
{
	ptf.prec = 0;
	(void)str;
	display_c(ptf, va_arg(vl, int));
	return (1);
}

t_ptf	init_ptf(void)
{
	t_ptf	ptf;

	ptf.ret = 0;
	return (ptf);
}

int		ft_printf(const char *str, ...)
{
	va_list	vl;
	t_ptf	ptf;

	va_start(vl, str);
	ptf = init_ptf();
	while (*str)
	{
		if (*str == '%' && *str + 1)
			ptf.ret += parse_str(vl, ptf, (char*)++str);
		else
			ptf.ret += ft_putchar(*str);
		str++;
	}
	va_end(vl);
	return (ptf.ret);
}
