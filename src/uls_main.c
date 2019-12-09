#include "uls.h"

int main(int argc, char **argv) {
	
	//mx_check(argc, argv);

/*  якщо аргументів немає -/- РЕАЛІЗОВАНО БЕЗ КОЛЬОРОВОЇ РОЗКРАСКИ -/-
*/	
	if (argc < 2) {
		DIR *entry;
		entry = opendir(".");
		mx_if_no_argv(entry); // print
	}
	
/*  якщо аргументи є 
*/
	if (argc >= 2) {
		t_command *comm = mx_create_command(argc, argv);
		mx_print_all(argc, argv, comm);
	}

/*  кінець */
	// system("leaks -q uls");
	return 0;	
}
