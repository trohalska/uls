NAME =		uls

CFLAGS =	-std=c11 -Wall -Wextra -Werror -Wpedantic

# --------- Header files ----------------
INC =		libmx.h
INCI =		$(addprefix inc/, 			\
			libmx.h)

# --------- Source files ----------------

SRC = 		uls_main.c

SRCS =  	$(addprefix src/,			\
			uls_main.c )

# --------- Object files ----------------
OBJ = 		uls_main.o 


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
