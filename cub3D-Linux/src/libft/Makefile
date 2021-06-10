# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akowalsk <akowalsk@student.42.f4>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 13:49:19 by akowalsk          #+#    #+#              #
#    Updated: 2021/01/13 15:47:29 by akowalsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_strlen.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_calloc.c\
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
		ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_strchr.c ft_strdup.c\
		ft_strrchr.c ft_strnstr.c ft_strlcat.c ft_strlcpy.c ft_substr.c\
		ft_strjoin.c ft_strtrim.c ft_strmapi.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_strrev.c ft_nbrlen.c ft_hextoa.c ft_hextoa_p.c\
		ft_ltoa_base.c ft_putchar.c ft_putnchar.c get_next_line/get_next_line.c\
		ft_strnew.c

OBJECTS = ft_strlen.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_calloc.o\
		ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o\
		ft_tolower.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o\
		ft_memccpy.o ft_memchr.o ft_memcmp.o ft_strchr.o ft_strdup.o\
		ft_strrchr.o ft_strnstr.o ft_strlcat.o ft_strlcpy.o ft_substr.o\
		ft_strjoin.o ft_strtrim.o ft_strmapi.o\
		ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o\
		ft_strrev.o ft_nbrlen.o ft_hextoa.o ft_hextoa_p.o\
		ft_ltoa_base.o ft_putchar.o ft_putnchar.o get_next_line.o\
		ft_strnew.o

all: $(NAME)

$(NAME):
	# @gcc -Wall -Wextra -Werror -c -I. $(SRCS)
	@gcc -c -I. $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

