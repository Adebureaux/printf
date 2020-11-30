/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_xX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:12:29 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/29 16:27:51 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		display_x(unsigned int nb, int alpha)
{
	int		count;
	char	conv_nb;
	char	base[17];

	if (alpha)
		ft_strlcpy(base, "0123456789ABCDEF", 17);
	else
		ft_strlcpy(base, "0123456789abcdef", 17);
	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count += ft_putchar('-');
	}
	if (nb >= 16)
		count += display_x((int)(nb / 16), alpha);
	conv_nb = base[nb % 16];
	count += ft_putchar(conv_nb);
	return (count);
}
