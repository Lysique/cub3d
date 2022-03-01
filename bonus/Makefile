# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/01 08:18:53 by tamighi           #+#    #+#              #
#    Updated: 2022/03/01 16:32:04 by tamighi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
SANITIZEFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
NORMALFLAGS = -Wall -Wextra -Werror
CFLAGS = $(NORMALFLAGS)
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
OBJDIR = objs/
MLX_DIR = mlx/
INCLUDES = includes/
GLOBAL_INCLUDES = includes/define.h includes/global.h
MK_OBJDIR = $(shell mkdir -p $(OBJDIR))

C_OBJS = $(OBJS) $(GLOBAL_OBJS) $(PARSER_OBJS) $(KEY_HOOK_OBJS) $(DISPLAY_OBJS) $(LOOP_HOOK_OBJS)
C_FILES = $(SRCS) $(GLOBAL_SRCS) $(PARSER_SRCS) $(KEY_HOOK_SRCS) $(DISPLAY_SRCS) $(LOOP_HOOK_SRCS)

##### SRCS FILES ######

SRCS_FILES = main.c cub3d.c structure_init.c \
			 imgs_creator.c img_resize.c create_shaders.c \
			 create_menu_imgs.c

SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = $(addprefix $(OBJDIR)srcs_, $(SRCS_FILES:.c=.o))
SRCS_HEADER = $(INCLUDES)srcs.h $(GLOBAL_INCLUDES)

$(OBJDIR)srcs_%.o: $(SRCS_DIR)%.c $(SRCS_HEADER)
	$(MK_OBJDIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

##### GLOBAL FILES ######

GLOBAL_FILES = my_write.c wr_and_ex.c free_and_exit.c \
			   utils.c set_cubptr.c error_manager.c \
			   math_utils.c variables_init.c variables_reset.c \
			   game_state_manager.c

GLOBAL_DIR = srcs/global/
GLOBAL_SRCS = $(addprefix $(GLOBAL_DIR), $(GLOBAL_FILES))
GLOBAL_OBJS = $(addprefix $(OBJDIR)global_, $(GLOBAL_FILES:.c=.o))
GLOBAL_HEADER = $(GLOBAL_INCLUDES)

$(OBJDIR)global_%.o: $(GLOBAL_DIR)%.c $(GLOBAL_HEADER)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

##### PARSER FILES ######

PARSER_FILES = parser.c parser_free.c parser_error.c \
			   map_error.c map_checker.c texture_error.c\
			   fd_to_arr.c parse_map.c parse_textures.c \
			   player_init.c parser_utils.c parser_utils2.c \
			   add_texture.c doors_init.c parser_utils3.c \
			   ennemy_init.c map_dist_init.c add_enemy.c \
			   sprs_init.c medikit_init.c

PARSER_DIR = srcs/parser/
PARSER_SRCS = $(addprefix $(PARSER_DIR), $(PARSER_FILES))
PARSER_OBJS = $(addprefix $(OBJDIR)parser_, $(PARSER_FILES:.c=.o))
PARSER_HEADER = $(INCLUDES)parser.h $(GLOBAL_INCLUDES)

$(OBJDIR)parser_%.o: $(PARSER_DIR)%.c $(PARSER_HEADER)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

##### DISPLAY FILES ######

DISPLAY_FILES = display.c view_casting.c \
				display_map.c display_char.c \
				display_utils.c display_gun.c display_menubar.c \
				f_c_casting.c draw_sprites.c sprites_init.c \
				hit_wall_check.c draw_line.c draw_img.c \
				mkits_in_sprites.c

DISPLAY_DIR = srcs/display/
DISPLAY_SRCS = $(addprefix $(DISPLAY_DIR), $(DISPLAY_FILES))
DISPLAY_OBJS = $(addprefix $(OBJDIR)display_, $(DISPLAY_FILES:.c=.o))
DISPLAY_HEADER = $(INCLUDES)display.h $(GLOBAL_INCLUDES)

$(OBJDIR)display_%.o: $(DISPLAY_DIR)%.c $(DISPLAY_HEADER)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

##### KEY_HOOK FILES ######

KEY_HOOK_FILES = key_press.c key_release.c mouse_press.c \
				 mouse_release.c mouse_move.c mouse_click_menu.c


KEY_HOOK_DIR = srcs/key_hook/
KEY_HOOK_SRCS = $(addprefix $(KEY_HOOK_DIR), $(KEY_HOOK_FILES))
KEY_HOOK_OBJS = $(addprefix $(OBJDIR)key_hook_, $(KEY_HOOK_FILES:.c=.o))
KEY_HOOK_HEADER = $(INCLUDES)key_hook.h $(GLOBAL_INCLUDES)

$(OBJDIR)key_hook_%.o: $(KEY_HOOK_DIR)%.c $(KEY_HOOK_HEADER)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

##### LOOP_HOOK FILES ######

LOOP_HOOK_FILES = loop_hook.c player_manager.c door_manager.c \
				  loop_hook_utils.c gun_manager.c shoot_manager.c \
				  enemy_manager.c hit_manager.c emotion_manager.c \
				  map_dist_manager.c enemy_still.c set_enemy_angle.c \
				  set_enemy_action.c enemy_attack.c enemy_die.c \
				  enemy_move.c order_enemies.c set_en_img_angle.c \
				  manage_boss.c boss_found_door.c throw_missile_manager.c \
				  missile_manager.c mkits_manager.c dying_boss.c

LOOP_HOOK_DIR = srcs/loop_hook/
LOOP_HOOK_SRCS = $(addprefix $(LOOP_HOOK_DIR), $(LOOP_HOOK_FILES))
LOOP_HOOK_OBJS = $(addprefix $(OBJDIR)loop_hook_, $(LOOP_HOOK_FILES:.c=.o))
LOOP_HOOK_HEADER = $(INCLUDES)loop_hook.h $(GLOBAL_INCLUDES)

$(OBJDIR)loop_hook_%.o: $(LOOP_HOOK_DIR)%.c $(LOOP_HOOK_HEADER)
	$(MK_OBJDIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

##### RULES #####

all: $(NAME)

$(NAME): $(C_OBJS)
	make -C $(MLX_DIR)
	$(CC) $(MLX_FLAGS) -I $(INCLUDES) $(C_FILES) $(CFLAGS) -o $(NAME)

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
