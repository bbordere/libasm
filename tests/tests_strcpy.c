#include "test.h"

void test_strcpy() {
	printf_center(YELLOW BOLD "[STRCPY]" RESET);

	char buffer_ft[256];
	char buffer_std[256];

	printf("String: \"Don't panic !\"\n");
	ft_strcpy(buffer_ft, "Don't panic !");
	strcpy(buffer_std, "Don't panic !");

	printf("%s %s %s\n", CYAN "buffer_ft:" YELLOW, buffer_ft, RESET);
	printf("%s %s %s\n", CYAN "buffer_std:" YELLOW, buffer_std, RESET);
	printf("%s\n\n",
		   (!(strcmp(buffer_ft, buffer_std)) ? GREEN "Test Passed ✅" RESET :
											   RED "Test Failed ❌" RESET));

	bzero(buffer_ft, sizeof(buffer_ft));
	bzero(buffer_std, sizeof(buffer_std));

	printf("String: \"%s\"\n", LOREM_IPSUM);
	ft_strcpy(buffer_ft, LOREM_IPSUM);
	strcpy(buffer_std, LOREM_IPSUM);

	printf("%s %s %s\n", CYAN "buffer_ft:" YELLOW, buffer_ft, RESET);
	printf("%s %s %s\n", CYAN "buffer_std:" YELLOW, buffer_std, RESET);
	printf("%s\n\n",
		   (!(strcmp(buffer_ft, buffer_std)) ? GREEN "Test Passed ✅" RESET :
											   RED "Test Failed ❌" RESET));

	bzero(buffer_ft, sizeof(buffer_ft));
	bzero(buffer_std, sizeof(buffer_std));

	printf("String: \"|123456789|\" (2 times)\n");

	ft_strcpy(buffer_ft, "|123456789|");
	strcpy(buffer_std, "|123456789|");
	ft_strcpy(buffer_ft + 11, "|123456789|");
	strcpy(buffer_std + 11, "|123456789|");

	printf("%s %s %s\n", CYAN "buffer_ft:" YELLOW, buffer_ft, RESET);
	printf("%s %s %s\n", CYAN "buffer_std:" YELLOW, buffer_std, RESET);
	printf("%s\n\n",
		   (!(strcmp(buffer_ft, buffer_std)) ? GREEN "Test Passed ✅" RESET :
											   RED "Test Failed ❌" RESET));
	printf(MAGENTA "%s\n%s", S2, RESET);
}
