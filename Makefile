NAME = hmidoun.filler

SRC =	filler.c \
		get_dim.c \
		get_board.c \
		get_piece.c \
		heat_map.c \
		solve.c

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

HEADER = ./includes/filler.h \
		 ./libft/includes/libft.h

INCLUDE_PATH = -I ./includes -I ./libft/includes

LIBFT =	libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(INCLUDE_PATH) $(OBJ) -o $(NAME) $(LIBFT)

obj:
	mkdir -p obj

obj/%.o: src/%.c $(LIBFT) | obj
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE_PATH)


$(LIBFT):
	make -C ./libft/

clean:
	rm -rf obj
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all

.PHONY : all, re, clean, flcean
