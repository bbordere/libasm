#include "test.h"

void test_strdup() {
	printf_center(YELLOW BOLD "[STRDUP]" RESET);
	printf("Dup string: \"Ceci est un test !\"\n");
	char *dup_ft;
	char *dup_std;
	int errno_ft;
	int errno_std;
	dup_ft = ft_strdup("Ceci est un test !");
	errno_ft = errno;
	dup_std = strdup("Ceci est un test !");
	errno_std = errno;

	printf("%s %p (%s)%s, errno: %s%d%s\n", CYAN "ft_strdup =>" YELLOW,
		   (void *)dup_ft, dup_ft, CYAN, YELLOW, errno_ft, RESET);
	printf("%s %p (%s)%s, errno: %s%d%s\n", CYAN "strdup =>" YELLOW,
		   (void *)dup_std, dup_std, CYAN, YELLOW, errno_std, RESET);

	printf("%s\n\n", ((errno_ft == errno_std) && (!strcmp(dup_ft, dup_std)) ?
						  GREEN "Test Passed ✅" RESET :
						  RED "Test Failed ❌" RESET));

	free(dup_ft);
	free(dup_std);

	printf("Dup string: \"\"\n");
	dup_ft = ft_strdup("");
	errno_ft = errno;
	dup_std = strdup("");
	errno_std = errno;

	printf("%s %p (%s)%s, errno: %s%d%s\n", CYAN "ft_strdup =>" YELLOW,
		   (void *)dup_ft, dup_ft, CYAN, YELLOW, errno_ft, RESET);
	printf("%s %p (%s)%s, errno: %s%d%s\n", CYAN "strdup =>" YELLOW,
		   (void *)dup_std, dup_std, CYAN, YELLOW, errno_std, RESET);

	printf("%s\n\n", ((errno_ft == errno_std) && (!strcmp(dup_ft, dup_std)) ?
						  GREEN "Test Passed ✅" RESET :
						  RED "Test Failed ❌" RESET));

	free(dup_ft);
	free(dup_std);

	printf("Dup string: \"%s\"\n", LOREM_IPSUM);
	dup_ft = ft_strdup(LOREM_IPSUM);
	errno_ft = errno;
	dup_std = strdup(LOREM_IPSUM);
	errno_std = errno;

	printf("%s %p (%s)%s, errno: %s%d%s\n", CYAN "ft_strdup =>" YELLOW,
		   (void *)dup_ft, dup_ft, CYAN, YELLOW, errno_ft, RESET);
	printf("%s %p (%s)%s, errno: %s%d%s\n", CYAN "strdup =>" YELLOW,
		   (void *)dup_std, dup_std, CYAN, YELLOW, errno_std, RESET);

	printf("%s\n\n", ((errno_ft == errno_std) && (!strcmp(dup_ft, dup_std)) ?
						  GREEN "Test Passed ✅" RESET :
						  RED "Test Failed ❌" RESET));

	free(dup_ft);
	free(dup_std);
	printf(MAGENTA "%s\n%s", S2, RESET);
}
