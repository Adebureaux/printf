/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:10:17 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/29 16:22:13 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				d_size(int n)
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

int				display_d(int n)
{
	int		count;
	int		size;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count += ft_putchar('-');
	}
	size = d_size(n);
	while (size >= 10)
	{
		count += ft_putchar(n / size + '0');
		n %= size;
		size /= 10;
	}
	count += ft_putchar(n % 10 + '0');
	return (count);
}
