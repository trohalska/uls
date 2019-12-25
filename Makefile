NAME = uls

INC = uls.h

SRC = mx_check.c \
	mx_clear_filesattr_list.c \
	mx_create_command.c \
	mx_flags.c \
	mx_get_arg_d.c \
	mx_get_arg_f.c \
	mx_get_files_list_dir.c \
	mx_get_filesattr.c \
	mx_get_lens_for_print.c \
	mx_get_permissions.c \
	mx_hr_size.c \
	mx_hr_get_pow.c \
	mx_hr_write_number.c \
	mx_isdir.c \
	mx_ishiden.c \
	mx_islink.c \
	mx_prepare_list_and_print.c \
	mx_print_acl.c \
	mx_print_col_format.c \
	mx_print_color_name.c \
	mx_print_linkname.c \
	mx_print_long_format.c \
	mx_print_m_format.c \
	mx_print_nlink.c \
	mx_print_size.c \
	mx_print_std_format.c \
	mx_print_tab.c \
	mx_print_time.c \
	mx_print_total.c \
	mx_sort_uls_list.c \
	mx_strcmp_atime.c \
	mx_strcmp_ctime.c \
	mx_strcmp_f_d_bool.c \
	mx_strcmp_mtime.c \
	mx_strcmp_names.c \
	mx_strcmp_size.c \
	uls_main.c


OBJ = mx_check.o \
	mx_clear_filesattr_list.o \
	mx_create_command.o \
	mx_flags.o \
	mx_get_arg_d.o \
	mx_get_arg_f.o \
	mx_get_files_list_dir.o \
	mx_get_filesattr.o \
	mx_get_lens_for_print.o \
	mx_get_permissions.o \
	mx_hr_size.o \
	mx_hr_get_pow.o \
	mx_hr_write_number.o \
	mx_isdir.o \
	mx_ishiden.o \
	mx_islink.o \
	mx_prepare_list_and_print.o \
	mx_print_acl.o \
	mx_print_col_format.o \
	mx_print_linkname.o \
	mx_print_long_format.o \
	mx_print_m_format.o \
	mx_print_color_name.o \
	mx_print_nlink.o \
	mx_print_size.o \
	mx_print_std_format.o \
	mx_print_tab.o \
	mx_print_time.o \
	mx_print_total.o \
	mx_sort_uls_list.o \
	mx_strcmp_atime.o \
	mx_strcmp_ctime.o \
	mx_strcmp_f_d_bool.o \
	mx_strcmp_mtime.o \
	mx_strcmp_names.o \
	mx_strcmp_size.o \
	uls_main.o

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make install -sC libmx
	@cp $(addprefix src/, $(SRC)) .
	@cp $(addprefix inc/, $(INC)) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) ./obj

uninstall: clean
	@make uninstall -sC libmx
	@rm -rf $(NAME)

clean:
	@make clean -sC libmx
	@rm -rf $(INC) $(SRC) ./obj

reinstall: uninstall install
