#Nom du programme
NAME	= push_swap

# Repertoires sous-parties
DIR_LIBFT = libft

# Obj des sous parties
OBJ_LIBFT = $(DIR_LIBFT)/libft.a

# Sources et obj main Makefile
SRCS	= main.c src/push_swap/utils.c src/push_swap/sorting.c src/push_swap/sorting_utils.c src/push_swap/target_utils.c \
		src/push_swap/move_utils.c src/push_swap/ope_utils.c src/push_swap/input_check.c src/push_swap/error.c \
		src/push_swap/init_stack.c src/cmd/cmd_push.c src/cmd/cmd_rota.c src/cmd/cmd_rrota.c src/cmd/cmd_swap.c
OBJS	= ${SRCS:.c=.o}

# Compilation
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -Iinc
LIB		= ranlib

# Regle principale
all:		${OBJ_LIBFT} ${NAME}

.c.o:
			@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${OBJ_LIBFT}
			@${CC} ${FLAGS} ${OBJS} ${OBJ_LIBFT} -o ${NAME}
			@echo "\n✅ Compilation terminée pour : ${NAME} !\n"

${OBJ_LIBFT}:
			@${MAKE} -C ${DIR_LIBFT} --no-print-directory
			@echo "\n✅ Compilation terminée pour libft !"

clean:
			@rm -f ${OBJS}
			@${MAKE} -C ${DIR_LIBFT} clean --no-print-directory
			@echo "✅ (clean) Suppression des fichiers .o !"

fclean:		clean
			@rm -f ${NAME}
			@${MAKE} -C ${DIR_LIBFT} fclean --no-print-directory
			@echo "✅ (fclean) Suppression de l'Archive !"

re:			fclean all

.PHONY:		all clean fclean re