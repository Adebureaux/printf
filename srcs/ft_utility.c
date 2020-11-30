/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:53:40 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/29 17:14:37 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
		count += ft_putchar(str[i++]);
	return (count);
}

int	display_percent(void)
{
	return (ft_putchar('%'));
}
