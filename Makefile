# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 21:22:32 by sthitiku          #+#    #+#              #
#    Updated: 2022/09/10 02:33:35 by sthitiku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker

M_MAIN = main.c
B_MAIN = b_main.c

SRCS =	ps_args.c ps_lstops.c ps_check_lst.c ps_median.c ps_push.c ps_rotate.c \
		ps_btoa.c ps_swap.c ps_atoi.c push_swap.c ps_clear.c b_utils.c

OBJS = $(SRCS:.c=.o)
M_OBJS = $(M_MAIN:.c=.o)
B_OBJS = $(B_MAIN:.c=.o)

HEADER = push_swap.h

LIBFT_DIR = libft/
SRCS_DIR = srcs/
OBJS_DIR = objs/
INCS_DIR = incs/

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME): $(addprefix $(OBJS_DIR), $(OBJS)) $(addprefix $(OBJS_DIR), $(M_OBJS)) $(addprefix $(INCS_DIR), $(HEADER))
	@make -C $(LIBFT_DIR) --silent
	$(CC) $(addprefix $(OBJS_DIR), $(OBJS)) $(addprefix $(OBJS_DIR), $(M_OBJS)) -o $(NAME) -L $(LIBFT_DIR) -lft

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(B_NAME)

$(B_NAME): $(NAME) $(addprefix $(OBJS_DIR), $(B_OBJS)) $(addprefix $(INCS_DIR), $(HEADER))
	@make -C $(LIBFT_DIR) --silent
	$(CC) $(addprefix $(OBJS_DIR), $(OBJS)) $(addprefix $(OBJS_DIR), $(B_OBJS)) -o $(B_NAME) -L $(LIBFT_DIR) -lft

clean:
	@make clean -C $(LIBFT_DIR) --silent
	$(RM) $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR) --silent
	$(RM) $(NAME) $(B_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
