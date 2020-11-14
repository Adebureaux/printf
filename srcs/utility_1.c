/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:25:32 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/10 20:33:44 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int				ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int				ft_putnbr_size(int n)
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

int				ft_putnbr(int n)
{
	int		count;
	int		size;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count += ft_putchar('-');
	}
	size = ft_putnbr_size(n);
	while (size >= 10)
	{
		count += ft_putchar(n / size + '0');
		n %= size;
		size /= 10;
	}
	count += ft_putchar(n % 10 + '0');
	return (count);
}
