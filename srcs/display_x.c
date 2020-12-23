/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:12:29 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/23 13:14:22 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	hex_len(t_ptf *ptf, unsigned long int nb)
{
	while ((nb /= 16))
		ptf->hex++;
}
//
// void	hex_prec(t_ptf *ptf, unsigned long int nb)
// {
//
// 	char	str[50];
// 	int		len;
//
// 	len = ptf->hex - 1;
// 	str[len + 1] = '\0';
// 	while (nb)
// 	{
// 		str[len--] = ptf->base[nb % 16];
// 		nb /= 16;
// 	}
// 	ptf->ret += ft_putstr_prec(ptf, str);
// }
//
// void	display_x(t_ptf *ptf, unsigned long int nb)
// {
// 	if (ptf->type == 'X')
// 		ft_strlcpy(ptf->base, "0123456789ABCDEF", 17);
// 	hex_size_prec(ptf, nb);
// 	ptf->prec -= ptf->hex;
// 	ptf->width -= ptf->hex;
// 	if (ptf->prec != -1 && !nb)
// 		ptf->width++;
// 	while (!ptf->align && ptf->width-- > 0)
// 		ptf->ret += ft_putchar(ptf->pad);
// 	if (ptf->prec == -1 && !nb)
// 		ptf->ret += ft_putchar('0');
// 	else if (nb)
// 		hex_prec(ptf, nb);
// 	while (ptf->align && ptf->width-- > 0)
// 		ptf->ret += ft_putchar(' ');
// }

/* ************************************************************************** */

void	ft_puthex_prec(t_ptf *ptf, char *str)
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

void	display_x_after(t_ptf *ptf, char *str, int prec, int n)
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
		ft_puthex_prec(ptf, str);
	while (ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(ptf->pad);
	free(str);
}

void	display_x(t_ptf *ptf, unsigned long int n)
{
	int		prec;
	char	*str;

	if (!ptf->align && !ptf->width && !ptf->prec)
		return ;
	prec = ptf->prec;
	ptf->prec -= hex_len(n, 1);
	ptf->width -= ptf->prec > 0 ? prec : hex_len(n, 1);
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
	display_x_after(ptf, str, prec, n);
}
