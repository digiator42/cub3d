# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 20:19:54 by mfirdous          #+#    #+#              #
#    Updated: 2023/05/06 15:33:49 by ahassan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

SRCS	=	srcs/main.c \
			srcs/get_data.c \
			srcs/parse.c \
			srcs/get_upper_map.c \
			srcs/get_colors.c \
			srcs/get_map.c \
			srcs/valid_map.c \
			srcs/parse_utils.c \
			srcs/extra_parse_utils.c \
			srcs/key_handler.c \
			srcs/draw_minimap.c \
			srcs/draw_rays.c \
			srcs/draw_utils.c
			

OBJS	=	${SRCS:.c=.o}

HEADER	=	include

LIBFT	=	libft/libft.a

MLX		=	libmlx.dylib

CC		=	gcc -Wall -Werror -Wextra -fsanitize=address

MLX_DIR		=	mlx

CFLAGS	=	-I ${HEADER} -I ${MLX_DIR} -Ofast

MLX_FLAGS	= -L. -lmlx -framework OpenGL -framework AppKit

${NAME}:	${LIBFT} ${MLX} ${OBJS}
			${CC} ${CFLAGS} ${MLX_FLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${LIBFT}:
			${MAKE} -C libft

${MLX}:
			${MAKE} -C mlx
			mv mlx/libmlx.dylib .

all:		${NAME}

clean:
			rm -f ${OBJS}
			rm -f ${MLX}
			${MAKE} -C libft clean
			${MAKE} -C ${MLX_DIR} clean

fclean:		clean
			rm -f ${NAME}
			${MAKE} -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re