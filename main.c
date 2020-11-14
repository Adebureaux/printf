#include "srcs/ft_printf.h"

int		main(void)
{
	int i;
	i = 290;

	ft_printf("mine = %d\n", ft_printf("Hi|%u|%i|%x|%i\n", -1, -1, 42, 42));
	ft_printf("real = %d\n", printf("Hi|%u|%i|%x|%i\n", -1, -1, 42, 42));
	return (0);
}
