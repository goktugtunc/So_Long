NAME = so_long

sources = extrafunctions.c so_long_main.c controller.c get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c mapcontrol.c controller2.c

objs = extrafunctions.o so_long_main.o controller.o get_next_line/get_next_line_bonus.o get_next_line/get_next_line_utils_bonus.o mapcontrol.o controller2.o

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(sources) -o so_long

clean:
	rm -rf $(objs)

fclean: clean
	rm -rf $(NAME)

re: fclean all