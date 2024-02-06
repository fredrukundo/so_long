GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
NC = \033[0m

PRINTF = ft_printf/libftprintf.a

INCLUDE	= -I /usr/local/include
LIBMLX	= -L /usr/local/lib

CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

NAME = so_long

SRCS = main.c srcs/parsing/get_next_line.c srcs/parsing/check_map.c  srcs/parsing/path_checker.c \
		  srcs/parsing/check_extention.c srcs/parsing/utils.c srcs/parsing/utils2.c srcs/parsing/check_ecp.c \
		  srcs/parsing/check_wall.c srcs/parsing/check_rectangular.c srcs/parsing/get_map.c \
		  srcs/parsing/map_error.c srcs/parsing/map_len.c \
		  srcs/parsing/check_characters.c srcs/parsing/check_dir.c srcs/parsing/check_player.c \
		  srcs/parsing/get_collectables.c srcs/parsing/get_player_position.c \
		  srcs/window.c srcs/rendering.c srcs/player_moves.c \
		  srcs/moves.c srcs/ft_free.c srcs/free_map.c

OBJS = $(SRCS:.c=.o)
HEADER	= includes/so_long.h

all: $(PRINTF) $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@echo "$(YELLOW)Building $(NAME)$(NC)"
	@$(CC) $(FLAGS) $(OBJS) $(INCLUDE) $(PRINTF) $(LIBMLX)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)$(NAME) built successfully$(NC)"

%.o: %.c $(HEADER) $(PRINTF)
	@$(CC) -Wall -Wextra -Werror $(OPTS) -c $< -o $@



$(PRINTF):
	@echo "$(YELLOW)Building printf$(NC)"
	@$(MAKE) -C ft_printf
	@echo "$(GREEN)printf built successfully$(NC)"

clean:
	@$(MAKE) clean -C ft_printf
	@echo "$(YELLOW)Cleaning object files$(NC)"
	@rm -rf $(OBJS)
	@echo "$(GREEN)Object files cleaned successfully$(NC)"


fclean: clean
	@$(MAKE) fclean -C ft_printf
	@echo "$(YELLOW)Cleaning binaries$(NC)"
	@rm -rf $(NAME)
	@echo "$(GREEN)Binaries cleaned successfully$(NC)"


re: fclean all

.PHONY: all clean fclean re 
