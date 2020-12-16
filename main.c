#include "includes/ft_printf.h"

int		main(void)
{
	printf("ret = |%d| (real)\n", printf("%7d", -14));
	printf("ret = |%d| (mine)\n", ft_printf("%7d", -14));

	printf("ret = |%d| (real)\n", printf("%-7d", -14));
	printf("ret = |%d| (mine)\n", ft_printf("%-7d", -14));

	printf("ret = |%d| (real)\n", printf("%07d", -14));
	printf("ret = |%d| (mine)\n", ft_printf("%07d", -14));

	printf("ret = |%d| (real)\n", printf("%-7d", -33));
	printf("ret = |%d| (mine)\n", ft_printf("%-7d", -33));

	printf("ret = |%d| (real)\n", printf("%-.7d", -33));
	printf("ret = |%d| (mine)\n", ft_printf("%-.7d", -33));

	printf("ret = |%d| (real)\n", printf("%.5d", -2));
	printf("ret = |%d| (mine)\n", ft_printf("%.5d", -2));

	printf("ret = |%d| (real)\n", printf("%1.5d", 6562));
	printf("ret = |%d| (mine)\n", ft_printf("%1.5d", 6562));

	printf("ret = |%d| (real)\n", printf("%0.5d", -398));
	printf("ret = |%d| (mine)\n", ft_printf("%0.5d", -398));
	return (0);
}
