INC=/usr/include


INCLIB=$(INC)/../lib

CC=gcc

CFLAGS= -I$(INC) -Iincludes -Imlx_linux -g -Werror -Wextra -Wall

NAME= fractol

SRC = srcs/main.c \
		srcs/mlx.c \
		srcs/launch.c \
		srcs/error.c \
		srcs/utils.c

OBJ = $(SRC:%.c=%.o)

LFLAGS = -Lmlx_linux -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): minilib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS) -g3 -fsanitize=address

minilib:
		cd mlx_linux ; ./configure ; cd ..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all
