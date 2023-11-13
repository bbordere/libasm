#include "test.h"

#if BONUS

#endif

void test_all()
{
#if BONUS
	test_atoi_base();
	test_list_push_front();
	test_list_size();
	test_list_sort();
	test_list_remove_if();
#else
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
#endif
}

int main(int ac, char **av)
{
	int options = 0;
	printf("%s%s\n", MAGENTA, S3);
	printf_center(" ___  ___  __  ___   _    _  ___  _   __  _   _ ");
	printf_center("|_ _|| __|/ _||_ _| | |  | || o )/ \\ / _|| \\_/ |");
	printf_center(" | | | _| \\_ \\ | |  | |_ | || o \\ o |\\_ \\| \\_/ |");
	printf_center(" |_| |___||__/ |_|  |___||_||___/_n_||__/|_| |_|");
	printf("%s\n%s", S2, RESET);
	if (ac == 1)
	{
		test_all();
		return (0);
	}
	for (int i = 1; i < ac; ++i)
	{
#if BONUS
		SET_BIT_TO(options, ATOI_BASE, !(strcmp(av[i], "atoi_base")));
		SET_BIT_TO(options, LIST_PUSH_FRONT, !(strcmp(av[i], "list_push_front")));
		SET_BIT_TO(options, LIST_SIZE, !(strcmp(av[i], "list_size")));
		SET_BIT_TO(options, LIST_SORT, !(strcmp(av[i], "list_sort")));
		SET_BIT_TO(options, REMOVE_IF, !(strcmp(av[i], "list_remove_if")));
#else
		SET_BIT_TO(options, STRLEN, !(strcmp(av[i], "strlen")));
		SET_BIT_TO(options, STRCPY, !(strcmp(av[i], "strcpy")));
		SET_BIT_TO(options, STRCMP, !(strcmp(av[i], "strcmp")));
		SET_BIT_TO(options, WRITE, !(strcmp(av[i], "write")));
		SET_BIT_TO(options, READ, !(strcmp(av[i], "read")));
		SET_BIT_TO(options, STRDUP, !(strcmp(av[i], "strdup")));
#endif
	}
#if BONUS
	void (*functions[])(void) = {test_atoi_base, test_list_push_front,
								 test_list_size, test_list_sort, test_list_remove_if};
#else
	void (*functions[])(void) = {test_strlen, test_strcpy, test_strcmp,
								 test_write, test_read, test_strdup};
#endif

	for (int i = 0; i < 6; ++i)
	{
		if (options & (1 << i))
			functions[i]();
	}
}
