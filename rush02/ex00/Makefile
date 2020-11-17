SRCS	= main.c str.c num_type_conversion.c read_string.c read_file.c error_checks.c three_digits_converter.c converter.c 
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	=  rush-02

.c.o :
	${CC} ${CFLAGS} -c ${SRCS}

all :	${OBJS}
		${CC} -o ${NAME} ${OBJS}

${NAME} :	all

clean :
		rm -f ${OBJS}

fclean : clean
		 	rm -f ${NAME}

re :	 fclean all

.PHONY: fclean clean re all
