/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:10:17 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/17 23:27:42 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_prec(t_ptf *ptf, char *str, int n)
{
	if (ptf->prec < 0)
		ptf->ret += ft_putstr(str);
	else
	{
		while (ptf->prec-- > 0)
			ptf->ret += ft_putchar('0');
		ptf->ret += ft_putstr(str);
	}
	n = 0;
}

void	display_d(t_ptf *ptf)
{
	int		n;
	char	*str;

	n = va_arg(ptf->vl, int);
	ptf->prec -= int_len(n, 1);
	ptf->width -= ptf->prec > 0 ? ptf->prec + int_len(n, 1) : int_len(n, 1);
	if (!(str = ft_itoa(n)))
		return ;
	if (n < 0 && ptf->prec > 0)
	{
		ptf->prec++;
		ptf->width--;
	}
	if (n < 0 && (ptf->width > 0 || ptf->prec > 0) && (ptf->pad = '0' || ptf->align))
	{
		ptf->ret += ft_putchar('-');
		n *= -n;
	}
	while (!ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(ptf->pad);
	ft_putnbr_prec(ptf, str, n);
	while (ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(ptf->pad);
	free(str);
}
