/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:58:26 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/24 19:27:30 by adeburea         ###   ########.fr       */
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
	char	*conv;
	char	*flag;
	int		(*ptr[6])();
	int		(*c)(char);
	int		(*s)(char*);
	int		(*p)(void*);
	int		(*d)(int);
	int		(*u)(unsigned int);
	int		(*x)(unsigned int);
};
int				ft_printf(const char *str, ...);
int				display_c(int c);
int				display_s(char *s);
int				display_p(void *ptr);
int				display_d(int n);
int				display_u(unsigned int n);
int				display_x(unsigned int nb);

#endif
