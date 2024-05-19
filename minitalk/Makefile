CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

SRCS_C = mandatory/client.c mandatory/ft_atoi.c
SRCS_S = mandatory/server.c mandatory/ft_atoi.c

SRCS_C_BONUS = bonus/client_bonus.c bonus/ft_atoi_bonus.c 
SRCS_S_BONUS = bonus/server_bonus.c bonus/ft_atoi_bonus.c bonus/ft_putnbr_bonus.c bonus/ft_putchar_bonus.c

OBJS_C = $(SRCS_C:.c=.o)
OBJS_S = $(SRCS_S:.c=.o)

OBJS_C_BONUS = $(SRCS_C_BONUS:.c=.o)
OBJS_S_BONUS = $(SRCS_S_BONUS:.c=.o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(CLIENT) $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

mandatory/%.o : mandatory/%.c mandatory/minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c bonus/minitalk_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT): $(OBJS_C)
	$(CC) $(CFLAGS) $^ -o $(CLIENT)

$(SERVER): $(OBJS_S)
	$(CC) $(CFLAGS) $^ -o $(SERVER)

$(CLIENT_BONUS): $(OBJS_C_BONUS)
	$(CC) $(CFLAGS) $^ -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJS_S_BONUS)
	$(CC) $(CFLAGS) $^ -o $(SERVER_BONUS)

clean:
	$(RM) $(OBJS_C) $(OBJS_S)  $(OBJS_C_BONUS) $(OBJS_S_BONUS)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)  $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all
