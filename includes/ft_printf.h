/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:58:26 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/29 17:33:21 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_ptf	t_ptf;
struct			s_ptf
{
	int		ret;
	int		padding;
	int		width;
	int		prec;
	char	conv;
};
int				ft_printf(const char *str, ...);
int				ft_putchar(int c);
int				ft_putstr(char *str);
void			display_c(t_ptf ptf, int c);
void			display_s(t_ptf ptf, char *s);
int				display_p(void *ptr);
int				display_d(int n);
int				display_u(unsigned int n);
int				display_x(unsigned int nb, int alpha);
int				display_percent(void);

#endif
