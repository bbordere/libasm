#include "test.h"

void test_write() {
	printf_center(YELLOW BOLD "[WRITE]" RESET);

	ssize_t val_ft;
	ssize_t val_std;
	int errno_ft;
	int errno_std;

	printf("String: \"Hello World !\", fd: 1, len %ld\n",
		   strlen("Hello World !\n"));

	write(1, BLUE, 6);

	val_ft = ft_write(1, "Hello World !\n", strlen("Hello World !\n"));
	errno_ft = errno;
	val_std = write(1, "Hello World !\n", strlen("Hello World !\n"));
	errno_std = errno;

	write(1, RESET, 5);

	printf("%s %ld%s, errno: %s%d%s\n", CYAN "ft_write =>" YELLOW, val_ft, CYAN,
		   YELLOW, errno_ft, RESET);
	printf("%s %ld%s, errno: %s%d%s\n", CYAN "write =>" YELLOW, val_std, CYAN,
		   YELLOW, errno_std, RESET);
	printf("%s\n\n", ((val_ft == val_std) && (errno_ft == errno_std) ?
						  GREEN "Test Passed ✅" RESET :
						  RED "Test Failed ❌" RESET));

	printf("String: \"Hello\\n World !\", fd: 1, len 6\n");

	write(1, BLUE, 6);

	val_ft = ft_write(1, "Hello\n World !\n", 6);
	errno_ft = errno;
	val_std = write(1, "Hello\n World !\n", 6);
	errno_std = errno;

	write(1, RESET, 5);

	printf("%s %ld%s, errno: %s%d%s\n", CYAN "ft_write =>" YELLOW, val_ft, CYAN,
		   YELLOW, errno_ft, RESET);
	printf("%s %ld%s, errno: %s%d%s\n", CYAN "write =>" YELLOW, val_std, CYAN,
		   YELLOW, errno_std, RESET);
	printf("%s\n\n", ((val_ft == val_std) && (errno_ft == errno_std) ?
						  GREEN "Test Passed ✅" RESET :
						  RED "Test Failed ❌" RESET));

	printf("String: \"Houston, we have a problem !\", fd: 4242, len %ld\n",
		   strlen("Houston, we have a problem !\n"));

	val_ft = ft_write(42, "Houston, we have a problem !\n",
					  strlen("Houston, we have a problem !\n"));
	errno_ft = errno;
	val_std = write(42, "Houston, we have a problem !\n",
					strlen("Houston, we have a problem !\n"));
	errno_std = errno;

	printf("%s %ld%s, errno: %s%d%s\n", CYAN "ft_write =>" YELLOW, val_ft, CYAN,
		   YELLOW, errno_ft, RESET);
	printf("%s %ld%s, errno: %s%d%s\n", CYAN "write =>" YELLOW, val_std, CYAN,
		   YELLOW, errno_std, RESET);
	printf("%s\n\n", ((val_ft == val_std) && (errno_ft == errno_std) ?
						  GREEN "Test Passed ✅" RESET :
						  RED "Test Failed ❌" RESET));
	printf(MAGENTA "%s\n%s", S2, RESET);
	errno = 0;
}
