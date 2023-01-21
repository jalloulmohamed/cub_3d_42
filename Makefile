CC = cc
NAME = cub3D
FLAGS = -Wall -Wextra -Werror
INCLUDE = -lmlx -framework OpenGL -framework AppKit
INC = cub3d.h\
	libft/libft.h

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC = get_next_line/get_next_line_utils.c\
	  get_next_line/get_next_line.c\
	  cub3d.c\
	  parsing/map.c \
	  window.c\
	  utils/derection.c\
	  utils/position_player.c\
	  utils/event.c\
	  utils/view.c\
	  utils/floor.c\
	  utils/len_map.c\
	  utils/rindring.c\
	  utils/intersection.c\
	  utils/intersection/up_right.c\
	  utils/intersection/up_left.c\
	  utils/intersection/down_left.c\
	  utils/intersection/down_right.c\
	  parsing/map2.c


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(INC) $(OBJ) $(LIBFT_LIB)
	$(CC) $(OBJ)  $(LIBFT_LIB) $(INCLUDE) -o $(NAME)  
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
	
%.o : %.c $(INC)
	$(CC)  $(FLAGS) -c $< -o $@ 

clean :
	$(MAKE)  clean -C $(LIBFT_DIR)
	rm -rf $(OBJ)
fclean : clean
	$(MAKE)  fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re : fclean all