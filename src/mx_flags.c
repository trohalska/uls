#include "uls.h"

static void print_flags(char flag, t_cmd *c);
static void format_flags(char flag, t_cmd *c);
static void sort_and_time_flags(char flag, t_cmd *c);
static void filter_flags(char flag, t_cmd *c);

void mx_flags(char flag, t_cmd *c) {

	print_flags(flag, c);
	sort_and_time_flags(flag, c);
	format_flags(flag, c);
	filter_flags(flag, c);
}

static void print_flags(char flag, t_cmd *c) {
	switch (flag) {
		case 'l':
			c->print_func = long_format;
			break;
		case 'C':
			if (c->print_func != m_format)
				c->print_func = std_format;
			break;
		case '1':
			c->print_func = col_format;
			break;
		case 'm':
			c->print_func = m_format;
			break;
		case 'R':
			c->print_recursion = true;
			break;
	}
}

static void sort_and_time_flags(char flag, t_cmd *c) {
	switch (flag) {
		case 'r':
			c->print_reverse = true;
			break;
		case 'S':
			c->sort_type = sort_size;
			break;
		case 't':
			if (c->sort_type != sort_size)
				c->sort_type = sort_time;
			break;
		case 'c':
			c->time_type = time_ctime;
			break;
		case 'u':
			c->time_type = time_atime;
			break;
	}
}

static void format_flags(char flag, t_cmd *c) {
	switch (flag) {
		case 'a':
			c->print_hidden = true;
			break;
		case 'A':
			c->print_dots_folder = true;
			break;
		case 'f':
			c->print_f = true;
			break;
	}
}

static void filter_flags(char flag, t_cmd *c) {
	switch (flag) {
		case 'h':
			c->format_h = true;
			break;
		case 'g':
			c->print_owner = false;
			break;
		case 'o':
			c->print_group = false;
			break;
		case 'n':
			c->print_owner_group_num = true;
			break;
	}
}

// B, //  -B  -- print octal escapes for control characters
// F, //  -F  -- append file type indicators
// H, //  -H  -- follow symlinks on the command line
// L, //  -L  -- list referenced file for sym link
// P, //  -P  -- do not follow symlinks
// b, //  -b  -- as -B, but use C escape codes whenever possible
// d, //  -d  -- list directory entries instead of contents
// i, //  -i  -- print file inode numbers
// k, //  -k  -- print sizes of 1k
// p, //  -p  -- append file type indicators for directory
// q, //  -q  -- hide control chars
// s, //  -s  -- display size of each file in blocks
// w, //  -w  -- print raw characters
// x, //  -x  -- sort horizontally
