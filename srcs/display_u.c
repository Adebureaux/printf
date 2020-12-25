/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:14:58 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/25 15:57:05 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_prec_u(t_ptf *ptf, char *str)
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

void	display_u_after(t_ptf *ptf, char *str, unsigned int n, int prec)
{
	while (!ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(ptf->pad);
	if (!n && !prec)
		ptf->ret += ft_putchar(' ');
	else
		ft_putnbr_prec_u(ptf, str);
	while (ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(' ');
	free(str);
}

void	display_u(t_ptf *ptf)
{
	unsigned int		n;
	int					prec;
	char				*str;

	n = va_arg(ptf->vl, unsigned);
	if (!ptf->align && !ptf->width && !ptf->prec && !n)
		return ;
	prec = ptf->prec;
	ptf->prec -= int_len(n, 1);
	ptf->width -= ptf->prec > 0 ? prec : int_len(n, 1);
	if (!(str = ft_itoa(n)))
		return ;
	if ((ptf->align) || (ptf->pad == '0' && prec >= 0) || (!n && !prec))
		ptf->pad = ' ';
	display_u_after(ptf, str, n, prec);
}
