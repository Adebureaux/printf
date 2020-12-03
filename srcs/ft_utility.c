/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:53:40 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/03 03:25:48 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int		ft_abs(t_ptf *ptf, int n)
{
	if (n < 0)
	{
		ptf->align = 1;
		return (-n);
	}
	return (n);
}

int		int_len(int n, int flag)
{
	int		len;

	if (!flag)
		return (1);
	len = 1;
	n < 0 ? len++ : 0;
	while ((n /= 10))
		len++;
	return (len);
}

void	reinit_ptf(t_ptf *ptf)
{
	ptf->padding = 0;
	ptf->align = 0;
	ptf->width = 0;
	ptf->prec = -1;
	ptf->pad = ' ';
	ptf->type = '\0';
}
