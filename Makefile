SRCS	= ft_printf.c init.c spec_info.c explain_specification.c exec_integer.c exec_unsigned.c exec_string.c calc_len.c operations.c puts_essentials.c puts.c

BONUS	= ft_printf.c init.c spec_info.c explain_specification.c exec_integer.c exec_unsigned.c exec_string.c calc_len.c operations.c puts_essentials.c puts.c

NAME	= libftprintf.a

INC		= -I ./

FLAGS	= -Wall -Werror -Wextra

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS = ${BONUS:.c=.o}

${NAME} : ${OBJS}
		make -C ./libft/ fclean
		make -C ./libft/
		cp libft/libft.a $(NAME)
		gcc -c $(INC) $(SRCS)
		ar rcs ${NAME} ${OBJS}
		

all : ${NAME}
	ar rcs ${NAME} ${OBJS}

bonus : $(OBJS) $(OBJS_BONUS)
		make -C ./libft/ fclean
		make -C ./libft/
		cp libft/libft.a $(NAME)
		gcc -c $(INC) $(SRCS)
		ar rcs ${NAME} ${OBJS} $(OBJS_BONUS)

clean :
		rm -f ${OBJS} ${OBJS_BONUS}

fclean : clean
		rm -f ${NAME}

re : fclean all
