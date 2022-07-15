# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthitiku <sthitiku@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 21:22:32 by sthitiku          #+#    #+#              #
#    Updated: 2022/07/15 22:18:36 by sthitiku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ps_args.c ps_lstadd.c ps_check_lst.c ps_median.c
OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

LIBFT_DIR = libft/
SRCS_DIR = srcs/
OBJS_DIR = objs/
INCS_DIR = incs/

CC = gcc
# CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME): $(addprefix $(OBJS_DIR), $(OBJS)) $(addprefix $(INCS_DIR), $(HEADER))
	@make -C $(LIBFT_DIR) --silent
	$(CC) $(addprefix $(OBJS_DIR), $(OBJS)) -o $(NAME) -L $(LIBFT_DIR) -lft

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR) --silent
	$(RM) $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR) --silent
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
