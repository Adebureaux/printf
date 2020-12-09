/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ptf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 05:24:11 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/01 22:56:11 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_ptf(t_ptf *ptf)
{
	printf("ret = %d\n", ptf->ret);
	printf("padding = %d\n", ptf->padding);
	printf("align = %d\n", ptf->align);
	printf("width = %d\n", ptf->width);
	printf("prec = %d\n", ptf->prec);
	if (!ptf->pad)
		printf("pad = null\n");
	else
		printf("pad = %c\n", ptf->pad);
	if (!ptf->type)
		printf("type = null\n");
	else
		printf("type = %c\n", ptf->type);
}
