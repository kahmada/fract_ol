# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 15:24:59 by kahmada           #+#    #+#              #
#    Updated: 2024/05/19 15:25:02 by kahmada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = fractol
HEADER = fractol.h
CC     = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
RM     = rm -f

SRC = fractol.c\
      utils.c\
	  ft_mandelbrot.c\
	  libft_func.c\
	  ft_julia.c\
	  events.c\
	  ft_atof.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)