#include "includes/ft_printf.h"

int		main(void)
{
	//ici
	printf("ret = |%d| (real)\n", printf("%10.5d", -216));
	printf("ret = |%d| (mine)\n", ft_printf("%10.5d", -216));

	printf("ret = |%d| (real)\n", printf("%7d", -14));
	printf("ret = |%d| (mine)\n", ft_printf("%7d", -14));

	printf("ret = |%d| (real)\n", printf("%7d", -14));
	printf("ret = |%d| (mine)\n", ft_printf("%7d", -14));

	printf("ret = |%d| (real)\n", printf("%-7d", -14));
	printf("ret = |%d| (mine)\n", ft_printf("%-7d", -14));

	//ici
	printf("ret = |%d| (real)\n", printf("%07d", -14));
	printf("ret = |%d| (mine)\n", ft_printf("%07d", -14));

	printf("ret = |%d| (real)\n", printf("%-7d", 33));
	printf("ret = |%d| (mine)\n", ft_printf("%-7d", 33));

	printf("ret = |%d| (real)\n", printf("%-.7d", -33));
	printf("ret = |%d| (mine)\n", ft_printf("%-.7d", -33));

	printf("ret = |%d| (real)\n", printf("%.5d", -2));
	printf("ret = |%d| (mine)\n", ft_printf("%.5d", -2));

	printf("ret = |%d| (real)\n", printf("%.6d", 6562));
	printf("ret = |%d| (mine)\n", ft_printf("%.6d", 6562));

	//ici
	printf("ret = |%d| (real)\n", printf("%0.5d", -398));
	printf("ret = |%d| (mine)\n", ft_printf("%0.5d", -398));

	//ici
	printf("ret = |%d| (real)\n", printf("%9.5d", -398));
	printf("ret = |%d| (mine)\n", ft_printf("%9.5d", -398));

	//ici
	printf("ret = |%d| (real)\n", printf("%-9.5d", -398));
	printf("ret = |%d| (mine)\n", ft_printf("%-9.5d", -398));

	printf("ret = |%d| (real)\n", printf("%4.10d", 398));
	printf("ret = |%d| (mine)\n", ft_printf("%4.10d", 398));

	printf("ret = |%d| (real)\n", printf("%0-3.3d", 6983));
	printf("ret = |%d| (mine)\n", ft_printf("%0-3.3d", 6983));

	printf("ret = |%d| (real)\n", printf("%-03.3d", -8462));
	printf("ret = |%d| (mine)\n", ft_printf("%-03.3d", -8462));

	printf("ret = |%d| (real)\n", printf("%0-3.3d", -8462));
	printf("ret = |%d| (real)\n", ft_printf("%0-3.3d", -8462));
	return (0);
}
