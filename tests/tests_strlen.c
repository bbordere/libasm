#include "test.h"

void test_strlen() {
	size_t val_ft;
	size_t val_std;

	printf_center(YELLOW BOLD "[STRLEN]" RESET);
	printf("String: \"Ceci est un test\"\n");
	val_ft = ft_strlen("Ceci est un test");
	val_std = strlen("Ceci est un test");
	printf("%s %ld %s\n", CYAN "ft_strlen =>" YELLOW, val_ft, RESET);
	printf("%s %ld %s\n", CYAN "strlen =>" YELLOW, val_std, RESET);
	printf("%s\n\n", ((val_ft == val_std) ? GREEN "Test Passed ✅" RESET :
											RED "Test Failed ❌" RESET));
	printf("String: \"\"\n");
	val_ft = ft_strlen("");
	val_std = strlen("");
	printf("%s %ld %s\n", CYAN "ft_strlen =>" YELLOW, val_ft, RESET);
	printf("%s %ld %s\n", CYAN "strlen =>" YELLOW, val_std, RESET);
	printf("%s\n\n", ((val_ft == val_std) ? GREEN "Test Passed ✅" RESET :
											RED "Test Failed ❌" RESET));

	printf("String: \"\\n\"\n");
	val_ft = ft_strlen("\n");
	val_std = strlen("\n");
	printf("%s %ld %s\n", CYAN "ft_strlen =>" YELLOW, val_ft, RESET);
	printf("%s %ld %s\n", CYAN "strlen =>" YELLOW, val_std, RESET);
	printf("%s\n\n", ((val_ft == val_std) ? GREEN "Test Passed ✅" RESET :
											RED "Test Failed ❌" RESET));
	printf(MAGENTA "%s\n%s", S2, RESET);
}
