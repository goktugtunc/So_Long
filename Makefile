NAME = so_long

sources = extrafunctions.c so_long_main.c controller.c get_next_line_bonus.c get_next_line_utils_bonus.c mapcontrol.c controller2.c mlxoperators.c mlxfunctions.c ifpressfunc.c subfunctions.c itoa.c extrafuncs2.c extracontrols.c

objs = extrafunctions.o so_long_main.o controller.o get_next_line_bonus.o get_next_line_utils_bonus.o mapcontrol.o controller2.o mlxoperators.o mlxfunctions.o ifpressfunc.o subfunctions.o itoa.o extrafuncs2.o extracontrols.o

MLX = ./minilibx

MINILIBX_PATH = ./minilibx
MINILIBXOBJ = ./minilibx/mlx_init_loop.o ./minilibx/mlx_int_str_to_wordtab.o ./minilibx/mlx_mouse.o ./minilibx/mlx_new_image.o ./minilibx/mlx_new_window.o ./minilibx/mlx_png.o ./minilibx/mlx_shaders.o ./minilibx/mlx_xpm.o

all: $(NAME)

$(NAME):
	make mlx
	gcc -Wall -Werror -Wextra -o so_long $(sources) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx

clean:
	rm -rf $(objs)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(MINILIBXOBJ)
	rm -rf ./minilibx/libmlx.a

re: fclean all

mlx:
	make -C $(MINILIBX_PATH) all