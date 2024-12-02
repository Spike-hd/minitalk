
# Répertoires
LIBFT_DIR = libft/_libft
PRINTF_DIR = libft/ft_printf

# Fichiers sources
SERVER_SRCS = server.c
CLIENT_SRCS = client.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_SRCS = client_bonus.c

# Fichiers objets
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
B_SERVER_OBJS = $(SERVER_BONUS_SRCS:.c=.o)
B_CLIENT_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Bibliothèques et headers
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
INC = minitalk.h $(PRINTF_DIR)/ft_printf.h $(LIBFT_DIR)/libft.h

# Noms des exécutables
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

# Règle par défaut : compiler les exécutables
all: $(LIBFT) $(PRINTF) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

# Créer la bibliothèque libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Créer la bibliothèque ft_printf
$(PRINTF):
	make -C $(PRINTF_DIR)

# Créer les exécutables
$(SERVER): $(SERVER_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER) $(LIBFT) $(PRINTF)

$(CLIENT): $(CLIENT_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT) $(LIBFT) $(PRINTF)

$(SERVER_BONUS): $(B_SERVER_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(B_SERVER_OBJS) -o $(SERVER_BONUS) $(LIBFT) $(PRINTF)

$(CLIENT_BONUS): $(B_CLIENT_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(B_CLIENT_OBJS) -o $(CLIENT_BONUS) $(LIBFT) $(PRINTF)

# Règle pour générer les fichiers objets
%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

# Bonus : compiler la version bonus
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

# Nettoyage des fichiers objets
clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(B_SERVER_OBJS) $(B_CLIENT_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

# Nettoyage complet (objets + exécutables)
fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

# Recompilation complète
re: fclean all

# Marque que les règles ne sont pas des fichiers
.PHONY: all bonus clean fclean re
