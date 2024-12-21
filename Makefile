NAME = cub3D

SRCS = inc/GNL/get_next_line.c cub3d.c utils/ft_check.c utils/ft_error.c \
		utils/ft_read_map.c utils/ft_txt_control.c utils/ft_free.c \
		utils/ft_map_control.c utils/ft_map_fill.c game/init_game.c game/raycast.c game/game_utils.c \

OBJS = $(SRCS:.c=.o)
MINILIBX = ./inc/minilibx-linux/libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./inc/minilibx-linux
LDFLAGS = -L ./inc/minilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	@clear >/dev/null 2>&1
	@echo "\033[3;32m"
	@echo '________/\\\\\\\\\\________________/\\\____________/\\\\\\\\\\__________/\\\__'
	@echo ' _____/\\\////////________________\/\\\__________/\\\///////\\\________\/\\\__'
	@echo '  ___/\\\/_________________________\/\\\_________\///______/\\\_________\/\\\__'
	@echo '   __/\\\______________/\\\____/\\\_\/\\\________________/\\\//__________\/\\\__'
	@echo '    _\/\\\_____________\/\\\___\/\\\_\/\\\\\\\\\_________\////\\\____/\\\\\\\\\__'
	@echo '     _\//\\\____________\/\\\___\/\\\_\/\\\////\\\___________\//\\\__/\\\////\\\__'
	@echo '      __\///\\\__________\/\\\___\/\\\_\/\\\__\/\\\__/\\\______/\\\__\/\\\__\/\\\__'
	@echo '       ____\////\\\\\\\\\_\//\\\\\\\\\__\/\\\\\\\\\__\///\\\\\\\\\/___\//\\\\\\\/\\_'
	@echo '        _______\/////////___\/////////___\/////////_____\/////////______\///////\//__'
	@echo "\033[0m"
	@echo "\033[32mBuilding $(NAME)...\033[0m"
	@make -C inc/minilibx-linux
	@make -C inc/libft
	@$(CC) $(OBJS) $(MINILIBX) $(LDFLAGS) -Linc/libft -lft -o $(NAME)
	@echo "\033[32m$(NAME) build complete!\033[0m"


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[0;34mCleaning object files...\033[0m"
	@make clean -C inc/libft
	@rm -rf $(OBJS)
	@echo "\033[32mObject files cleaned.\033[0m"

fclean: clean
	@echo "\033[33mPerforming full clean...\033[0m"
	@make fclean -C inc/libft >/dev/null 2>&1
	@rm -f $(NAME)
	@echo "\n\033[31mEverything deleted!\033[0m"

re: fclean all

.PHONY: all clean fclean re
