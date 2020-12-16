/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:10:17 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/16 23:08:41 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_d_flag(t_ptf *ptf, char *str)
{
	if (ptf->pad == '0')
	{
		ptf->ret += ft_putchar('-');
		ft_memmove(str, str + 1, ft_strlen(str) - 1);
	}
	if (ptf->prec != -1)
	{
			ptf->pad = '0';
			ptf->width = ptf->prec;
			ptf->ret += ft_putchar('-');
			ft_memmove(str, str + 1, ft_strlen(str) - 1);
	}
}

void	display_d(t_ptf *ptf)
{
	int		n;
	char	*str;

	n = va_arg(ptf->vl, int);
	ptf->width -= int_len(n, 1);
	if (!(str = ft_itoa(n)))
		return ;
	display_d_flag(ptf, str);
	while (!ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(ptf->pad);
	ptf->ret += ft_putstr_prec(ptf, str);
	while (ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(ptf->pad);
	free(str);
}
