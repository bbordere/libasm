#ifndef __TEST_H__
#define __TEST_H__

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAGENTA "\033[95m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define LOREM_IPSUM                                                          \
	"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam vitae " \
	"elit tristique, tincidunt elit nec, faucibus est. Aenean ut velit eu "  \
	"erat dignissim rhoncus et et ante. Donec ac elit id tellus dictum "     \
	"tempor id at lorem. Curabitur fermentum ipsum nunc"

#define SET_BIT_TO(var, bitPos, bitValue) \
	((var) |= ((var) & ~(1u << (bitPos))) | ((bitValue) << (bitPos)))

#define SAME_SIGN(x, y) (((x ^ y) >> (sizeof(int) * 8 - 1)) == 0)

#define S2                                                                     \
	"------------------------------------------------------------------------" \
	"-------"
#define S3                                                                     \
	"________________________________________________________________________" \
	"_______"

#define DEC_BASE "0123456789"
#define DEC_BASE "0123456789"
#define HEX_BASE "0123456789ABCDEF"
#define OCT_BASE "01234567"
#define WTF_BASE "poney"

typedef struct s_list
{
	void *data;
	struct s_list *next;
} t_list;

enum BIT_POS
{
	STRLEN,
	STRCPY,
	STRCMP,
	WRITE,
	READ,
	STRDUP,
};

enum BONUS_BIT_POS
{
	ATOI_BASE,
	LIST_PUSH_FRONT,
	LIST_SIZE,
	LIST_SORT,
	REMOVE_IF
};

enum TYPE
{
	INT,
	CHAR,
	STR
};

void test_atoi_base(void);
void test_strlen(void);
void test_strcpy(void);
void test_strcmp(void);
void test_write(void);
void test_read(void);
void test_strdup(void);
void test_list_push_front(void);
void test_list_size(void);
void test_list_sort(void);
void test_list_remove_if(void);

void printf_center(char *str);
void print_list(t_list *lst, enum TYPE type);
void clear_list(t_list **lst);
int upper_cmp(void *d1, void *d2);
int lower_cmp(void *d1, void *d2);
int equal(void *d1, void *d2);
int is_sorted(t_list *lst, int (*cmp)());

char *ft_strdup(char const *s);
char *ft_strcpy(char *dest, char const *src);

size_t ft_strlen(char const *s);

int ft_strcmp(char const *s1, char const *s2);

ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, char const *buf, size_t count);

int ft_atoi_base(char *str, char *base);

int ft_list_size(t_list *begin_list);
void ft_list_sort(t_list **begin_list, int (*cmp)());
void ft_list_push_front(t_list **begin_list, void *data);
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

#endif
