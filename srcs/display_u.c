/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:14:58 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/01 23:01:38 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		u_size(unsigned int n)
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

void	display_u(t_ptf *ptf)
{
	int				size;
	unsigned int	n;

	n = va_arg(ptf->vl, unsigned);
	if (n < 0)
	{
		n *= -1;
		ptf->ret += ft_putchar('-');
	}
	size = u_size(n);
	while (size >= 10)
	{
		ptf->ret += ft_putchar(n / size + '0');
		n %= size;
		size /= 10;
	}
	ptf->ret += ft_putchar(n % 10 + '0');
}
