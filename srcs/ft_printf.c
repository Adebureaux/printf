/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:40:36 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/10 20:35:32 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	init_spec(void)
{
	t_spec spec;

	spec.conv = "cspdiuxX%";
	spec.flag = "-0.*";
	return (spec);
}

int	ft_printf(const char *str, ...)
{
	va_list	vl;
	t_spec	spec;
	int		ret;

	va_start(vl, str);
	spec = init_spec();
	ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == 'c')
				ret += ft_putchar(va_arg(vl, int));
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
