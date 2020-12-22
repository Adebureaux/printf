/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:10:17 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/22 18:59:28 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_prec(t_ptf *ptf, char *str, int prec)
{
	if (prec < 0)
		ptf->ret += ft_putstr(str);
	else
	{
		while (prec-- > 0)
			ptf->ret += ft_putchar('0');
		ptf->ret += ft_putstr(str);
	}
}

void	display_d(t_ptf *ptf)
{
	int		n;
	int		len;
	char	*str;

	n = va_arg(ptf->vl, int);
	len = int_len(n, 1);
	ptf->width -= ptf->prec - len > 0 ? ptf->prec : len;
	if (!(str = ft_itoa(n)))
		return ;
	if ((ptf->align) || (ptf->pad == '0' && ptf->width > 0 && ptf->prec > 0))
		ptf->pad = ' ';
	if (n < 0 && ptf->prec - len > 0)
	{
		ptf->prec++;
		ptf->width--;
	}
	if (n < 0 && ptf->width > 0
		&& (ptf->pad == '0' || ptf->align) && ptf->prec - len < 0)
	{
		ptf->ret += ft_putchar('-');
		ft_memmove(str, str + 1, ft_strlen(str));
	}
	while (!ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(ptf->pad);
	if (n < 0 && ptf->prec > 0)
	{
		ptf->ret += ft_putchar('-');
		ft_memmove(str, str + 1, ft_strlen(str));
	}
	if (!n && !ptf->prec)
		ptf->ret += ft_putchar(' ');
	else
		ft_putnbr_prec(ptf, str, ptf->prec - len);
	while (ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(ptf->pad);
	free(str);
}
