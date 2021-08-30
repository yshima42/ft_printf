CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
NAME			= libftprintf.a
SRCS_PATH		= srcs/
LIBFT_PATH		= libft/
LIBFT_LIB		= libft.a
HEADERS_FOLDER	= includes/
SRCS_FILES    	= 	./srcs/ft_printf.c \
					./srcs/ft_output_char.c \
					./srcs/ft_output_hexa_int.c \
					./srcs/ft_output_int.c \
					./srcs/ft_output_pointer.c \
					./srcs/ft_output_string.c \
					./srcs/ft_output_unsigned_int.c
SRCS_OBJS		= ${SRCS_FILES:.c=.o}
AR				= ar crs
LIBFT_OBJS		= ${LIBFT_PATH}*.o
LIBFTMAKE		= $(MAKE) -C ${LIBFT_PATH}

all:			${NAME}

${NAME}:		${SRCS_OBJS} lib
				${AR} ${NAME} ${SRCS_OBJS} ${LIBFT_OBJS}

lib:
				${LIBFTMAKE}

clean:
				make -C ${LIBFT_PATH} clean
				${RM} ${SRCS_OBJS}

fclean:			clean
				${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:				fclean all

.PHONY:			all clean fclean re