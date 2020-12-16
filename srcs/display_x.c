/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:12:29 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/16 19:33:27 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	recursive_hex_size(t_ptf *ptf, unsigned long int nb)
{
	if (nb >= 16)
		recursive_hex_size(ptf, (unsigned long int)(nb / 16));
	ptf->hex++;
}

void	recursive_hex(t_ptf *ptf, unsigned long int nb)
{
	if (nb >= 16)
		recursive_hex(ptf, (unsigned long int)(nb / 16));
	ptf->ret += ft_putchar((char)ptf->base[nb % 16]);
}

void	display_x(t_ptf *ptf, unsigned long int nb)
{
	if (ptf->type == 'X')
		ft_strlcpy(ptf->base, "0123456789ABCDEF", 17);
	recursive_hex(ptf, nb);
}
