#include "test.h"

void test_strcmp()
{
	printf_center(YELLOW BOLD "[STRCMP]" RESET);
	int val_ft;
	int val_std;

	printf("String1: \"Bonjour Bonsoir\", String2: \"Bonjour Bonsoir\"\n");
	val_ft = ft_strcmp("Bonjour Bonsoir", "Bonjour Bonsoir");
	val_std = strcmp("Bonjour Bonsoir", "Bonjour Bonsoir");
	printf("%s %d %s\n", CYAN "ft_strcmp =>" YELLOW, val_ft, RESET);
	printf("%s %d %s\n", CYAN "strcmp =>" YELLOW, val_std, RESET);
	printf("%s\n\n",
		   (SAME_SIGN(val_ft, val_std) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET));

	printf("String1: \"Bonjour\", String2: \"Bonsoir\"\n");
	val_ft = ft_strcmp("Bonjour", "Bonsoir");
	val_std = strcmp("Bonjour", "Bonsoir");
	printf("%s %d %s\n", CYAN "ft_strcmp =>" YELLOW, val_ft, RESET);
	printf("%s %d %s\n", CYAN "strcmp =>" YELLOW, val_std, RESET);
	printf("%s\n\n",
		   (SAME_SIGN(val_ft, val_std) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET));

	printf("String1: \"Bonsoir\", String2: \"Bonjour\"\n");
	val_ft = ft_strcmp("Bonsoir", "Bonjour");
	val_std = strcmp("Bonsoir", "Bonjour");
	printf("%s %d %s\n", CYAN "ft_strcmp =>" YELLOW, val_ft, RESET);
	printf("%s %d %s\n", CYAN "strcmp =>" YELLOW, val_std, RESET);
	printf("%s\n\n",
		   (SAME_SIGN(val_ft, val_std) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET));

	printf("String1: \"1234\", String2: \"123456\"\n");
	val_ft = ft_strcmp("1234", "123456");
	val_std = strcmp("1234", "123456");
	printf("%s %d %s\n", CYAN "ft_strcmp =>" YELLOW, val_ft, RESET);
	printf("%s %d %s\n", CYAN "strcmp =>" YELLOW, val_std, RESET);
	printf("%s\n\n",
		   (SAME_SIGN(val_ft, val_std) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET));

	printf("String1: \"123456\", String2: \"123455\"\n");
	val_ft = ft_strcmp("123456", "123455");
	val_std = strcmp("123456", "123455");
	printf("%s %d %s\n", CYAN "ft_strcmp =>" YELLOW, val_ft, RESET);
	printf("%s %d %s\n", CYAN "strcmp =>" YELLOW, val_std, RESET);
	printf("%s\n\n",
		   (SAME_SIGN(val_ft, val_std) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET));
	printf(MAGENTA "%s\n%s", S2, RESET);
}
