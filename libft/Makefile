# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncella <ncella@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 10:21:38 by ncella            #+#    #+#              #
#    Updated: 2017/12/07 16:32:12 by ncella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SOURCES = ft_memset.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_bzero.c \
		ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strstr.c ft_strncmp.c \
		ft_atoi.c ft_strcmp.c ft_toupper.c ft_tolower.c ft_strchr.c  \
		ft_strrchr.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
		ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strnstr.c \
		ft_itoa.c ft_strsplit.c ft_strlcat.c ft_lstnew.c ft_lstdelone.c \
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_counter_atoi.c \
		ft_len_int.c ft_while_itoa.c ft_nb_words.c ft_length_words.c \
		ft_cpy.c ft_strsplit_1.c ft_split_whitespaces.c

OBJET = $(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(OBJET)
	@ar rc $(NAME) $(OBJET)
	@ranlib $(NAME)

%.o:%.c
	@gcc -g $(CFLAGS) -c -o $@ $< $(INC)

clean:
	@/bin/rm -f $(OBJET)

fclean: clean
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
