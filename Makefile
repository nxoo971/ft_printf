SRCS	= ft_printf.c flags.c flags2.c sflags.c xflags.c

BONUS	= 

NAME	= libftprintf.a

INC		= -I ./includes/

FLAGS	= -Wall -Werror -Wextra

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS = ${BONUS:.c=.o}

${NAME} : ${OBJS}
		make -C ./libft/ fclean
		make -C ./libft/
		cp libft/libft.a $(NAME)
		gcc $(FLAGS) -c $(INC) $(SRCS)
		ar rcs ${NAME} ${OBJS}

all : ${NAME}

bonus : $(OBJS) $(OBJS_BONUS)
		ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean :
		rm -f ${OBJS} ${OBJS_BONUS}

fclean : clean
		rm -f ${NAME}

re : fclean all
