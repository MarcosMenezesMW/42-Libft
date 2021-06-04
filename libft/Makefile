
FLAGS =	-Wall -Wextra -Werror

INC_DIR = src

LIB_DIR = lib

CC =	gcc

NAME =	libft.a

SRC_FILES =	ft_atoi.c \
			ft_isascii.c \
			ft_memcmp.c \
			ft_strchr.c \
			ft_strlen.c \
			ft_substr.c \
			ft_bzero.c \
    		ft_isdigit.c \
	  		ft_memcpy.c \
	     	ft_strdup.c \
			ft_strncmp.c \
	 		ft_tolower.c \
			ft_calloc.c \
			ft_isprint.c \
			ft_memmove.c \
			ft_strjoin.c \
			ft_strnstr.c \
			ft_toupper.c \
			ft_isalnum.c \
			ft_memccpy.c \
			ft_memset.c \
			ft_strlcat.c \
			ft_strrchr.c \
			ft_isalpha.c \
			ft_memchr.c \
			ft_strlcpy.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c 

SRCS = $(addprefix $(INC_DIR)/,$(SRC_FILES))

OBJS = $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created"

%.o: %.c
	@gcc $(FLAGS) -I $(LIB_DIR) -c $< -o $@
	@echo "$@ created from $<"

clean:
	@rm -f $(OBJS)
	@echo "OBJECTS deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY = all clean fclean re