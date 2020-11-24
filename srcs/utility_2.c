/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 03:33:07 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/24 19:26:43 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				display_u_size(unsigned int n)
{
	int size;

	size = 1;
	if (!n)
		return (0);
	while (n >= 10)
	{
		size *= 10;
		n /= 10;
	}
	return (size);
}

int				display_u(unsigned int n)
{
	int		count;
	int		size;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count += ft_putchar('-');
	}
	size = display_u_size(n);
	while (size >= 10)
	{
		count += ft_putchar(n / size + '0');
		n %= size;
		size /= 10;
	}
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int		display_x(unsigned int nb)
{
	int		count;
	char	conv_nb;
	char	base[17];

	ft_strlcpy(base, "0123456789abcdef", 17);
	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count += ft_putchar('-');
	}
	if (nb >= 16)
		count += ft_puthex((int)(nb / 16));
	conv_nb = base[nb % 16];
	count += ft_putchar(conv_nb);
	return (count);
}

char	display_p_hex(int n)
{
	if (n >= 0 && n < 10)
		return ('0' + n);
	else
		return ('a' + n - 10);
}

int		display_p(void *ptr)
{
	int			count;
	int			i;
	uintptr_t	p;

	count = 0;
	p = (uintptr_t)ptr;
	count += ft_putstr("0x");
	if (!p)
		return ((count += ft_putchar('0')));
	i = (sizeof(p) << 3) - 20;
	while (i >= 0)
	{
		count += ft_putchar(display_p_hex((p >> i) & 0xf));
		i -= 4;
	}
	return (count);
}
