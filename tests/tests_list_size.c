#include "test.h"

void test_list_size(void)
{
	printf_center(YELLOW BOLD "[LIST_SIZE]" RESET);
	t_list *list = NULL;
	printf("%s %p %s\n", CYAN "list:" YELLOW, (void *)list, RESET);
	printf("%s %d %s\n\n", CYAN "ft_list_size =>" YELLOW, ft_list_size(list), RESET);

	for (long i = 0; i < 10; ++i)
	{
		ft_list_push_front(&list, (void *)(42 + i));
		printf("%s %p %s\n", CYAN "list:" YELLOW, (void *)list, RESET);
		print_list(list, INT);
		printf("%s %d %s\n\n", CYAN "ft_list_size =>" YELLOW, ft_list_size(list), RESET);
	}

	clear_list(&list);
}
