##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compiles my program
##

CC 	=	gcc

SRC_MAIN	=	src/main.c

SRC	=	src/check.c \
		src/cd.c \
		src/cd_bis.c \
		src/cm_prompt.c \
		src/env.c \
		src/get.c \
		src/init.c \
		src/process.c \
		src/setenv.c \
		src/signal.c \
		src/unsetenv.c \
		src/error.c

SRC_CRIT =

LIB	=	lib/list_add.c	\
		lib/list_get.c	\
		\
		lib/char/cm_putchar.c	\
		\
		lib/int/cm_getnbr.c	\
		lib/int/cm_putnbr.c	\
		lib/int/cm_swap.c	\
		\
		lib/str/cm_putstr.c				\
		lib/str/cm_revstr.c				\
		lib/str/cm_str_to_word_array.c	\
		lib/str/cm_strcat.c				\
		lib/str/cm_strcmp.c				\
		lib/str/cm_strcpy.c				\
		lib/str/cm_strdup.c				\
		lib/str/cm_stris.c				\
		lib/str/cm_strlen.c				\
		lib/str/cm_strtok.c				\
		lib/str/cm_strupcase.c			\
		\
		lib/tab/cm_freetab.c	\
		lib/tab/cm_puttab.c		\
		\
		lib/cm_isneg.c

INCLUDES        =       -I includes/


## COMPILATION_PROGRAM

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o) $(SRC_MAIN:.c=.o)

NAME	= 	mysh

CFLAGS	=	$(INCLUDES) -Wall -Wextra -g


## TESTS_CRITERION

OBJ_CRIT	=	$(SRC:.c=.o) $(LIB:.c=.o) $(SRC_CRIT:.c=.o)

NAME_CRIT	=	unit_tests

CRIT_F	=	$(INCLUDES) --coverage -lcriterion


## COMMANDE_CONSOLE

all:	$(NAME)

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
		@echo -e "\033[1;32mCompilation done\033[0m"

%.o:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

unit_tests: $(OBJ_CRIT)
	@$(CC) -o $(NAME_CRIT) $(OBJ_CRIT) $(CRIT_F)
	@echo -e "\033[1;32mCompilation unit_tests done\033[0m"
	@./$(NAME_CRIT)
	@gcovr

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_CRIT)
	@find . \( -name "*~" -o -name "#*" -o -name "*#" \) -delete
	@echo -e "\033[1;31mClean done\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_CRIT)
	@rm -f coding-style-reports.log
	@rm -f vgcore*
	@echo -e "\033[1;31mFclean done\033[0m"

re:	fclean all

.PHONY: 	all re clean fclean unit_tests
