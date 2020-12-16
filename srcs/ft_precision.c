/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 03:44:26 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/16 16:29:28 by adeburea         ###   ########.fr       */
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

int		ft_strlen_prec(t_ptf *ptf, char *str)
{
	int i;

	i = 0;
	if (ptf->prec == -1)
		return (ft_strlen(str));
	while (str[i] && i < ptf->prec)
		i++;
	return (i);
}

int		ft_parse_prec(t_ptf *ptf, char *str, int i)
{
	if (str[i] == '.')
	{
		if (str[++i] == '*')
			i += int_len((ptf->prec = ft_abs(ptf, va_arg(ptf->vl, int))), 0);
		else if (ft_isdigit(str[i]))
		{
			if (str[i] == '0')
			{
				ptf->prec = 0;
				i++;
			}
			if (ft_isdigit(str[i]))
				i += int_len((ptf->prec = ft_atoi(&str[i])), 1);
		}
		else
			ptf->prec = 0;
	}
	return (i);
}
