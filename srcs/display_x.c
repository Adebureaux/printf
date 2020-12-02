/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:12:29 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/02 03:16:33 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_x(t_ptf *ptf, unsigned int nb)
{
	char base[17];

	if (ptf->type == 'X')
		ft_strlcpy(base, "0123456789ABCDEF", 17);
	else
		ft_strlcpy(base, "0123456789abcdef", 17);
	if (nb >= 16)
		display_x(ptf, (int)(nb / 16));
	ptf->ret += ft_putchar((char)base[nb % 16]);
}
