BLUE = \033[34m
RESET = \033[0m
GREEN =	\033[32m
YELLOW = \033[33m

FILES		=	$(SRCS_DIR)ft_write.s $(SRCS_DIR)ft_strlen.s $(SRCS_DIR)ft_strcpy.s $(SRCS_DIR)ft_strcmp.s $(SRCS_DIR)ft_read.s $(SRCS_DIR)ft_strdup.s
BONUS_FILES =	$(FILES) $(SRCS_DIR)ft_atoi_base_bonus.s

SRCS_DIR	=	src/
INC_DIR		=	include/
OBJ_DIR 	= 	obj/

OBJS		=	$(patsubst $(SRCS_DIR)%.s, $(OBJ_DIR)%.o, $(FILES))

BONUS_OBJS	=	$(patsubst $(SRCS_DIR)%.s, $(OBJ_DIR)%.o, $(BONUS_FILES))

ASM_COMP	=	nasm
ASM_FLAGS	=	-f elf64 -g -gstabs -F dwarf

CC			=	clang
CFLAGS		=	-g3 -Wall -Wextra -Werror -Wpedantic -fPIE

NAME		=	libasm.a

$(OBJ_DIR)%.o: $(SRCS_DIR)%.s
	@ mkdir -p $(OBJ_DIR)
	@ printf "$(YELLOW)Compiling: %s$(RESET)\n" $(notdir $<)
	@ $(ASM_COMP) $(ASM_FLAGS) $< -o $@

all: $(NAME)
	@ printf "\n"
	@ printf "$(BLUE)██╗     ██╗██████╗  █████╗ ███████╗███╗   ███╗$(RESET)\n"
	@ printf "$(BLUE)██║     ██║██╔══██╗██╔══██╗██╔════╝████╗ ████║$(RESET)\n"
	@ printf "$(BLUE)██║     ██║██████╔╝███████║███████╗██╔████╔██║$(RESET)\n"
	@ printf "$(BLUE)██║     ██║██╔══██╗██╔══██║╚════██║██║╚██╔╝██║$(RESET)\n"
	@ printf "$(BLUE)███████╗██║██████╔╝██║  ██║███████║██║ ╚═╝ ██║$(RESET)\n"
	@ printf "$(BLUE)╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝$(RESET)\n"
	@ printf "\n"
	@ printf "$(GREEN)$(NAME) is ready to use !$(RESET)\n"

$(NAME): $(OBJS)
	@ printf "$(GREEN)Creating static library...$(RESET)\n"
	@ ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	@ printf "$(GREEN)Creating static library...$(RESET)\n"
	@ ar rcs $(NAME) $(BONUS_OBJS)
	@ printf "\n"
	@ printf "$(BLUE)██╗     ██╗██████╗  █████╗ ███████╗███╗   ███╗$(RESET)\n"
	@ printf "$(BLUE)██║     ██║██╔══██╗██╔══██╗██╔════╝████╗ ████║$(RESET)\n"
	@ printf "$(BLUE)██║     ██║██████╔╝███████║███████╗██╔████╔██║$(RESET)\n"
	@ printf "$(BLUE)██║     ██║██╔══██╗██╔══██║╚════██║██║╚██╔╝██║$(RESET)\n"
	@ printf "$(BLUE)███████╗██║██████╔╝██║  ██║███████║██║ ╚═╝ ██║$(RESET)\n"
	@ printf "$(BLUE)╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝$(RESET)\n"
	@ printf "\n"
	@ printf "$(GREEN)$(NAME) is ready to use !$(RESET)\n"

clean:
	@ rm -rf $(OBJ_DIR)
	@ printf "$(GREEN)clean done ! $(RESET)\n"

fclean:	clean
	@ rm -f $(NAME)
	@ rm -f test
	@ printf "$(GREEN)fclean done ! $(RESET)\n"

re: fclean all

test: all
	@ printf "$(YELLOW)Compiling main test ...$(RESET)\n"
	@ $(CC) $(CFLAGS) -I include/ -D BONUS=0 main.c $(NAME) -o test

test_bonus: bonus
	@ printf "$(YELLOW)Compiling bonus main test ...$(RESET)\n"
	@ $(CC) $(CFLAGS) -I include/ -D BONUS=1 main.c $(NAME) -o test
