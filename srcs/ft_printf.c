/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:40:36 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/24 19:24:03 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ptf	init_ptf(void)
{
	t_ptf ptf;

	ptf.conv = "cspdiuxX%";
	ptf.flag = "-0.*";
	ptf.ptr[0] = &display_c;
	ptf.ptr[1] = &display_s;
	ptf.ptr[2] = &display_p;
	ptf.ptr[3] = &display_d;
	ptf.ptr[4] = &display_u;
	ptf.ptr[5] = &display_x;
	return (ptf);
}

int	ft_printf(const char *str, ...)
{
	va_list	vl;
	t_ptf	ptf;
	int		ret;

	va_start(vl, str);
	ptf = init_ptf();
	ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == 'c')
				ret += (ptf.ptr[0](va_arg(vl, int)));
			else if (*(str + 1) == 's')
				ret += ft_putstr(va_arg(vl, char*));
			else if (*(str + 1) == 'p')
				ret += ft_putaddress(va_arg(vl, void*));
			else if (*(str + 1) == 'd' || *(str + 1) == 'i')
				ret += ft_putnbr(va_arg(vl, int));
			else if (*(str + 1) == 'u')
				ret += ft_putnbr_u(va_arg(vl, unsigned));
			else if (*(str + 1) == 'x' || *(str + 1) == 'X')
				ret += ft_puthex(va_arg(vl, int));
			else if (*(str + 1) == '%')
				ret += ft_putchar('%');
			str += 2;
		}
		else
			ret += ft_putchar(*str++);
	}
	va_end(vl);
	return (ret);
}
