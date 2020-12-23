/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:41:44 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/23 11:46:51 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	hex_size(t_ptf *ptf, unsigned long int nb)
{
	if (nb >= 16)
		hex_size(ptf, (unsigned long int)(nb / 16));
	ptf->hex++;
}

void	hex(t_ptf *ptf, unsigned long int nb)
{
	if (nb >= 16)
		hex(ptf, (unsigned long int)(nb / 16));
	ptf->ret += ft_putchar((char)ptf->base[nb % 16]);
}
