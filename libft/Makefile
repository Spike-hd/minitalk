NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Répertoires des sources et objets
SRC_DIR = srcs
PRINTF_DIR = $(SRC_DIR)/ft_printf
OBJ_DIR = objects

# Fichiers sources principaux
FILES = $(SRC_DIR)/ft_atoi.c $(SRC_DIR)/ft_bzero.c $(SRC_DIR)/ft_calloc.c $(SRC_DIR)/ft_isalpha.c $(SRC_DIR)/ft_isalnum.c \
        $(SRC_DIR)/ft_isascii.c $(SRC_DIR)/ft_isdigit.c $(SRC_DIR)/ft_isprint.c $(SRC_DIR)/ft_itoa.c $(SRC_DIR)/ft_memchr.c \
        $(SRC_DIR)/ft_memcmp.c $(SRC_DIR)/ft_memcpy.c $(SRC_DIR)/ft_memmove.c $(SRC_DIR)/ft_memset.c $(SRC_DIR)/ft_putchar_fd.c \
        $(SRC_DIR)/ft_putendl_fd.c $(SRC_DIR)/ft_putnbr_fd.c $(SRC_DIR)/ft_putstr_fd.c $(SRC_DIR)/ft_strchr.c \
        $(SRC_DIR)/ft_strjoin.c $(SRC_DIR)/ft_strdup.c $(SRC_DIR)/ft_striteri.c $(SRC_DIR)/ft_strlcat.c $(SRC_DIR)/ft_strlcpy.c \
        $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strmapi.c $(SRC_DIR)/ft_strnstr.c $(SRC_DIR)/ft_strncmp.c $(SRC_DIR)/ft_strrchr.c \
        $(SRC_DIR)/ft_strtrim.c $(SRC_DIR)/ft_substr.c $(SRC_DIR)/ft_tolower.c $(SRC_DIR)/ft_toupper.c $(SRC_DIR)/ft_split.c \
        $(SRC_DIR)/ft_lstnew.c $(SRC_DIR)/ft_lstadd_front.c $(SRC_DIR)/ft_lstsize.c $(SRC_DIR)/ft_lstlast.c \
        $(SRC_DIR)/ft_lstadd_back.c $(SRC_DIR)/ft_lstdelone.c $(SRC_DIR)/ft_lstclear.c $(SRC_DIR)/ft_lstiter.c \
        $(SRC_DIR)/ft_lstmap.c $(SRC_DIR)/get_next_line.c

# Fichiers sources de ft_printf
SRCS_PRINTF = $(PRINTF_DIR)/ft_printf.c $(wildcard $(PRINTF_DIR)/utils/*.c)

# Tous les fichiers sources
FILES_ALL = $(FILES) $(SRCS_PRINTF)

# Fichiers objets générés
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES_ALL:$(SRC_DIR)/%.c=%.o))

# Règle principale
all: $(NAME)

# Création de la bibliothèque
$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

# Compilation des fichiers .c en fichiers .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(dir $@)  # Créer le répertoire des objets si nécessaire
		$(CC) $(CFLAGS) -c $< -o $@

# Compilation spécifique des fichiers de ft_printf
$(OBJ_DIR)/ft_printf/%.o: $(PRINTF_DIR)/%.c
		@mkdir -p $(dir $@)  # Créer le répertoire des objets de ft_printf
		$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
		rm -f $(OBJ)
		rm -rf $(OBJ_DIR)

# Nettoyage complet (objets + bibliothèque)
fclean: clean
		rm -f $(NAME)

# Refaire la compilation
re: fclean all

# Déclare les cibles comme étant "virtuelles" pour éviter des conflits avec des fichiers
.PHONY: all clean fclean re
