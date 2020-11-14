/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:58:26 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/14 19:24:09 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_spec	t_spec;
struct			s_spec
{
	char	*conv;
	char	*flag;
};
int				ft_printf(const char *str, ...);
int				ft_putaddress(void *ptr);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putnbr(int n);
unsigned int	ft_putnbr_u(unsigned int n);
int				ft_puthex(unsigned int nb);

#endif
