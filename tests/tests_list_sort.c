#include "test.h"

void test_list_sort(void) {
	printf_center(YELLOW BOLD "[LIST_SORT]" RESET);
	t_list *list = NULL;

	ft_list_push_front(&list, (void *)2);
	ft_list_push_front(&list, (void *)3);
	ft_list_push_front(&list, (void *)4);
	ft_list_push_front(&list, (void *)-1);
	ft_list_push_front(&list, (void *)5);
	ft_list_push_front(&list, (void *)-2);
	ft_list_push_front(&list, (void *)6);
	ft_list_push_front(&list, (void *)-3);
	ft_list_push_front(&list, (void *)7);
	ft_list_push_front(&list, (void *)0);

	printf(CYAN "list before sorting:\n" RESET);
	print_list(list, ADDR);

	printf(CYAN "list after sorting:\n" RESET);
	ft_list_sort(&list, lower_cmp);
	print_list(list, ADDR);
	printf("%s\n\n", is_sorted(list, lower_cmp) ? GREEN "Test Passed ✅" RESET :
												  RED "Test Failed ❌" RESET);

	clear_list(&list, 0);

	ft_list_push_front(&list, (void *)8);
	ft_list_push_front(&list, (void *)7);
	ft_list_push_front(&list, (void *)6);
	ft_list_push_front(&list, (void *)5);
	ft_list_push_front(&list, (void *)4);
	ft_list_push_front(&list, (void *)3);
	ft_list_push_front(&list, (void *)2);

	printf(CYAN "list before sorting:\n" RESET);
	print_list(list, ADDR);
	printf(CYAN "list after sorting:\n" RESET);
	ft_list_sort(&list, lower_cmp);
	print_list(list, ADDR);
	printf("%s\n\n", is_sorted(list, lower_cmp) ? GREEN "Test Passed ✅" RESET :
												  RED "Test Failed ❌" RESET);

	printf(CYAN "list before sorting:\n" RESET);
	print_list(list, ADDR);
	printf(CYAN "list after sorting:\n" RESET);
	ft_list_sort(&list, upper_cmp);
	print_list(list, ADDR);
	printf("%s\n\n", is_sorted(list, upper_cmp) ? GREEN "Test Passed ✅" RESET :
												  RED "Test Failed ❌" RESET);
	clear_list(&list, 0);

	ft_list_push_front(&list, (void *)"Jade");
	ft_list_push_front(&list, (void *)"Gabriel");
	ft_list_push_front(&list, (void *)"Louise");
	ft_list_push_front(&list, (void *)"Léo");
	ft_list_push_front(&list, (void *)"Ambre");
	ft_list_push_front(&list, (void *)"Raphaël");
	ft_list_push_front(&list, (void *)"Alba");
	ft_list_push_front(&list, (void *)"Maël");
	ft_list_push_front(&list, (void *)"Emma");
	ft_list_push_front(&list, (void *)"Louis");

	printf(CYAN "list before sorting:\n" RESET);
	print_list(list, STR);
	printf(CYAN "list after sorting:\n" RESET);
	ft_list_sort(&list, ft_strcmp);
	print_list(list, STR);
	printf("%s\n\n", is_sorted(list, ft_strcmp) ? GREEN "Test Passed ✅" RESET :
												  RED "Test Failed ❌" RESET);
	clear_list(&list, 0);

	printf(CYAN "list before sorting:\n" RESET);
	print_list(list, STR);
	printf(CYAN "list after sorting:\n" RESET);
	ft_list_sort(&list, ft_strcmp);
	print_list(list, STR);
	printf("%s\n\n", is_sorted(list, ft_strcmp) ? GREEN "Test Passed ✅" RESET :
												  RED "Test Failed ❌" RESET);

	ft_list_push_front(&list, (void *)"Lonely");

	printf(CYAN "list before sorting:\n" RESET);
	print_list(list, STR);
	printf(CYAN "list after sorting:\n" RESET);
	ft_list_sort(&list, ft_strcmp);
	print_list(list, STR);
	printf("%s\n\n", is_sorted(list, ft_strcmp) ? GREEN "Test Passed ✅" RESET :
												  RED "Test Failed ❌" RESET);
	clear_list(&list, 0);
}
