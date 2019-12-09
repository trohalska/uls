#include "uls.h"

static t_command *initiailze_default();
static void print_and_filter_flags(char flag, t_command *c);
// static void format_flags(char flag, t_command *c);
// static void sort_and_time_flags(char flag, t_command *c);

t_command *mx_create_command(int argc, char **argv)
{
	t_command *c = initiailze_default();

	for (int i = 1; i < argc; i++)
		if (argv[i][0] == '-')
			for (int j = 1; j < mx_strlen(argv[i]); j++) {
				print_and_filter_flags(argv[i][j], c);
				// format_flags(argv[i][j], c);				
				// sort_and_time_flags(argv[i][j], c);
			}
		else break;
	return c;
}

static t_command *initiailze_default()
{
	t_command *c = (t_command *)malloc(sizeof(t_command));

	//c->print_func = mx_print_std_format;
	//c->print_func = mx_print_col_format; // ----------------- заменить на стандарт при готовности

	//c->sort_func = mx_sort_name; // ---------------- сделать
	c->print_func = col_format;
	c->time_type = time_mtime;
	// c->print_hidden = false;			// -a
	// c->print_reverse = false;			// -r
	c->print_owner = true;				// -g
	c->print_group = true;				// -o
	c->print_owner_group_num = false;	// -n
	// c->format_h = false;				// -h
	// c->format_at_symbol = false;		// -@
	// c->format_e = false;				// -e
	// c->format_T = false;				// -T

	return c;
}

static void print_and_filter_flags(char flag, t_command *c)
{
	switch (flag) {
		case 'l':
			c->print_func = long_format;
			break;
		// case 'C':	// Вывод в несколько колонок с сортировкой по колонкам.
		// 	c->print_func = mx_print_std_format;
		// 	break;
		case '1':
			c->print_func = col_format;
			break;
		case 'g':	// -l, id владельца не выводится.
			c->print_owner = false;
			break;
		case 'o':	// и -l, id группы не выводится.
			c->print_group = false;
			break;
		case 'n':	// -l, id владельца и группы выводятся в виде чисел.
			c->print_owner_group_num = true;
			break;
	}
}

// static void format_flags(char flag, t_command *c)
// {
// 	switch (flag) {
// 		case 'a':	// Вывести список всех файлов (в т.ч "." и "..")
// 			c->print_hidden = true;
// 			break;
// 		case 'r':	// reverse sort order
// 			c->print_reverse = true;
// 			break;
// 		case 'h':	// print sizes in human readable form
// 			c->format_h = true;
// 			break;
// 		case '@':	// display extended attribute keys and sizes in long (-l) output 
// 			c->format_at_symbol = true;
// 			break;
// 		// case 'e':	// ???
// 		// 	c->format_e = true;
// 		// 	break;
// 		case 'T':	// show complete time information
// 			c->format_T = true;
// 			break;
// 	}
// }

// static void sort_and_time_flags(char flag, t_command *c)
// {
// 	switch (flag) {
// 		// case 't':	// Имена файлов сортируются по времени, default - mtime
// 		// 	c->sort_func = mx_sort_time;
// 		// 	break;
// 		// case 'S':	// Имена файлов сортируются по времени
// 		// 	c->sort_func = mx_sort_size;
// 		// 	break;
// 		case 'c':	// create time
// 			c->time_type = time_ctime;
// 			break;
// 		case 'u':	// access time
// 			c->time_type = time_atime;
// 			break;
// 	}
// 		// sort_none = -1,	/* -U */
//     	// sort_extension,	/* -X */
//    		// sort_version,	/* -v */
// }

// -l	Вывод в длинном формате: перед именами файлов выдается режим доступа, 
// 		количество ссылок на файл, имена владельца и группы, 
// 		размер в байтах и время последней модификации (см. ниже).
// 		Если файл является специальным, то в поле размера выводится старший и младший номера устройства.
// -r	Изменить порядок сортировки на обратный алфавитный или, при наличии флага -t, 
//		сначала выводить более старые файлы.
// -t	Имена файлов сортируются по времени (сначала идут самые свежие файлы). 
// 		По умолчанию используется время последнего изменения. См. также флаги -u и -c.
// -u	Вместо времени последнего изменения использовать 
// 		время последнего доступа для сортировки (с флагом -t) или для вывода (с флагом -l).
// -c	Вместо времени последнего изменения использовать
// 		время последней модификации описателя файла (т.е. время создания файла, 
// 		изменения режима доступа к нему и т.п.) для сортировки (с флагом -t) или для вывода (с флагом -l).

// ------------------ Командой ls обрабатываются следующие флаги: ----------------------------

// -R	Рекурсивно обойти встретившиеся подкаталоги.
// -d	Если аргумент является каталогом, то выводить только его имя, а не содержимое. 
// 		Часто используется с флагом -l для получения сведений о состоянии каталога.
// -x	Вывод в несколько колонок с сортировкой по строкам.
// -m	Вывод в свободном формате, имена файлов разделяются запятыми.
// -p	Если файл является каталогом, то выдавать после его имени символ /.
// -F	Если файл является каталогом, то выдавать после его имени символ /; 
// 		если файл является выполняемым, то выдавать после его имени символ *.
// -b	Выдавать непечатаемые символы, входящие в имя файла, в восьмеричном виде (\ddd).
// -q	Выдавать непечатаемые символы, входящие в имя файла, в виде символа ?.
// -i	Выдавать в первой колонке номера описателей файлов.
// -s	Выдавать размер файлов в блоках (включая косвенные блоки).
// -f	Рассматривать каждый аргумент как каталог и выводить его содержимое. 
// 		Этот флаг отменяет флаги -l, -t, -s, -r и включает флаг -a. 
// 		Сортировка имен файлов не производится; имена выдаются в таком порядке, 
// 		в каком они перечислены в каталоге.


// typedef enum e_flag { // 33 flags:
// A, //  -A  -- list all except . and ..
// B, //  -B  -- print octal escapes for control characters
// F, //  -F  -- append file type indicators
// H, //  -H  -- follow symlinks on the command line
// L, //  -L  -- list referenced file for sym link
// P, //  -P  -- do not follow symlinks
// R, //  -R  -- list subdirectories recursively
// b, //  -b  -- as -B, but use C escape codes whenever possible
// d, //  -d  -- list directory entries instead of contents
// f, //  -f  -- output is not sorted
// i, //  -i  -- print file inode numbers
// k, //  -k  -- print sizes of 1k
// m, //  -m  -- comma separated
// p, //  -p  -- append file type indicators for directory
// q, //  -q  -- hide control chars
// s, //  -s  -- display size of each file in blocks
// w, //  -w  -- print raw characters
// x, //  -x  -- sort horizontally
// } t_flag;
