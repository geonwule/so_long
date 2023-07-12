HEAD = includes

MLX_HEAD = mlx.h mlx_int.h \

SRCS = srcs/get_next_line.c srcs/get_next_line_utils.c srcs/main.c\
	   srcs/map_init.c srcs/so_long_util.c srcs/so_long_util2.c srcs/valid_dfs.c\
	   srcs/map_error.c srcs/map_set.c srcs/keyboard_input.c\

BONUS_SRCS = srcs/get_next_line.c srcs/get_next_line_utils.c srcs/main.c\
	   srcs/map_init.c srcs/so_long_util.c srcs/so_long_util2.c srcs/valid_dfs.c\
	   srcs/map_error_bonus.c srcs/map_set_bonus.c srcs/keyboard_input_bonus.c\

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

MLXNAME = libmlx.a

MLXDIR = ./mlx

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
#-L${MLXDIR} -lmlx -I${MLXDIR} -lX11 -lXext

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

BONUS_NAME = bonus_so_long

#color
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all : ${NAME}

%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@ -I ${HEAD}

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} $^ ${MLXFLAGS} -o ${NAME}
	@echo "$(GREEN)so_long compiled!$(DEF_COLOR)"

bonus : ${BONUS_OBJS}
	@${CC} ${CFLAGS} $^ ${MLXFLAGS} -o ${BONUS_NAME}
	@echo "$(GREEN)so_long_bonus_compiled!$(DEF_COLOR)"

debug : ${OBJS}
	@cc -g3 -fsanitize=address -l${MLXNAME} ${MLXFLAGS} -o debug $^
	@echo "$(GREEN)debug compiled!$(DEF_COLOR)"

clean :
	@rm -f ${OBJS}
	@rm -f ${BONUS_OBJS}
	@echo "$(BLUE)so_long object files cleaned!$(DEF_COLOR)"

fclean : clean
	@rm -f ${NAME}
	@rm -f ${BONUS_NAME}
	@rm -f debug
	@echo "$(YELLOW)so_long library files cleaned!$(DEF_COLOR)"

re :
	${MAKE} fclean
	${MAKE} all
	@echo "$(MAGENTA)Cleaned and rebuilt everything for so_long!$(DEF_COLOR)"

.PHONY : all clean fclean re bonus debug
