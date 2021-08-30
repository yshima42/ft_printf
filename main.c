#include "libft/libft.h"
#include "includes/ft_printf.h"

int main(void)
{
	char *a = "abc";
	char c = 'c';
	int i_max = 2147483647;
	int i_min = -2147483648;
	unsigned int ui = 4294967295;


	printf("return: %d\n" ,ft_printf("ft_printf: %c\n", c));
	printf("return: %d\n", printf("printf: %c\n", c));
	printf("\n");

	printf("return: %d\n", ft_printf("ft_printf: %s\n", a));
	printf("printf: %s\n", a);
	printf("\n");
	
	printf("return: %d\n", ft_printf("ft_printf: %d\n", i_max));
	printf("return: %d\n", printf("printf: %d\n", i_max));
	printf("\n");
	
	ft_printf("ft_printf: %i\n", i_max);
	printf("printf: %i\n", i_max);
	printf("\n");
	
	ft_printf("ft_printf: %d\n", i_min);
	printf("printf: %d\n", i_min);
	printf("\n");
	
	ft_printf("ft_printf: %i\n", i_min);
	printf("printf: %i\n", i_min);
	printf("\n");
	
	printf("return: %d\n", ft_printf("ft_printf: %u\n", ui));
	printf("return: %d\n", printf("printf: %u\n", ui));
	printf("\n");
	
	printf("return: %d\n", ft_printf("ft_printf: %p\n", a));
	printf("return: %d\n", printf("printf: %p\n", a));
	printf("\n");

	printf("return: %d\n", ft_printf("ft_printf: %p\n", a));
	printf("return: %d\n", printf("printf: %p\n", a));
	printf("\n");
	
	printf("return: %d\n", ft_printf("ft_printf: %x\n", i_max));
	printf("return: %d\n", printf("printf: %x\n", i_max));
	ft_printf("ft_printf: %x\n", i_min);
	
	printf("printf: %x\n", i_min);
	ft_printf("ft_printf: %X\n", i_min);
	printf("printf: %X\n", i_min);
	ft_printf("ft_printf: %X\n", i_min);
	printf("printf: %X\n", i_min);
	printf("\n");

	printf("return: %d\n", ft_printf("ft_printf: %mmm\n", i_min));
	printf("return: %d\n", printf("printf: %mmm\n"));

}
