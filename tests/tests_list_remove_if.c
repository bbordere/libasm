#include "test.h"

void useless_free(void *ptr) {
	// *(int *)ptr = -1;
	(void)ptr;
}

void test_list_remove_if(void) {
	printf_center(YELLOW BOLD "[LIST_REMOVE_IF]" RESET);
	t_list *list = NULL;

	ft_list_push_front(&list, (void *)strdup("Sit Amet"));
	ft_list_push_front(&list, (void *)strdup("Dolore"));
	ft_list_push_front(&list, (void *)strdup("Ipsum"));
	ft_list_push_front(&list, (void *)strdup("Lorem"));

	printf(CYAN "list: " RESET);
	print_list(list, STR);

	printf(GREEN "Removing \"Ipsum\"\n" RESET);
	ft_list_remove_if(&list, (void *)"Ipsum", ft_strcmp, free);
	printf(CYAN "list: " RESET);
	print_list(list, STR);

	printf(GREEN "Removing \"Dolore\"\n" RESET);
	ft_list_remove_if(&list, (void *)"Dolore", ft_strcmp, free);
	printf(CYAN "list: " RESET);
	print_list(list, STR);

	printf(GREEN "Removing \"Sit Amet\"\n" RESET);
	ft_list_remove_if(&list, (void *)"Sit Amet", ft_strcmp, free);
	printf(CYAN "list: " RESET);
	print_list(list, STR);

	printf(GREEN "Removing \"Lorem\"\n" RESET);
	ft_list_remove_if(&list, (void *)"Lorem", ft_strcmp, free);
	printf(CYAN "list: " RESET);
	print_list(list, STR);
	printf("\n\n");

	clear_list(&list, 1);
	ft_list_push_front(&list, ft_strdup("0"));
	ft_list_push_front(&list, ft_strdup("1"));
	for (long long i = 0; i < 4; ++i) {
		ft_list_push_front(&list, ft_strdup("0"));
	}
	ft_list_push_front(&list, ft_strdup("2"));
	ft_list_push_front(&list, ft_strdup("0"));

	printf(CYAN "list: " RESET);
	print_list(list, STR);
	printf(GREEN "Removing all \"0\"\n" RESET);
	ft_list_remove_if(&list, "0", ft_strcmp, free);
	printf(CYAN "list: " RESET);
	print_list(list, STR);
	printf(GREEN "Removing all \"6\"\n" RESET);
	ft_list_remove_if(&list, "6", ft_strcmp, free);
	printf(CYAN "list: " RESET);
	print_list(list, STR);
	clear_list(&list, 1);
	printf("\n\n");

	printf(CYAN "list: " RESET);
	print_list(list, STR);
	printf(GREEN "Removing all \"AAAAAAH\"\n" RESET);
	printf(CYAN "list: " RESET);
	print_list(list, INT);
	printf("\n\n");

	int data[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	for (int i = 0; i < 10; ++i) {
		ft_list_push_front(&list, data + i);
	}
	printf(CYAN "list: " RESET);
	print_list(list, INT);
	printf(GREEN "Removing elements greater than or equal to %d\n" RESET,
		   data[5]);
	ft_list_remove_if(&list, &data[5], upper_cmp, useless_free);
	printf(CYAN "list: " RESET);
	print_list(list, INT);
	clear_list(&list, 0);
	printf("\n\n");

	for (int i = 0; i < 10; ++i) {
		ft_list_push_front(&list, data + i);
	}
	printf(CYAN "list: " RESET);
	print_list(list, INT);
	printf(GREEN "Removing elements with the same parity as %d\n" RESET,
		   data[5]);
	ft_list_remove_if(&list, &data[5], parity_cmp, useless_free);
	printf(CYAN "list: " RESET);
	print_list(list, INT);
	clear_list(&list, 0);
}
