#include "test.h"

void useless_free(void *ptr)
{
	// printf("C'EST FREE %s\n", (char *)ptr);
	(void)ptr;
}

void test_list_remove_if(void)
{
	printf_center(YELLOW BOLD "[LIST_REMOVE_IF]" RESET);
	t_list *list = NULL;

	ft_list_push_front(&list, (void *)strdup("Sit Amet"));
	ft_list_push_front(&list, (void *)strdup("Dolore"));
	ft_list_push_front(&list, (void *)strdup("Ipsum"));
	ft_list_push_front(&list, (void *)strdup("Lorem"));

	printf(CYAN "list: " RESET);
	print_list(list, STR);

	printf(GREEN "\nRemoving \"Ipsum\"\n" RESET);
	ft_list_remove_if(&list, (void *)"Ipsum", ft_strcmp, free);
	printf(CYAN "list: " RESET);
	print_list(list, STR);

	printf(GREEN "\nRemoving \"Dolore\"\n" RESET);
	ft_list_remove_if(&list, (void *)"Dolore", ft_strcmp, free);
	printf(CYAN "list: " RESET);
	print_list(list, STR);

	printf(GREEN "\nRemoving \"Sit Amet\"\n" RESET);
	ft_list_remove_if(&list, (void *)"Sit Amet", ft_strcmp, free);
	printf(CYAN "list: " RESET);
	print_list(list, STR);

	printf(GREEN "\nRemoving \"Lorem\"\n" RESET);
	ft_list_remove_if(&list, (void *)"Lorem", ft_strcmp, free);
	printf(CYAN "list: " RESET);
	print_list(list, STR);
	printf("\n\n");

	clear_list(&list);
	ft_list_push_front(&list, ft_strdup("1"));
	for (long long i = 0; i < 10; ++i)
	{
		ft_list_push_front(&list, ft_strdup("0"));
	}
	ft_list_push_front(&list, ft_strdup("2"));

	printf(CYAN "list: " RESET);
	print_list(list, STR);
	printf(GREEN "\nRemoving all \"0\"\n" RESET);
	ft_list_remove_if(&list, "0", equal, free);
	print_list(list, STR);
}
