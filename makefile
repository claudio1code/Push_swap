NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

SRCS_DIR = srcs/
OBJS_DIR = objs/
INC_DIR = includes/
LIBFT_DIR = libft/

SRCS_LIST = 	parsing.c \
				main.c \
				utils_stack.c \
				indexing.c \
				push_operations.c \
				swap_operations.c \
				rotate_operations.c \
				rev_rotate_operations.c \
				verification.c \
				sort_small.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_LIST:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I $(INC_DIR) -I$(LIBFT_DIR)/includes
LDFLAGS = -L$(LIBFT_DIR) -lft

GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
DEF_COLOR = \033[0;39m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo -n "$(YELLOW)A linkar $(NAME)... $(DEF_COLOR)"
	@sh -c 'i=0; while [ $$i -lt 10 ]; do \
		echo -n "\b|"; sleep 0.05; \
		echo -n "\b/"; sleep 0.05; \
		echo -n "\b-"; sleep 0.05; \
		echo -n "\b\\"; sleep 0.05; \
		i=$$(($$i+1)); \
	done'
	@echo "\b\b$(GREEN)OK!$(DEF_COLOR)\r"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@echo -n "$(CYAN)A compilar $<... $(DEF_COLOR)"
	@sh -c 'i=0; while [ $$i -lt 10 ]; do \
		echo -n "\b|"; sleep 0.05; \
		echo -n "\b/"; sleep 0.05; \
		echo -n "\b-"; sleep 0.05; \
		echo -n "\b\\"; sleep 0.05; \
		i=$$(($$i+1)); \
	done'
	@echo "\b\b$(GREEN)OK!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -sC $(LIBFT_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@make -sC $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -sC $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus