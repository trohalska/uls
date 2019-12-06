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
		char *flags = mx_get_flags(argc, argv); // "lRaAGh@eT1CrtucS"
		//char **files = mx_get_files(argc, argv);
		if(flags[0] == 'l')
			mx_print_all(argc, argv, flags);

		//printf("flags = %s\n", flags);
		

		// DIR *file = opendir(".");
		// struct dirent *tmp = readdir(file);
		// while ((tmp = readdir(file)) != NULL) {
		// 	if (tmp->d_name[0] != '.') {  // != 1 || mx_strcmp(entry1->d_name, "..") != 0)
		// 		mx_printstr(tmp->d_name);
		// 		mx_printchar('\t');
		// 		mx_printint(tmp->d_type);
		// 		mx_printchar('\n');
		// 	}	
		// }

		//if (flags == NULL && files != NULL) { // если только папки

			// for (int i = 0; files[i]; i ++) {
			// 	DIR *file = opendir(files[i]);
			// 	struct dirent *tmp = readdir(file);
			// 	if (tmp->d_type == 8) {
			// 		mx_printstr(files[i]);
			// 		mx_printstr(":\n");
			// 		mx_if_no_argv(opendir(files[i]));
			// 		if (files[i + 1] == NULL) break;
			// 		mx_printstr("\n");
			// 	}
			// 	closedir(file);
			// }
			// for (int i = 0; files[i] ; i++) {
			// 	DIR *file = opendir(files[i]);
			// 	struct dirent *tmp = readdir(file);
			// 	if (tmp->d_type == 4) {
			// 		mx_printstr(files[i]);
			// 		mx_printstr(":\n");
			// 		mx_if_no_argv(opendir(files[i]));
			// 		if (files[i + 1] == NULL) break;
			// 		mx_printstr("\n");
			// 	}
			// 	closedir(file);
			// }
		//}
		// if (flags != NULL) { // если есть флаги
		// 	t_list *test = mx_get_files_list(files);
		// 	mx_printstr("\n");
		// 	mx_print_long_format(test);
		// 	mx_printstr("\n");
		// }
	}

/*  кінець */
	// system("leaks -q uls");
	return 0;	
}
