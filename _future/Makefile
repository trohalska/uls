NAME =		uls

CFLAGS =	-std=c11 -Wall -Wextra -Werror -Wpedantic

# --------- Header files ----------------
INC =		uls.h
INCI =		$(addprefix inc/, 			\
			uls.h)

# --------- Source files ----------------

SRC = 		mx_check.c mx_if_no_argv.c mx_standart_print.c mx_push_back_uls.c uls_main.c

SRCS =  	$(addprefix src/,			\
			mx_check.c mx_if_no_argv.c mx_standart_print.c mx_push_back_uls.c uls_main.c )

# --------- Object files ----------------
OBJ = 		mx_check.o mx_if_no_argv.o mx_standart_print.o mx_push_back_uls.o uls_main.o


# ---------------------------------------
all: install clean

install:
	@ make install -sC libmx/
	@ cp $(SRCS) $(INCI) .
	@ clang $(CFLAGS) -c $(SRC)
	@ clang $(CFLAGS) $(OBJ) libmx/libmx.a -o $(NAME)
	@ mkdir ./obj
	@ mv $(OBJ) ./obj

uninstall: clean
	@ make uninstall -sC libmx/
	@ rm -rf $(NAME)

clean: 
	@ make clean -sC libmx/
	@ rm -rf $(INC) $(SRC) ./obj
	
reinstall: uninstall install
