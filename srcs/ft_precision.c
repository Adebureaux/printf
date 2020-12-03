/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 03:44:26 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/03 03:55:29 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putstr_prec(t_ptf *ptf, char *str)
{
	int i;

	i = 0;
	if (ptf->prec == -1)
		ptf->ret += ft_putstr(str);
	else
		while (str[i] && i < ptf->prec)
			ft_putchar(str[i++]);
	return (i);
}
