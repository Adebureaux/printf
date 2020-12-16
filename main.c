#include "includes/ft_printf.h"

int		main(void)
{
	printf("ret = |%d| (real)\n", printf("%10.03s", NULL));
	printf("ret = |%d| (mine)\n", ft_printf("%10.03s", NULL));
	return (0);
}
