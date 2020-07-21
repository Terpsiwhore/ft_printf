# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 12:05:39 by kcorazon          #+#    #+#              #
#    Updated: 2020/07/21 12:05:42 by kcorazon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

#============================================================================================================================

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -O2

#============================================================================================================================

OBJ_DIR		= obj/
LIB_DIR		= libft/
HDR_DIR		= includes/
#----------------------------------------------------------------------------------------------------------------------------
PTF_HDR		= $(addprefix $(HDR_DIR), ft_printf.h)
PTF_SRC		= ft_printf.c
PTF_OBJ		= $(addprefix $(OBJ_DIR), $(PTF_SRC:.c=.o))
#----------------------------------------------------------------------------------------------------------------------------
PRS_DIR		= parser/
PRS_HDR		= $(addprefix $(HDR_DIR), ft_parser.h)
PRS_SRC		= ft_parse_flags.c	ft_parse_precision.c	ft_parse_type.c		ft_parse_width.c	ft_parser.c
PRS_OBJ		= $(addprefix $(OBJ_DIR), $(PRS_SRC:.c=.o))
#----------------------------------------------------------------------------------------------------------------------------
COR_DIR		= core/
COR_HDR		= $(addprefix $(HDR_DIR), ft_core.h)
COR_SRC		= ft_core.c			ft_core_type_c.c		ft_core_type_i.c	ft_core_type_p.c	ft_core_type_pc.c \
			  ft_core_type_s.c	ft_core_type_u.c		ft_core_type_x.c
COR_OBJ		= $(addprefix $(OBJ_DIR), $(COR_SRC:.c=.o))
#----------------------------------------------------------------------------------------------------------------------------
OBJS		= $(PTF_OBJ) $(PRS_OBJ) $(COR_OBJ)

#============================================================================================================================

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_DIR) objs
		@make -C $(LIB_DIR)
		@cp $(LIB_DIR)libft.a ./$(NAME)
		@ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

.PHONY: objs
objs: $(PTF_OBJ) $(PRS_OBJ) $(COR_OBJ)

$(PTF_OBJ): $(OBJ_DIR)%.o: %.c $(PTF_HDR)
		$(CC) -I$(HDR_DIR) -I$(LIB_DIR)  $(FLAGS) -c $< -o $@

$(PRS_OBJ): $(OBJ_DIR)%.o: $(PRS_DIR)%.c $(PRS_HDR)
		$(CC) -I$(HDR_DIR) -I$(LIB_DIR)  $(FLAGS) -c $< -o $@

$(COR_OBJ): $(OBJ_DIR)%.o: $(COR_DIR)%.c $(COR_HDR)
		$(CC) -I$(HDR_DIR) -I$(LIB_DIR)  $(FLAGS) -c $< -o $@

#============================================================================================================================

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean

.PHONY: fclean
fclean: clean
		rm -rf $(NAME)
		@make -C $(LIB_DIR) fclean

.PHONY: re
re: fclean all
		@make -C $(LIB_DIR) re

#============================================================================================================================
