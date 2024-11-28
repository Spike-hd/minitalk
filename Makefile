
# Répertoires
LIBFT_DIR = libft
SRC_DIR = .
PRINTF_DIR = $(LIBFT_DIR)/ft_printf

# Fichiers sources
SERVER_SRCS = $(SRC_DIR)/server.c
CLIENT_SRCS = $(SRC_DIR)/client.c
SERVER_BONUS_SRCS = $(SRC_DIR)/server_bonus.c
CLIENT_BONUS_SRCS = $(SRC_DIR)/client_bonus.c

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
PRINTF = $(PRINTF_DIR)/ft_printf.a
INC = minitalk.h $(LIBFT_DIR)/libft.h $(PRINTF_DIR)/ft_printf.h

# Noms des exécutables
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

# Règle par défaut : compiler les deux exécutables
all: $(LIBFT) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

# Créer la bibliothèque libft et ft_printf en même temps
$(LIBFT):
	make -C $(LIBFT_DIR)

# Création de l'exécutable serveur / client
$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJS) -L$(LIBFT_DIR) -lft

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJS) -L$(LIBFT_DIR) -lft

# Création de l'exécutable serveur / client bonus
$(SERVER_BONUS): $(B_SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(B_SERVER_OBJS) -L$(LIBFT_DIR) -lft

$(CLIENT_BONUS): $(B_CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(B_CLIENT_OBJS) -L$(LIBFT_DIR) -lft

# Compilation des fichiers .c en .o, avec dépendance aux en-têtes
%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

# Bonus : compiler la version bonus
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

# Nettoyage des fichiers objets
clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(B_SERVER_OBJS) $(B_CLIENT_OBJS)
	make -C $(LIBFT_DIR) clean

# Nettoyage complet (objets + exécutables)
fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	make -C $(LIBFT_DIR) fclean

# Recompilation complète
re: fclean all

# Marque que les règles ne sont pas des fichiers
.PHONY: all bonus clean fclean re
