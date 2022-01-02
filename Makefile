# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamighi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/01 08:18:53 by tamighi           #+#    #+#              #
#    Updated: 2022/01/02 12:50:39 by tamighi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
OBJDIR = objs/
MLX_DIR = mlx/
INCLUDES = includes/
MK_OBJDIR = $(shell mkdir -p $(OBJDIR))

C_OBJS = $(OBJS) $(GLOBAL_OBJS) $(PARSER_OBJS) $(KEY_HOOK_OBJS) $(DISPLAY_OBJS)
C_FILES = $(SRCS) $(GLOBAL_SRCS) $(PARSER_SRCS) $(KEY_HOOK_SRCS) $(DISPLAY_SRCS)

##### SRCS FILES ######

SRCS_FILES = main.c cub3d.c
SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = $(addprefix $(OBJDIR)srcs_, $(SRCS_FILES:.c=.o))

$(OBJDIR)srcs_%.o: $(SRCS_DIR)%.c
	$(MK_OBJDIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

##### GLOBAL FILES ######

GLOBAL_FILES = my_write.c wr_and_ex.c
GLOBAL_DIR = srcs/global/
GLOBAL_SRCS = $(addprefix $(GLOBAL_DIR), $(GLOBAL_FILES))
GLOBAL_OBJS = $(addprefix $(OBJDIR)global_, $(GLOBAL_FILES:.c=.o))

$(OBJDIR)global_%.o: $(GLOBAL_DIR)%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

##### PARSER FILES ######

PARSER_FILES = parser.c parser_error.c parse_textures.c parser_utils.c add_texture_to_struct.c parse_map.c map_checker.c
PARSER_DIR = srcs/parser/
PARSER_SRCS = $(addprefix $(PARSER_DIR), $(PARSER_FILES))
PARSER_OBJS = $(addprefix $(OBJDIR)parser_, $(PARSER_FILES:.c=.o))

$(OBJDIR)parser_%.o: $(PARSER_DIR)%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

##### DISPLAY FILES ######

DISPLAY_FILES = display.c ray_casting.c display_map.c
DISPLAY_DIR = srcs/display/
DISPLAY_SRCS = $(addprefix $(DISPLAY_DIR), $(DISPLAY_FILES))
DISPLAY_OBJS = $(addprefix $(OBJDIR)display_, $(DISPLAY_FILES:.c=.o))

$(OBJDIR)display_%.o: $(DISPLAY_DIR)%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

##### KEY_HOOK FILES ######

KEY_HOOK_FILES = key_hook.c
KEY_HOOK_DIR = srcs/key_hook/
KEY_HOOK_SRCS = $(addprefix $(KEY_HOOK_DIR), $(KEY_HOOK_FILES))
KEY_HOOK_OBJS = $(addprefix $(OBJDIR)key_hook_, $(KEY_HOOK_FILES:.c=.o))

$(OBJDIR)key_hook_%.o: $(KEY_HOOK_DIR)%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

##### RULES #####

all: $(NAME)

$(NAME): $(C_OBJS)
	make -C $(MLX_DIR)
	$(CC) $(MLX_FLAGS) -I $(INCLUDES) $(C_FILES) -o $(NAME)

mk_objdir:
	mkdir -p $(OBJDIR)

clean:
	make -C $(MLX_DIR) clean
	rm -f $(C_OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
