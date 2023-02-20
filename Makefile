SRCS	=	ft_printf.c \
			utils.c \

OBJS		= $(addprefix $(BIN_DIR)/, $(SRCS:.c=.o))

NAME		= libftprintf.a
LIBC		= ar rcs
LIBR		= ranlib
CC			= gcc
RM			= rm -f
RM_DIR		= rm -rf
CFLAGS		= -Wall -Wextra -Werror
BIN_DIR 	= bin
LIBFT		= libft/libft.a

all: $(LIBFT) $(NAME)

$(BIN_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(BIN_DIR) $(OBJS)
	$(LIBC) $(NAME) $(OBJS) $(LIBFT)
	$(LIBR) $(NAME)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(LIBFT):
	make -C libft

clean:
	$(RM_DIR) $(BIN_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all