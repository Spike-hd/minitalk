NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
OBJ_DIR = objects

FILES = ft_printf.c print_char.c print_hexa.c print_nbr.c print_string.c

SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating library $(NAME)..."
	ar rcs $(NAME) $(OBJ)
	@echo "$(NAME) successfully created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
