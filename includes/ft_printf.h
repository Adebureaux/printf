/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:58:26 by adeburea          #+#    #+#             */
/*   Updated: 2020/12/23 13:09:23 by adeburea         ###   ########.fr       */
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
	int		align;
	int		width;
	int		prec;
	int		hex;
	char	pad;
	char	type;
	char	nul[7];
	char	spec[10];
	char	base[17];
	va_list	vl;
};
int				ft_printf(const char *str, ...);
int				ft_putchar(int c);
int				ft_putstr(char *str);
int				int_len(long long n, int flag);
int				ft_abs(t_ptf *ptf, int n);
int				ft_putstr_prec(t_ptf *ptf, char *str);
int				ft_strlen_prec(t_ptf *ptf, char *str);
int				ft_parse_prec(t_ptf *ptf, char *str, int i);
void			reinit_ptf(t_ptf *ptf);
void			display_pct(t_ptf *ptf);
void			display_c(t_ptf *ptf);
void			display_s(t_ptf *ptf);
void			display_p(t_ptf *ptf);
void			display_d(t_ptf *ptf);
void			display_u(t_ptf *ptf);
void			display_x(t_ptf *ptf, unsigned long int n);
void			hex(t_ptf *ptf, unsigned long int nb);
void			hex_size(t_ptf *ptf, unsigned long int nb);
void			display_ptf(t_ptf *ptf);

#endif
