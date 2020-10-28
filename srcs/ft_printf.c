/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:40:36 by adeburea          #+#    #+#             */
/*   Updated: 2020/10/28 18:00:46 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	vl;
	int		ret;

	va_start(vl, str);
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
			else if (*(str + 1) == 'd')
				ret += ft_putnbr(va_arg(vl, int));
			else if (*(str + 1) == 'i' || *(str + 1) == 'u')
				ret += ft_putnbr(va_arg(vl, unsigned));
			else if (*(str + 1) == 'x' || *(str + 1) == 'X')
				ret += ft_putnbr(va_arg(vl, int));
			str += 2;
		}
		else
			ret += ft_putchar(*str++);
	}
	va_end(vl);
	return (ret);
}
