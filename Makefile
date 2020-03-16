##
## EPITECH PROJECT, 2019
## EPITECH
## File description:
## navy
##

SRC =	lib/my/my_putchar.c				\
		lib/my/my_put_nbr.c				\
		lib/my/my_putstr.c				\
		lib/my/my_revstr.c				\
		lib/my/my_showmem.c				\
		lib/my/my_showstr.c				\
		lib/my/my_sort_int_array.c		\
		lib/my/my_strcapitalize.c		\
		lib/my/my_strcat.c				\
		lib/my/my_strcmp.c				\
		lib/my/my_strcpy.c				\
		lib/my/my_strlen.c				\
		lib/my/my_strlowcase.c			\
		lib/my/my_getnbr.c				\
		lib/my/my_strncat.c				\
		lib/my/my_strncmp.c				\
		lib/my/my_strncpy.c				\
		lib/my/my_str_to_word_array.c	\
		lib/my/my_strstr.c				\
		lib/my/my_itoa.c				\
		lib/my/get_next_line.c			\
		lib/my/my_str_dup.c				\
		src/main.c						\
		src/check_file.c				\
		src/settings.c                  \
		src/alphabetic_order.c			\
		src/error_gestion.c				\

OBJ =   $(SRC:.c=.o)

CFLAGS  += -g -Iinclude

NAME    =   tetris

RED =   \033[1m\033[38;2;164;0;0m

GREEN   =   \033[1m\033[38;2;100;245;0m

WHITE = \033[0m

BLUE = \033[1m\033[38;2;0;0;170m

$(NAME):    $(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses -Wall -W -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast -Wmissing-prototypes -Wstrict-prototypes -Wmissing-declarations -Winline -Wundef -Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter -Wfloat-equal -std=c99 -pedantic
		rm -f *.o

all:    $(NAME)
		@printf " ----------------------------------\n"
		@printf " |$(BLUE)Compilation du Makefile réussie.$(WHITE)|\n"
		@printf " |$(BLUE)-> BINAIRE:$(WHITE) ./%s            |\n" $(NAME)
		@printf " ----------------------------------\n"

debug: CFLAGS += -g -DDEBUG
debug: fclean
debug: all

clean:
		@rm -f $(OBJ)
		@printf "Les .o ont bien été supprimés.\n"

fclean: clean
		@rm -f $(NAME)
		@printf "La/Le %s a été supprimé.\n" $(NAME)

re:     fclean all

%.o:    %.c
		@echo -en "${BLUE}$@${WHITE} "; $(CC) -c -o $@ $< ${CFLAGS}; if [ $$? -eq 0 ]; then echo -e "${GREEN}[OK]${WHITE}"; else echo -e "${RED}[ERROR]${WHITE}"; fi; echo;
