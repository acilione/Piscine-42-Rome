SRCS	= main.c nummanagement.c operations.c str.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	=  do-op

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