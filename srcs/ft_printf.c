/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:40:36 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/16 21:32:21 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_type(t_ptf *ptf)
{
	if (ptf->type == 'c')
		display_c(ptf);
	if (ptf->type == 's')
		display_s(ptf);
	if (ptf->type == 'p')
		display_p(ptf);
	if (ptf->type == 'd' || ptf->type == 'i')
		display_d(ptf);
	if (ptf->type == 'u')
		display_u(ptf);
	if (ptf->type == 'x' || ptf->type == 'X')
		display_x(ptf, va_arg(ptf->vl, unsigned long));
	if (ptf->type == '%')
		display_pct(ptf);
}

char	*parse_spec(t_ptf *ptf, char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i += int_len((ptf->align = 1), 0);
	if (str[i] == '0')
		i += int_len((ptf->pad = '0'), 0);
	if (str[i] == '*')
		i += int_len((ptf->width = ft_abs(ptf, va_arg(ptf->vl, int))), 0);
	else if (ft_isdigit(str[i]))
		i += int_len((ptf->width = ft_atoi(&str[i])), 1);
	i = ft_parse_prec(ptf, str, i);
	ptf->type = str[i];
	//display_ptf(ptf);
	if (!ptf->type || !ft_strchr(ptf->spec, ptf->type))
		return (NULL);
	display_type(ptf);
	return (&str[i]);
}

t_ptf	*init_ptf(void)
{
	t_ptf	*ptf;

	if (!(ptf = (t_ptf*)malloc(sizeof(t_ptf))))
		return (NULL);
	ptf->ret = 0;
	ptf->align = 0;
	ptf->width = 0;
	ptf->prec = -1;
	ptf->hex = 2;
	ptf->pad = ' ';
	ptf->type = '\0';
	ft_strlcpy(ptf->nul, "(null)", 7);
	ft_strlcpy(ptf->spec, "cspdiuxX%", 10);
	ft_strlcpy(ptf->base, "0123456789abcdef", 17);
	return (ptf);
}

int		ft_printf(const char *str, ...)
{
	t_ptf	*ptf;
	int		ret;

	if (!(ptf = init_ptf()))
		return (-1);
	va_start(ptf->vl, str);
	while (*str)
	{
		if (*str == '%' && *str + 1)
		{
			if (!(str = parse_spec(ptf, (char*)++str)))
				return (-1);
			reinit_ptf(ptf);
		}
		else
			ptf->ret += ft_putchar(*str);
		str++;
	}
	va_end(ptf->vl);
	ret = ptf->ret;
	free(ptf);
	return (ret);
}
