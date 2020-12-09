#include "includes/ft_printf.h"

int		main(void)
{
	printf("ret = |%d|\n", printf("|%-*s dsfsdf %-10.8s|", 10, "HIIIIII", NULL));
	printf("ret = |%d|\n", ft_printf("|%-*s dsfsdf %-10.8s|", 10, "HIIIIII", NULL));

	printf("ret = |%d|\n", printf("|%9.3s|", "JIIIII"));
	printf("ret = |%d|\n", ft_printf("|%9.3s|", "JIIIII"));

	printf("ret = |%d|\n", printf("|%20.s|", "JIIIIIIIIIII"));
	printf("ret = |%d|\n", ft_printf("|%20.s|", "JIIIIIIIIIII"));
	return (0);
}
