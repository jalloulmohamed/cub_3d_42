CC = gcc

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c\
	  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
	  ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
	  ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_putendl_fd.c

bonus_src = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c


OBJ = $(SRC:.c=.o)

bonus_obj = $(bonus_src:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) libft.h
	ar rcs $@ $^   

bonus : $(bonus_obj) libft.h 
	ar rcs $(NAME) $^ 

%.o : %.c libft.h
	$(CC) $(FLAGS)  -c $< -o $@ 

clean :
	rm -rf $(OBJ) $(bonus_obj)
fclean : clean
	rm -rf $(NAME)

re : fclean all
