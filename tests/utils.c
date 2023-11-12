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

void clear_list(t_list **lst)
{
	t_list *tmp;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	lst = NULL;
}

int is_sorted(t_list *lst, int (*cmp)())
{
	t_list *tmp;
	while (lst)
	{
		tmp = lst->next;
		if (!lst->next)
			return (1);
		if (cmp(lst->data, tmp->data) > 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int lower_cmp(void *d1, void *d2)
{
	return ((long long)d1 > (long long)d2);
}

int upper_cmp(void *d1, void *d2)
{
	return ((long long)d1 < (long long)d2);
}
