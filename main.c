#include "includes/ft_printf.h"

int		main(void)
{
	printf("ret = |%d|\n", printf("%7.8s", "yolo"));
	printf("ret = |%d|\n", ft_printf("%7.8s", "yolo"));
	return (0);
}
