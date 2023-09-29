NAME = so_long

NAME2 = so_long_bonus

sources = mandatory/extrafunctions.c mandatory/so_long_main.c mandatory/controller.c mandatory/get_next_line_bonus.c mandatory/get_next_line_utils_bonus.c mandatory/mapcontrol.c mandatory/controller2.c mandatory/mlxoperators.c mandatory/mlxfunctions.c mandatory/ifpressfunc.c mandatory/itoa.c mandatory/extracontrols.c

objs = extrafunctions.o so_long_main.o controller.o get_next_line_bonus.o get_next_line_utils_bonus.o mapcontrol.o controller2.o mlxoperators.o mlxfunctions.o ifpressfunc.o itoa.o extracontrols.o

sourcesbonus = bonus/extrafunctions_bonus.c bonus/so_long_main_bonus.c bonus/controller_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/mapcontrol_bonus.c bonus/controller2_bonus.c bonus/mlxoperators_bonus.c bonus/mlxfunctions_bonus.c bonus/ifpressfunc_bonus.c bonus/subfunctions_bonus.c bonus/itoa_bonus.c bonus/extrafuncs2_bonus.c bonus/extracontrols_bonus.c

objsbonus = extrafunctions_bonus.o so_long_main_bonus.o controller_bonus.o get_next_line_bonus.o get_next_line_utils_bonus.o mapcontrol_bonus.o controller2_bonus.o mlxoperators_bonus.o mlxfunctions_bonus.o ifpressfunc_bonus.o subfunctions_bonus.o itoa_bonus.o extrafuncs2_bonus.o extracontrols_bonus.o

MLX = ./minilibx

MINILIBX_PATH = ./minilibx
MINILIBXOBJ = ./minilibx/mlx_init_loop.o ./minilibx/mlx_int_str_to_wordtab.o ./minilibx/mlx_mouse.o ./minilibx/mlx_new_image.o ./minilibx/mlx_new_window.o ./minilibx/mlx_png.o ./minilibx/mlx_shaders.o ./minilibx/mlx_xpm.o

all: $(NAME)

$(NAME):
	make mlx
	gcc -Wall -Werror -Wextra -o so_long $(sources) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx

bonus: $(NAME2)

$(NAME2):
	make mlx
	gcc -Wall -Werror -Wextra -o so_long_bonus $(sourcesbonus) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx

clean:
	rm -rf $(objs)
	rm -rf $(objsbonus)
	rm -rf $(MINILIBXOBJ)
	rm -rf ./minilibx/libmlx.a

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME2)

re: fclean all

mlx:
	make -C $(MINILIBX_PATH) all