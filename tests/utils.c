#include "test.h"

void printf_center(char *str)
{
	int len = strlen(str);
	int left_pad = (80 - len) / 2;
	int right_pad = 80 - len - left_pad;
	printf("%*s%s%*s\n", left_pad, "", str, right_pad, "");
}

void print_list(t_list *lst, enum TYPE type)
{
	char *types[] = {"%d ", "%c ", "%s "};
	while (lst)
	{
		printf(YELLOW);
		printf(types[type], lst->data);
		printf(RESET);
		printf("-> ");
		lst = lst->next;
	}
	printf("NULL\n");
}

void free_list(t_list *lst)
{
	t_list *tmp;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
