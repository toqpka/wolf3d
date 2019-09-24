# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 18:09:40 by gwaymar-          #+#    #+#              #
#    Updated: 2019/09/20 10:46:05 by gwaymar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := wolf3d

# SRCS files
SRCS_PATH := ./srcs
SRCS_FILES := main.c color.c functions.c reader.c sounds.c time.c \
							weapon/riffle_fraps.c \
							weapon/riffle.c \
							ui/draw_ui.c \
							ui/menu.c \
							ui/ui.c \
							render/draw_adv.c \
							render/draw.c \
							render/image.c \
							render/render.c \
							loader/assets_loader.c \
							loader/errors.c \
							loader/options.c \
							loader/tga_reader.c \
							init/init_adv.c \
							init/init.c \
							controlls/controls.c \
							controlls/key.c \
							controlls/movements.c
SRCS := $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

# OBJ files
OBJECTS_PATH := ./objs
OBJECTS_FILES := $(SRCS_FILES:.c=.o)
OBJECTS := $(addprefix $(OBJECTS_PATH)/, $(OBJECTS_FILES))
SUB_DIR_OBJ := $(patsubst %, $(OBJECTS_PATH)/%, $(notdir $(shell find $(SRCS_PATH) -type d -not -path $(SRCS_PATH))))

# cc FLAGS
CC := gcc
CCFLAGS := -Wall -Wextra -Werror

# SDL2
SDL_PATH := ./frameworks
SDL_NAME := SDL2
SDL_INC := -I $(addprefix $(SDL_PATH)/,SDL2.framework/Versions/A/Headers)
SDL_LNK := -framework SDL2 -F $(SDL_PATH)
SDL_rpath := -rpath $(SDL_PATH)
SDL_MIXER_INC := -I $(addprefix $(SDL_PATH)/,SDL2_mixer.framework/Versions/A/Headers)
SDL_MIXER_LNK := -framework SDL2_mixer -F $(SDL_PATH)
SDL2 := $(SDL_rpath) $(SDL_LNK) $(SDL_MIXER_LNK)

# libft
LIB_PATH := ./utils/libft
LIB_NAME := LibFT
LIB := $(addprefix $(LIB_PATH)/,libft.a)
LIB_INC := -I $(LIB_PATH)
LIB_LNK := -L $(LIB_PATH) -lft

# include lib and sdl and header
INCLUDES := $(LIB_INC) $(SDL_INC) $(SDL_MIXER_INC) -I ./includes
HEADER := ./includes/wolf3d.h ./includes/wolf3d_prototypes.h ./includes/wolf3d_structs.h

# console colors
COLOR_RESET := \033[0m
COLOR_RED := \033[31m
COLOR_BLUE := \033[34m
COLOR_YELLOW := \033[33m
COLOR_GREEN := \033[32m
COLOR_INVERT := \033[7m
SUCCESS := [$(COLOR_GREEN)✓$(COLOR_RESET)]
SUCCESS_OK := [$(COLOR_GREEN)OK$(COLOR_RESET)]
# clear_row (delete all symymbols)
CLEAR_ROW := @echo "\033[1A\033[K\033[1A"

#	First target
all: $(NAME)

$(OBJECTS): $(OBJECTS_PATH)/%.o: $(SRCS_PATH)/%.c $(HEADER) | $(SUB_DIR_OBJ)
	@echo -n ' $@: '
	@$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(SUCCESS)"

$(SUB_DIR_OBJ):
	@mkdir -p $(OBJECTS_PATH) $(SUB_DIR_OBJ) > /dev/null

$(LIB): | $(HEADER)
	@echo "$(COLOR_RED) > $(COLOR_RESET)Compilation $(NAME)"

$(NAME): $(LIB) $(OBJECTS) $(HEADER)
	@echo "$(COLOR_YELLOW) Creating OBJ .o $(COLOR_RESET)$(SUCCESS_OK)"
	@echo "$(COLOR_YELLOW) $(LIB_NAME)           $(COLOR_RESET)[$(COLOR_YELLOW)Compiling...$(COLOR_RESET)]"
	@make -C $(LIB_PATH) > /dev/null
	$(CLEAR_ROW)
	@echo "$(COLOR_YELLOW) $(LIB_NAME)           $(COLOR_RESET)$(SUCCESS_OK)"
	@echo "$(COLOR_YELLOW) $(NAME)          $(COLOR_RESET)[$(COLOR_YELLOW)Compiling...$(COLOR_RESET)]"
	@$(CC) $(SDL2) $(CCFLAGS) $(OBJECTS) $(LIB_LNK) -o $(NAME)
	$(CLEAR_ROW)
	@echo "$(COLOR_YELLOW) $(NAME)          $(COLOR_RESET)$(SUCCESS_OK)"
	@echo "$(COLOR_RED) > $(COLOR_BLUE)Compilation is ended$(COLOR_RESET)"

#	Removing objects
clean:
	@echo "$(COLOR_RED)removing  object files - ...$(COLOR_RESET)"
	@make -C $(LIB_PATH) clean > /dev/null
	@rm -rf $(OBJECTS_PATH) > /dev/null
	$(CLEAR_ROW)
	@echo "$(COLOR_RED)removing  object files - done$(COLOR_RESET)"

#	Removing objects and project_launcher
fclean: clean
	@echo "$(COLOR_RED)removing  $(NAME) - ...$(COLOR_RESET)"
	@make -C $(LIB_PATH) fclean > /dev/null
	@rm -rf $(NAME) > /dev/null
	$(CLEAR_ROW)
	@echo "$(COLOR_RED)removing  $(NAME) - done$(COLOR_RESET)"

#	All removing then compiling
re: fclean all

.PHONY: clean fclean re all
