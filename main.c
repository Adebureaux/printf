#include "srcs/ft_printf.h"

int		main(void)
{
	unsigned int i = 133;

	ft_printf("mine = %d\n", ft_printf("Hi|%x\n", i));
	ft_printf("real = %d\n", printf("Hi|%i\n", i));
	// printf("real one : |%s|slt|%d||%c|slt|%d|\n", c, 1, c[1], 1);
	// ft_printf("my one   : |%s|slt|%d||%c|slt|%d|\n", c, 1, c[1], 1);
	return (0);
}
