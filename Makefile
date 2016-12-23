# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vportell <vportell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/18 01:47:06 by vportell          #+#    #+#              #
#    Updated: 2016/12/22 20:18:53 by vportell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft

SRCS =	ft_printf.c \
		parse.c \
		format.c \
		print_1.c \
		print_2.c \
		print_segments.c \
		brain.c \

		# alloc_wrap.c

OBJS = $(SRCS:.c=.o)

LIB_FILES =	ft_memset \
			ft_bzero \
			ft_memcpy \
			ft_memccpy \
			ft_memmove \
			ft_memchr \
			ft_memcmp \
			ft_strlen \
			ft_strdup \
			ft_strcpy \
			ft_strncpy \
			ft_strcat \
			ft_strncat \
			ft_strlcat \
			ft_strchr \
			ft_strrchr \
			ft_strstr \
			ft_strnstr \
			ft_strcmp \
			ft_strncmp \
			ft_atoi \
			ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isprint \
			ft_toupper \
			ft_tolower \
			ft_memalloc \
			ft_memdel \
			ft_strnew \
			ft_strdel \
			ft_strclr \
			ft_striter \
			ft_striteri \
			ft_strmap \
			ft_strmapi \
			ft_strequ \
			ft_strnequ \
			ft_strsub \
			ft_strjoin \
			ft_strtrim \
			ft_strsplit \
			ft_itoa \
			ft_putchar \
			ft_putstr \
			ft_putendl \
			ft_putnbr \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_lstnew \
			ft_lstdelone \
			ft_lstdel \
			ft_lstadd \
			ft_lstiter \
			ft_lstmap \
			ft_is_lowercase \
			ft_is_uppercase \
			ft_is_space \
			ft_strrev \
			ft_word_count

LIB_SRCS := $(addprefix $(LIB_DIR)/, $(addsuffix .c, $(LIB_FILES)))
LIB_OBJS = $(LIB_SRCS:.c=.o)

RM = rm -f

.PHONY: fclean all

all: $(NAME)

$(NAME): $(OBJS) $(LIB_OBJS)
	ar rc $(NAME) $(LIB_OBJS) $(OBJS) 
	ranlib $(NAME)
	# gcc main.c libftprintf.a
	# ./a.out
	
clean:
	$(RM) $(OBJS)
	$(RM) $(LIB_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
