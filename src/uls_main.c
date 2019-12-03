#include "uls.h"

int main(int argc, char **argv) {
	DIR *entry;

	//mx_check(argc, argv);

/*  якщо аргументів немає -/- РЕАЛІЗОВАНО БЕЗ КОЛЬОРОВОЇ РОЗКРАСКИ -/-
*/	
	if (argc < 2) {
		entry = opendir(".");
		mx_if_no_argv(entry); // print
	}

/*  якщо аргументи є 
*/
	else if (argc >= 2) {
		char *flags = mx_get_flags(argc, argv);
		char **files = mx_get_files(argc, argv);

		printf("flags = %s\n", flags);
		if (files != NULL)
			for (int i = 0; files[i]; i++)
				printf("file[%d] = %s\n", i, files[i]);
		else printf("files = NULL");

		// if (flags == NULL && files != NULL) { // если только папки
		// 	for (int i = 0; files[i]; i ++) {
		// 		DIR *file = opendir(files[i]);
		// 		struct dirent *tmp = readdir(file);
		// 		if (tmp->d_type == 8) {
		// 			mx_printstr(files[i]);
		// 			mx_printstr(":\n");
		// 			mx_if_no_argv(opendir(files[i]));
		// 			if (files[i + 1] == NULL) break;
		// 			mx_printstr("\n");
		// 		}
		// 		closedir(file);
		// 	}
		// 	for (int i = 0; files[i] ; i++) {
		// 		DIR *file = opendir(files[i]);
		// 		struct dirent *tmp = readdir(file);
		// 		if (tmp->d_type == 4) {
		// 			mx_printstr(files[i]);
		// 			mx_printstr(":\n");
		// 			mx_if_no_argv(opendir(files[i]));
		// 			if (files[i + 1] == NULL) break;
		// 			mx_printstr("\n");
		// 		}
		// 		closedir(file);
		// 	}
		// }
		// else { // если только флаги или флаги и папки
			// if (files != NULL) {
			// 	t_file *test = mx_get_filesattr(files[0]);
			// 	print_long_format(test);
			// }
			// else {
			// 	//files[0] = ".";
			// }
		//}
	}

/*  кінець */
	// system("leaks -q uls");
	return 0;	
}
