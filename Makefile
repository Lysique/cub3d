# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamighi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 13:17:02 by tamighi           #+#    #+#              #
#    Updated: 2021/12/05 13:08:26 by tamighi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= cub3d
INCLUDES= includes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
OBJDIR	= objs
MLX_DIR = mlx

SOURCES	= print_my_struct.c main.c cub3d.c error_manager.c free_manager.c
SRCDIR 	= srcs
SRCS 	= $(addprefix $(SRCDIR)/, $(SOURCES))
OBJS	= $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

STRUCT		= file_reading.c game_struct_init.c add_texture_paths.c add_map.c get_next_line.c utils.c
STRUCT_DIR 	= srcs/struct_init
STRUCT_SRCS = $(addprefix $(STRUCT_DIR)/, $(STRUCT))
STRUCT_OBJS	= $(addprefix $(OBJDIR)/, $(STRUCT:.c=.o))

all : 		$(NAME)

$(NAME) :	$(OBJS) $(STRUCT_OBJS)
	make -C $(MLX_DIR)
	$(CC) $(MLX_FLAGS) -I $(INCLUDES) $(OBJS) $(STRUCT_OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@
	
$(OBJDIR)/%.o: $(STRUCT_DIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	make -C $(MLX_DIR) clean
	rm -f $(OBJS) $(STRUCT_OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re :		fclean all

.PHONY: all clean fclean re
