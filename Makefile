NAME = library/mlx/libmlx.a
CC = gcc
PRINT = library/ft_printf/libftprintf.a
LIBFT = library/libft/libft.a
MINILIB = library/mlx
F_PRINT = library/ft_printf
F_LIBFT = library/libft
LFLAGS = -framework OpenGL -framework AppKit
SO_LONG = so_long
SRCS = game/*.c

all: $(NAME) $(SO_LONG)

$(SO_LONG) : $(PRINT) $(LIBFT) $(SRCS)
	$(CC) $(LFLAGS) $(FLAGS) $(NAME) $(PRINT) $(LIBFT) $(SRCS) -o $(SO_LONG)
	@echo "FINISH"

$(NAME): $(MINILIB)
	make -s -C $(MINILIB)
	@echo "\nMLX Done!!"

$(PRINT): $(F_PRINT)
	make -s -C $(F_PRINT)
	@echo "\nPrintf Done!!"

$(LIBFT): $(F_LIBFT)
	make -s -C $(F_LIBFT)
	@echo "\nLibft Done!!"

clean:
	make clean -C $(F_LIBFT)
	make clean -C $(F_PRINT)
	make clean -C $(MINILIB)

fclean: clean
	make fclean -C $(F_LIBFT)
	make fclean -C $(F_PRINT)
	rm -rf so_long so_long_bonus *.a

re: fclean all

.PHONY: clean re fclean all