#include "test.h"

void test_atoi_base(void)
{
	printf_center(YELLOW BOLD "[ATOI_BASE]" RESET);
	printf("String: \"42\", Base: \"%s\"\n", DEC_BASE);
	int number = ft_atoi_base("42", DEC_BASE);
	printf("%s %d %s\n", CYAN "ft_atoi_base =>" YELLOW, number, RESET);
	printf("%s\n\n", (number == 42) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET);
	printf("String: \"-42\", Base: \"%s\"\n", DEC_BASE);
	number = ft_atoi_base("-42", DEC_BASE);
	printf("%s %d %s\n", CYAN "ft_atoi_base =>" YELLOW, number, RESET);
	printf("%s\n\n", (number == -42) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET);

	printf("String: \"42\", Base: \"%s\"\n", HEX_BASE);
	number = ft_atoi_base("42", HEX_BASE);
	printf("%s %d %s\n", CYAN "ft_atoi_base =>" YELLOW, number, RESET);
	printf("%s\n\n", (number == 66) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET);

	printf("String: \"42\", Base: \"%s\"\n", OCT_BASE);
	number = ft_atoi_base("42", OCT_BASE);
	printf("%s %d %s\n", CYAN "ft_atoi_base =>" YELLOW, number, RESET);
	printf("%s\n\n", (number == 34) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET);

	printf("String: \"DEAD\", Base: \"%s\"\n", HEX_BASE);
	number = ft_atoi_base("DEAD", HEX_BASE);
	printf("%s %d %s\n", CYAN "ft_atoi_base =>" YELLOW, number, RESET);
	printf("%s\n\n", (number == 57005) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET);

	printf("String: \"        -++--+-+--+34\", Base: \"%s\"\n", DEC_BASE);
	number = ft_atoi_base("        -++--+-+--+34", DEC_BASE);
	printf("%s %d %s\n", CYAN "ft_atoi_base =>" YELLOW, number, RESET);
	printf("%s\n\n", (number == 34) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET);

	printf("String: \"ey42\", Base: \"%s\"\n", WTF_BASE);
	number = ft_atoi_base("ey42", WTF_BASE);
	printf("%s %d %s\n", CYAN "ft_atoi_base =>" YELLOW, number, RESET);
	printf("%s\n\n", (number == 19) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET);

	printf("String: \"1001\", Base: \"%s\"\n", "011");
	number = ft_atoi_base("ey42", "011");
	printf("%s %d %s\n", CYAN "ft_atoi_base =>" YELLOW, number, RESET);
	printf("%s\n\n", (number == 0) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET);

	printf("String: \"1001\", Base: \"%s\"\n", "+01");
	number = ft_atoi_base("1001", "+01");
	printf("%s %d %s\n", CYAN "ft_atoi_base =>" YELLOW, number, RESET);
	printf("%s\n\n", (number == 0) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET);

	printf("String: \"1001\", Base: \"%s\"\n", " 01");
	number = ft_atoi_base("1001", " 01");
	printf("%s %d %s\n", CYAN "ft_atoi_base =>" YELLOW, number, RESET);
	printf("%s\n\n", (number == 0) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET);

	printf("String: \"\", Base: \"%s\"\n", " 01");
	number = ft_atoi_base("", " 01");
	printf("%s %d %s\n", CYAN "ft_atoi_base =>" YELLOW, number, RESET);
	printf("%s\n\n", (number == 0) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET);

	printf("String: \"01\", Base: \"%s\"\n", "");
	number = ft_atoi_base("01", "");
	printf("%s %d %s\n", CYAN "ft_atoi_base =>" YELLOW, number, RESET);
	printf("%s\n\n", (number == 0) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET);
}
