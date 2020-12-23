/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:12:29 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/23 15:02:21 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		hex_len(unsigned long int nb)
{
	int		i;

	i = 1;
	while ((nb /= 16))
		i++;
	return (i);
}

void	*ft_itoa_hex(t_ptf *ptf, unsigned long int nb)
{
	char		*str;
	int			len;

	len = hex_len(nb);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = ptf->base[nb % 16];
		nb /= 16;
	}
	return (str);
}

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
	while (!ptf->align && ptf->width-- > 0)
		ptf->ret += ft_putchar(ptf->pad);
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

	if (ptf->type == 'X')
		ft_strlcpy(ptf->base, "0123456789ABCDEF", 17);
	if (!ptf->align && !ptf->width && !ptf->prec)
		return ;
	prec = ptf->prec;
	ptf->prec -= hex_len(n);
	ptf->width -= ptf->prec > 0 ? prec : hex_len(n);
	if (!(str = ft_itoa_hex(ptf, n)))
		return ;
	if ((ptf->align) || (ptf->pad == '0' && ptf->width > 0 && prec > 0)
		|| (!n && !prec))
		ptf->pad = ' ';
	display_x_after(ptf, str, prec, n);
}
