#include "includes/ft_printf.h"

int		main(void)
{
	printf("ret = |%d| (real)\n", printf("%05d", 43));
	printf("ret = |%d| (mine)\n", ft_printf("%05d", 43));

	printf("ret = |%d| (real)\n", printf("%08.5d", 34));
	printf("ret = |%d| (mine)\n", ft_printf("%08.5d", 34));

	printf("ret = |%d| (real)\n", printf("%08.3d", 8375));
	printf("ret = |%d| (mine)\n", ft_printf("%08.3d", 8375));

	printf("ret = |%d| (real)\n", printf("%0-5d", 34));
	printf("ret = |%d| (mine)\n", ft_printf("%0-5d", 34));

	printf("ret = |%d| (real)\n", printf("%0-10.5d", -216));
	printf("ret = |%d| (mine)\n", ft_printf("%0-10.5d", -216));

	//ICI
	printf("ret = |%d| (real)\n", printf("%10.5d", -216));
	printf("ret = |%d| (mine)\n", ft_printf("%10.5d", -216));

	printf("ret = |%d| (real)\n", printf("%7d", -14));
	printf("ret = |%d| (mine)\n", ft_printf("%7d", -14));

	printf("ret = |%d| (real)\n", printf("%7d", -14));
	printf("ret = |%d| (mine)\n", ft_printf("%7d", -14));

	printf("ret = |%d| (real)\n", printf("%-7d", -14));
	printf("ret = |%d| (mine)\n", ft_printf("%-7d", -14));

	printf("ret = |%d| (real)\n", printf("%07d", -14));
	printf("ret = |%d| (mine)\n", ft_printf("%07d", -14));

	printf("ret = |%d| (real)\n", printf("%-7d", 33));
	printf("ret = |%d| (mine)\n", ft_printf("%-7d", 33));

	printf("ret = |%d| (real)\n", printf("%-.7d", -33));
	printf("ret = |%d| (mine)\n", ft_printf("%-.7d", -33));

	//ICI
	printf("ret = |%d| (real)\n", printf("%.5d", -2));
	printf("ret = |%d| (mine)\n", ft_printf("%.5d", -2));

	printf("ret = |%d| (real)\n", printf("%.6d", 6562));
	printf("ret = |%d| (mine)\n", ft_printf("%.6d", 6562));

	printf("ret = |%d| (real)\n", printf("%0.5d", -398));
	printf("ret = |%d| (mine)\n", ft_printf("%0.5d", -398));

	//ICI
	printf("ret = |%d| (real)\n", printf("%9.5d", -398));
	printf("ret = |%d| (mine)\n", ft_printf("%9.5d", -398));

	//ICI
	printf("ret = |%d| (real)\n", printf("%-9.5d", -398));
	printf("ret = |%d| (mine)\n", ft_printf("%-9.5d", -398));

	printf("ret = |%d| (real)\n", printf("%4.10d", 398));
	printf("ret = |%d| (mine)\n", ft_printf("%4.10d", 398));

	printf("ret = |%d| (real)\n", printf("%0-3.3d", 6983));
	printf("ret = |%d| (mine)\n", ft_printf("%0-3.3d", 6983));

	printf("ret = |%d| (real)\n", printf("%-03.3d", -8462));
	printf("ret = |%d| (mine)\n", ft_printf("%-03.3d", -8462));

	printf("ret = |%d| (real)\n", printf("%-5.d", 0));
	printf("ret = |%d| (mine)\n", ft_printf("%-5.d", 0));

	printf("ret = |%d| (real)\n", printf("%05.d", 0));
	printf("ret = |%d| (mine)\n", ft_printf("%05.d", 0));

	printf("ret = |%d| (real)\n", printf("%0-5.d", 0));
	printf("ret = |%d| (mine)\n", ft_printf("%0-5.d", 0));

	printf("ret = |%d| (real)\n", printf("%.d", 0));
	printf("ret = |%d| (mine)\n", ft_printf("%.d", 0));

	printf("ret = |%d| (real)\n", printf("%d", 0));
	printf("ret = |%d| (mine)\n", ft_printf("%d", 0));

	printf("ret = |%d| (real)\n", printf("%.*s", -3, "hello"));
	printf("ret = |%d| (mine)\n", ft_printf("%.*s", -3, "hello"));

	printf("ret = |%d| (real)\n", printf("%-*.*s", -7, -3, "yolo"));
	printf("ret = |%d| (mine)\n", ft_printf("%-*.*s", -7, -3, "yolo"));

	printf("ret = |%d| (real)\n", printf("%-*.*s", 7, -3, "yolo"));
	printf("ret = |%d| (mine)\n", ft_printf("%-*.*s", 7, -3, "yolo"));

	printf("ret = |%d| (real)\n", printf("%-*.*s", 7, 3, "yolo"));
	printf("ret = |%d| (mine)\n", ft_printf("%-*.*s", 7, 3, "yolo"));

	printf("ret = |%d| (real)\n", printf("%u", 4294967295u));
	printf("ret = |%d| (mine)\n", ft_printf("%u", 4294967295u));
	return (0);
}
