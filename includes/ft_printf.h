/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:58:26 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/03 03:46:44 by adeburea         ###   ########.fr       */
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
	int		align;
	int		width;
	int		prec;
	char	pad;
	char	type;
	char	spec[10];
	va_list	vl;
};
int				ft_printf(const char *str, ...);
int				ft_putchar(int c);
int				ft_putstr(char *str);
int				int_len(int n, int flag);
int				ft_abs(t_ptf *ptf, int n);
int				ft_putstr_prec(t_ptf *ptf, char *str);
void			reinit_ptf(t_ptf *ptf);
void			display_c(t_ptf *ptf);
void			display_s(t_ptf *ptf);
void			display_p(t_ptf *ptf);
void			display_d(t_ptf *ptf);
void			display_u(t_ptf *ptf);
void			display_x(t_ptf *ptf, unsigned int nb);
void			display_ptf(t_ptf *ptf);

#endif
