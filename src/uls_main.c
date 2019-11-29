#include "uls.h"

int main(int argc, char **argv) {
	
/*  засунути в фукцію перевірки на помилки */

	//mx_check(argc, argv);
	
	//DIR *dir;
	//dir = opendir(argv[1]);
	//struct dirent *entry1;

	// if (!dir) {
	// 	char *str =  mx_strjoin("uls:",argv[2]);
	// 	//mx_printstr(str);
	// 	perror(str);
	// 	exit(1);
	// }

	// if (!dir) {
	// 	mx_printerr("uls: ");
	// 	mx_printerr("dir");
	// 	mx_printerr(": ");
	// 	mx_printerr(strerror(errno));
	// 	mx_printerr("\n");
	// 	exit(1);
	// }	

	if (argv) {}

/*  якщо аргументів немає -/- РЕАЛІЗОВАНО БЕЗ КОЛЬОРОВОЇ РОЗКРАСКИ -/-
*/	
	if (argc < 2)
		mx_if_no_argv();
	else if (mx_strcmp(argv[1], "-l") != 0)
        for_each_argv(argc, argv);
	// else if (mx_strcmp(argv[1], "-l") == 0) {
	// 	DIR *d = opendir(".");
	// 	get_contents(d);
	// 	closedir(d);
	// }
/*  якщо аргументи є
*/
	if (argc >= 2) {
		// if (argv[1][0] == '-' && argv[1][1] == 'l' )
		// 	mx_printstr("good \n");
	}

/*  кінець
*/
	// system("leaks -q uls");
	return 0;	
}
