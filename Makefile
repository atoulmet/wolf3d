# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 16:31:19 by atoulmet          #+#    #+#              #
#    Updated: 2017/03/23 12:08:09 by atoulmet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = wolf3d

SRC_PATH = srcs/

SRCS = exit_success.c restart_img.c trace_line.c raycast.c generate_map.c main.c env_img_init.c ft_error.c events.c put_string.c

OBJ_NAME = $(SRCS:.c=.o)

OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH),$(SRCS))

FLAGS = -Wall -Wextra -Werror 

INC = -I ./includes/ -I./libft

LIB = -L minilibx -lmlx -framework OpenGL -framework AppKit -Llibft/ -lft

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	@gcc $(OBJ) $(INC) $(LIB) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc -c $(FLAGS) $< -o $@ $(INC)

clean :
	@rm -rf $(OBJ_PATH)

fclean : clean
	@rm -rf $(NAME)
	@make -C libft fclean

re : fclean all
