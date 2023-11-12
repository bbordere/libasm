#include "test.h"

void test_list_push_front(void)
{
	printf_center(YELLOW BOLD "[LIST_PUSH_FRONT]" RESET);
	t_list *list = NULL;
	printf("%s %p %s\n", CYAN "list:" YELLOW, (void *)list, RESET);
	print_list(list, STR);
	printf("\n");

	ft_list_push_front(&list, "first !");
	printf("%s %p %s\n", CYAN "list:" YELLOW, (void *)list, RESET);
	print_list(list, STR);
	printf("\n");

	ft_list_push_front(&list, ":)");
	printf("%s %p %s\n", CYAN "list:" YELLOW, (void *)list, RESET);
	print_list(list, STR);
	printf("\n");

	ft_list_push_front(&list, "Hello World !");
	printf("%s %p %s\n", CYAN "list:" YELLOW, (void *)list, RESET);
	print_list(list, STR);
	printf("\n");

	ft_list_push_front(&list, NULL);
	printf("%s %p %s\n", CYAN "list:" YELLOW, (void *)list, RESET);
	print_list(list, STR);
	printf("\n");

	ft_list_push_front(NULL, "Bof");
	printf("%s %p %s\n", CYAN "list:" YELLOW, (void *)list, RESET);
	print_list(list, STR);
	printf("\n");
	clear_list(&list);
}
