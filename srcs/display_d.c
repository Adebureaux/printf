/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:10:17 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/23 15:46:32 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_prec(t_ptf *ptf, char *str)
{
	if (ptf->prec < 0)
		ptf->ret += ft_putstr(str);
	else
	{
		while (ptf->prec-- > 0)
			ptf->ret += ft_putchar('0');
		ptf->ret += ft_putstr(str);
	}
}

void	display_d_after(t_ptf *ptf, char *str, int prec, int n)
{
	if (n < 0 && ptf->width > 0
		&& (ptf->pad == '0' || ptf->align) && ptf->prec < 0)
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
	if (!n && !prec)
		ptf->ret += ft_putchar(' ');
	else
		ft_putnbr_prec(ptf, str);
	while (ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(ptf->pad);
	free(str);
}

void	display_d(t_ptf *ptf)
{
	int		n;
	int		prec;
	char	*str;

	n = va_arg(ptf->vl, int);
	if (!ptf->align && !ptf->width && !ptf->prec && !n)
		return ;
	prec = ptf->prec;
	ptf->prec -= int_len(n, 1);
	ptf->width -= ptf->prec > 0 ? prec : int_len(n, 1);
	if (!(str = ft_itoa(n)))
		return ;
	if ((ptf->align) || (ptf->pad == '0' && ptf->width > 0 && prec > 0)
		|| (!n && !prec))
		ptf->pad = ' ';
	if (n < 0 && ptf->prec > 0)
	{
		ptf->prec++;
		ptf->width--;
	}
	display_d_after(ptf, str, prec, n);
}
