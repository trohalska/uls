NAME =		uls

CFLAGS =	-std=c11 -Wall -Wextra -Werror -Wpedantic

# --------- Header files ----------------
INC =		uls.h
INCI =		$(addprefix inc/, 			\
			uls.h)

# --------- Source files ----------------

SRC = 		*.c

SRCS =  	$(addprefix src/,			\
			*.c )

# --------- Object files ----------------
OBJ = 		*.o


# ---------------------------------------
all: install clean

install:
	
	@ cp $(SRCS) $(INCI) .
	@ clang $(CFLAGS) -c $(SRC)
	@ clang $(CFLAGS) $(OBJ) libmx/libmx.a -o $(NAME)
	@ mkdir ./obj
	@ mv $(OBJ) ./obj

uninstall: clean
	
	@ rm -rf $(NAME)

clean: 
	
	@ rm -rf $(INC) $(SRC) ./obj
	
reinstall: uninstall install
