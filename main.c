#include "include/test.h"

void printf_center(char *str) {
	int len = strlen(str);
	int left_pad = (80 - len) / 2;
	int right_pad = 80 - len - left_pad;
	printf("%*s%s%*s\n", left_pad, "", str, right_pad, "");
}

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

void test_strcmp() {
	printf_center(YELLOW BOLD "[STRCMP]" RESET);
	int val_ft;
	int val_std;

	printf("String1: \"Bonjour Bonsoir\", String2: \"Bonjour Bonsoir\"\n");
	val_ft = ft_strcmp("Bonjour Bonsoir", "Bonjour Bonsoir");
	val_std = strcmp("Bonjour Bonsoir", "Bonjour Bonsoir");
	printf("%s %d %s\n", CYAN "ft_strcmp =>" YELLOW, val_ft, RESET);
	printf("%s %d %s\n", CYAN "strcmp =>" YELLOW, val_std, RESET);
	printf("%s\n\n",
		   (SAME_SIGN(val_ft, val_std) ? GREEN "Test Passed ✅" RESET :
										 RED "Test Failed ❌" RESET));

	printf("String1: \"Bonjour\", String2: \"Bonsoir\"\n");
	val_ft = ft_strcmp("Bonjour", "Bonsoir");
	val_std = strcmp("Bonjour", "Bonsoir");
	printf("%s %d %s\n", CYAN "ft_strcmp =>" YELLOW, val_ft, RESET);
	printf("%s %d %s\n", CYAN "strcmp =>" YELLOW, val_std, RESET);
	printf("%s\n\n",
		   (SAME_SIGN(val_ft, val_std) ? GREEN "Test Passed ✅" RESET :
										 RED "Test Failed ❌" RESET));

	printf("String1: \"Bonsoir\", String2: \"Bonjour\"\n");
	val_ft = ft_strcmp("Bonsoir", "Bonjour");
	val_std = strcmp("Bonsoir", "Bonjour");
	printf("%s %d %s\n", CYAN "ft_strcmp =>" YELLOW, val_ft, RESET);
	printf("%s %d %s\n", CYAN "strcmp =>" YELLOW, val_std, RESET);
	printf("%s\n\n",
		   (SAME_SIGN(val_ft, val_std) ? GREEN "Test Passed ✅" RESET :
										 RED "Test Failed ❌" RESET));

	printf("String1: \"1234\", String2: \"123456\"\n");
	val_ft = ft_strcmp("1234", "123456");
	val_std = strcmp("1234", "123456");
	printf("%s %d %s\n", CYAN "ft_strcmp =>" YELLOW, val_ft, RESET);
	printf("%s %d %s\n", CYAN "strcmp =>" YELLOW, val_std, RESET);
	printf("%s\n\n",
		   (SAME_SIGN(val_ft, val_std) ? GREEN "Test Passed ✅" RESET :
										 RED "Test Failed ❌" RESET));

	printf("String1: \"123456\", String2: \"123455\"\n");
	val_ft = ft_strcmp("123456", "123455");
	val_std = strcmp("123456", "123455");
	printf("%s %d %s\n", CYAN "ft_strcmp =>" YELLOW, val_ft, RESET);
	printf("%s %d %s\n", CYAN "strcmp =>" YELLOW, val_std, RESET);
	printf("%s\n\n",
		   (SAME_SIGN(val_ft, val_std) ? GREEN "Test Passed ✅" RESET :
										 RED "Test Failed ❌" RESET));
	printf(MAGENTA "%s\n%s", S2, RESET);
}

void test_read() {
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
							  (!strcmp(buffer_ft, buffer_std)) ?
						  GREEN "Test Passed ✅" RESET :
						  RED "Test Failed ❌" RESET));

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
							  (!strcmp(buffer_ft, buffer_std)) ?
						  GREEN "Test Passed ✅" RESET :
						  RED "Test Failed ❌" RESET));
	errno = 0;

	printf("Reading \'testFile.ber\' character by character\n");

	char c;
	int pos = 0;
	fd_ft = open("textFile.ber", O_RDONLY);
	fd_std = open("textFile.ber", O_RDONLY);
	while (read(fd_std, &c, 1) > 0) {
		buffer_std[pos++] = c;
	}
	pos = 0;
	while (ft_read(fd_ft, &c, 1) > 0) {
		buffer_ft[pos++] = c;
	}
	printf("%s %s %s\n", CYAN "buffer_ft:" YELLOW, buffer_ft, RESET);
	printf("%s %s %s\n", CYAN "buffer_std:" YELLOW, buffer_std, RESET);

	printf("%s\n\n",
		   ((!strcmp(buffer_ft, buffer_std)) ? GREEN "Test Passed ✅" RESET :
											   RED "Test Failed ❌" RESET));
	printf(MAGENTA "%s\n%s", S2, RESET);
}

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

void test_all() {
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
}

// int main(int ac, char **av) {
// 	int options = 0;
// 	printf("%s%s\n", MAGENTA, S3);
// 	printf_center(" ___  ___  __  ___   _    _  ___  _   __  _   _ ");
// 	printf_center("|_ _|| __|/ _||_ _| | |  | || o )/ \\ / _|| \\_/ |");
// 	printf_center(" | | | _| \\_ \\ | |  | |_ | || o \\ o |\\_ \\| \\_/ |");
// 	printf_center(" |_| |___||__/ |_|  |___||_||___/_n_||__/|_| |_|");
// 	printf("%s\n%s", S2, RESET);
// 	if (ac == 1) {
// 		test_all();
// 		return (0);
// 	}
// 	for (int i = 1; i < ac; ++i) {
// 		SET_BIT_TO(options, STRLEN, !(strcmp(av[i], "strlen")));
// 		SET_BIT_TO(options, STRCPY, !(strcmp(av[i], "strcpy")));
// 		SET_BIT_TO(options, STRCMP, !(strcmp(av[i], "strcmp")));
// 		SET_BIT_TO(options, WRITE, !(strcmp(av[i], "write")));
// 		SET_BIT_TO(options, READ, !(strcmp(av[i], "read")));
// 		SET_BIT_TO(options, STRDUP, !(strcmp(av[i], "strdup")));
// 	}
// 	void (*functions[])(void) = {test_strlen, test_strcpy, test_strcmp,
// 								 test_write,  test_read,   test_strdup};
// 	for (int i = 0; i < 6; ++i) {
// 		if (options & (1 << i)) {
// 			functions[i]();
// 		}
// 	}
// }

int main(int ac, char **av) {
	(void)ac;
	int i = ft_atoi_base(av[1], av[2]);
	printf("%d\n", i);
}
