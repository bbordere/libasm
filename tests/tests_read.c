#include "test.h"

void test_read()
{
	printf_center(YELLOW BOLD "[READ]" RESET);

	int fd_ft;
	int fd_std;
	ssize_t val_ft;
	ssize_t val_std;
	char buffer_ft[256] = {0};
	char buffer_std[256] = {0};
	int errno_ft;
	int errno_std;

	fd_ft = open("textFile.ber", O_RDONLY);
	fd_std = open("textFile.ber", O_RDONLY);

	val_ft = ft_read(fd_ft, buffer_ft, 26);
	errno_ft = errno;

	val_std = read(fd_std, buffer_std, 26);
	errno_std = errno;

	printf("Reading the first 26 characters of \'testFile.ber\'\n");
	printf("%s %s %s\n", CYAN "buffer_ft:" YELLOW, buffer_ft, RESET);
	printf("%s %s %s\n", CYAN "buffer_std:" YELLOW, buffer_std, RESET);
	printf("%s %ld%s, errno: %s%d%s\n", CYAN "ft_read =>" YELLOW, val_ft, CYAN,
		   YELLOW, errno_ft, RESET);
	printf("%s %ld%s, errno: %s%d%s\n", CYAN "read =>" YELLOW, val_std, CYAN,
		   YELLOW, errno_std, RESET);

	printf("%s\n\n", ((val_ft == val_std) && (errno_ft == errno_std) &&
							  (!strcmp(buffer_ft, buffer_std))
						  ? GREEN "Test Passed ✅" RESET
						  : RED "Test Failed ❌" RESET));

	close(fd_ft);
	close(fd_std);

	bzero(buffer_ft, sizeof(buffer_ft));
	bzero(buffer_std, sizeof(buffer_std));

	printf("Reading invalid fd\n");

	val_ft = ft_read(4242, buffer_ft, 27);
	errno_ft = errno;

	val_std = read(4242, buffer_std, 27);
	errno_std = errno;

	printf("%s %s %s\n", CYAN "buffer_ft:" YELLOW, buffer_ft, RESET);
	printf("%s %s %s\n", CYAN "buffer_std:" YELLOW, buffer_std, RESET);
	printf("%s %ld%s, errno: %s%d%s\n", CYAN "ft_read =>" YELLOW, val_ft, CYAN,
		   YELLOW, errno_ft, RESET);
	printf("%s %ld%s, errno: %s%d%s\n", CYAN "read =>" YELLOW, val_std, CYAN,
		   YELLOW, errno_std, RESET);

	printf("%s\n\n", ((val_ft == val_std) && (errno_ft == errno_std) &&
							  (!strcmp(buffer_ft, buffer_std))
						  ? GREEN "Test Passed ✅" RESET
						  : RED "Test Failed ❌" RESET));
	errno = 0;

	printf("Reading \'testFile.ber\' character by character\n");

	char c;
	int pos = 0;
	fd_ft = open("textFile.ber", O_RDONLY);
	fd_std = open("textFile.ber", O_RDONLY);
	while (read(fd_std, &c, 1) > 0)
	{
		buffer_std[pos++] = c;
	}
	pos = 0;
	while (ft_read(fd_ft, &c, 1) > 0)
	{
		buffer_ft[pos++] = c;
	}
	printf("%s %s %s\n", CYAN "buffer_ft:" YELLOW, buffer_ft, RESET);
	printf("%s %s %s\n", CYAN "buffer_std:" YELLOW, buffer_std, RESET);

	printf("%s\n\n",
		   ((!strcmp(buffer_ft, buffer_std)) ? GREEN "Test Passed ✅" RESET : RED "Test Failed ❌" RESET));
	printf(MAGENTA "%s\n%s", S2, RESET);
}
