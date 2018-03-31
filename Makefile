# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:39:52 by gsmith            #+#    #+#              #
#    Updated: 2018/03/21 08:27:09 by allauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = clang
FLAG = -Wall -Wextra -Werror -g3
LIBFT = ft
LIBFT_DIR = Libft/
HEADER_PATH = includes
OBJS_PATH = objs
SRCS_PATH = srcs
DPDS_PATH = depend
SRCS = $(addprefix $(SRCS_PATH)/, \
	   main.c)

OBJS = $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)
DPDS = $(SRCS:$(SRCS_PATH)/%.c=$(DPDS_PATH)/%.d)
ERASE_LINE = '\r\033[K'
NC = '\033[0m'
RED = '\033[0;31m'
LRED = '\033[1;31m'
LBLUE = '\033[1;34m'
GREEN = '\033[0;32m'
LGREEN = '\033[1;32m'
ORANGE = '\033[0;33m'
YELLOW = '\033[1;33m'

all: $(NAME)

$(NAME): $(OBJS)
#	@printf $(NC)"[$(NAME)] "$(YELLOW)"Compiling .o files done.\n"$(NC)
	make -C $(LIBFT_DIR)
	#@printf $(NC)"[$(NAME)] "$(LBLUE)
	$(CC) $(FLAG) -I $(HEADER_PATH) -I $(LIBFT_DIR) -o $(NAME) $(OBJS) \
		-L./$(LIBFT_DIR) -l$(LIBFT)
	@printf $(NC)"[$(NAME)] "$(LGREEN)"$(NAME) ready.\n"$(NC)

$(OBJS_PATH)/%.o:
	@printf "[$(NAME)] "$(LBLUE)
	$(CC) $(FLAG) -I $(HEADER_PATH) -I $(LIBFT_DIR) -o $@ \
		-c $(@:$(OBJS_PATH)/%.o=$(SRCS_PATH)/%.c)
	@printf $(NC)

$(DPDS_PATH)/%.d: $(SRCS_PATH)/%.c
	@printf $(NC)"[$(NAME)] "$(LBLUE)
	$(CC) $(CFLAGS) -I $(HEADER_PATH) -I $(LIBFT_DIR) -MM $^ \
		| sed -e '1s/^/$(OBJS_PATH)\//' > $@
	@printf $(NC)"[$(NAME)] "$(YELLOW)"$@ created/updated.\n"$(NC)

clean:
	@make -C $(LIBFT_DIR) clean
	@printf $(NC)"[$(NAME)] "$(RED)
	rm -f $(OBJS)
	@printf $(NC)"[$(NAME)] "$(LRED)".o files cleaned.\n"$(NC)

dclean:
	@printf $(NC)"[$(NAME)] "$(RED)
	rm -f $(DPDS)
	@printf $(NC)"[$(NAME)] "$(LRED)".d files cleaned.\n"$(NC)

fclean:
	@make -C $(LIBFT_DIR) fclean
	@printf "[$(NAME)] "$(RED)
	rm -f $(OBJS)
	@printf $(NC)"[$(NAME)] "$(LRED)".o files cleaned.\n"$(NC)
	@printf "[$(NAME)] "$(RED)
	rm -f $(NAME)
	@printf $(NC)"[$(NAME)] "$(LRED)"$(NAME) cleaned.\n"$(NC)

norm:
	norminette $(SRCS_PATH) $(HEADER_PATH)

re:
	$(MAKE) fclean
	$(MAKE) all

-include $(DPDS)

.PHONY: all clean fclean re
