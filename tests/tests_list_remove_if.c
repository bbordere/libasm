#include "test.h"

void	useless_free(void *ptr){
	printf("C'EST FREE %s\n", (char *)ptr);
	(void)ptr;
}

void test_list_remove_if(void){
	printf_center(YELLOW BOLD "[LIST_REMOVE_IF]" RESET);
	t_list *list = NULL;

	ft_list_push_front(&list, (void*)"test");
	ft_list_push_front(&list, (void*)"test2");
	ft_list_push_front(&list, (void*)"test3");
	ft_list_push_front(&list, (void*)"test4");
	print_list(list, STR);

	ft_list_remove_if(&list, (void *)"test2", ft_strcmp, useless_free);
	print_list(list, STR);

	ft_list_remove_if(&list, (void *)"test3", ft_strcmp, useless_free);
	print_list(list, STR);

	ft_list_remove_if(&list, (void *)"test4", ft_strcmp, useless_free);
	print_list(list, STR);

	ft_list_remove_if(&list, (void *)"test", ft_strcmp, useless_free);
	// printf("%p %s\n", ptr, (char*)ptr);
	print_list(list, STR);
}
