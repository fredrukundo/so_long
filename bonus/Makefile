# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 21:23:00 by frukundo          #+#    #+#              #
#    Updated: 2024/02/05 19:03:10 by frukundo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long_bonus

CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

INCLUDE	= -I /usr/local/include
LIBMLX	= -L /usr/local/lib

PRINTF      = ../ft_printf/libftprintf.a

SRCS_BONUS = main_bonus.c srcs_bonus/parsing_bonus/gnl_bonus.c srcs_bonus/parsing_bonus/check_map_bonus.c srcs_bonus/parsing_bonus/path_checker_bonus.c\
		  srcs_bonus/parsing_bonus/check_extention_bonus.c srcs_bonus/parsing_bonus/utils_bonus.c srcs_bonus/parsing_bonus/utils2_bonus.c srcs_bonus/parsing_bonus/check_ecp_bonus.c \
		  srcs_bonus/parsing_bonus/check_walls_bonus.c srcs_bonus/parsing_bonus/check_rectangular_bonus.c srcs_bonus/parsing_bonus/get_map_bonus.c \
		  srcs_bonus/parsing_bonus/map_error_bonus.c srcs_bonus/parsing_bonus/map_len_bonus.c \
		  srcs_bonus/parsing_bonus/check_characters_bonus.c srcs_bonus/parsing_bonus/check_dir_bonus.c srcs_bonus/parsing_bonus/check_player_bonus.c \
		  srcs_bonus/parsing_bonus/get_collectibles_bonus.c srcs_bonus/parsing_bonus/get_player_position_bonus.c \
		  srcs_bonus/window_bonus.c srcs_bonus/rendering_bonus.c srcs_bonus/player_moves_bonus.c \
		  srcs_bonus/moves_bonus.c srcs_bonus/ft_free_bonus.c srcs_bonus/free_map_bonus.c \
		  srcs_bonus/reset_bonus.c srcs_bonus/ft_itoa_bonus.c srcs_bonus/enemy_moves_bonus.c

BONUS_HEADER = includes_bonus/so_long_bonus.h

BONUS_OBJS = $(SRCS_BONUS:.c=.o)

all: $(PRINTF) $(NAME)


$(NAME): $(BONUS_OBJS) $(BONUS_HEADER)
	@echo "$(YELLOW)Building $(NAME)$(NC)"
	@$(CC) $(FLAGS) $(BONUS_OBJS) $(INCLUDE) $(PRINTF) $(LIBMLX)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)$(NAME) built successfully$(NC)"

%.o: %.c $(BONUS_HEADER) $(PRINTF)
	@$(CC) -Wall -Wextra -Werror $(OPTS) -c $< -o $@

$(PRINTF):
	@echo "$(YELLOW)Building printf$(NC)"
	@$(MAKE) -C ../ft_printf
	@echo "$(GREEN)printf built successfully$(NC)"


clean:
	@$(MAKE) clean -C ../ft_printf
	@echo "$(YELLOW)Cleaning object files$(NC)"
	@rm -rf $(BONUS_OBJS)
	@echo "$(GREEN)Object files cleaned successfully$(NC)"

fclean: clean
	@$(MAKE) fclean -C ../ft_printf
	@echo "$(YELLOW)Cleaning binaries$(NC)"
	@rm -rf $(NAME)
	@echo "$(GREEN)Binaries cleaned successfully$(NC)"

re: fclean all

.PHONY: all clean fclean re



