#include "uls.h"

static int round_num(double g);         // округление числа
static void add_pref(char *size, int pow);      // указиваем формат числа M, G, T, P
static int get_pow(off_t st_size);        // получаем степень 2
static void write_number(char *size, off_t st_size);     // запись числа в позицию 0 - 2

char *mx_human_read_size(off_t st_size) {
    char *size = mx_strnew(4);
    off_t num = st_size;
    double g;
    int pow = 0;

    if (num == 0) {
      size = mx_strcpy(size, "  0B");
    }
    else if (st_size < 1000) {
      write_number(size, num);
        size[3] = 'B';
    }
    else if (st_size >= 1000) {
        pow = get_pow(st_size);
        g = st_size / mx_pow(2, pow);

        if (g  >= 10) {               // усли целая часть >= 10
            num = round_num(g);
                if (num < 999)
                    write_number(size, num);
            else {
                num = round_num(g * 10);
                pow += 10;
                size[0] = num / 10 + 48;
                size[1] = '.';
                size[2] = num % 10 + 48;
            }
        }
        else {                          // усли целая часть < 10
            num = round_num(g * 10);
            size[0] = num / 10 + 48;
            size[1] = '.';
            size[2] = num % 10 + 48;
        }
     add_pref(size, pow);
    }
   return size;
}

static void write_number(char *size, off_t st_size) {
    int c;
    off_t num = st_size;

    for (c = 3; c > 0; c-- ) {
        if (num > 0) {
            size [c - 1] = num % 10  + 48;
            num /= 10;
        }
        else
            size[c - 1] = ' ';
    }
}

static int get_pow(off_t st_size) {
    off_t num = st_size;
    int pow = 0;

    while (num >= 1000) {
        num /= 1024;
        pow += 10;
    }
    return pow;
}

static int round_num(double g) {
    off_t res;

    if (((off_t)(g * 10) % 10) >= 5)
      res = (off_t)(g * 10) /10 + 1;
    else
      res = (off_t)(g * 10) /10;
    return res;
}


static void add_pref(char *size, int pow) {
     switch (pow) {
         case 10:
             size[3] = 'K';
             break;
         case 20:
             size[3] = 'M';
             break;
         case 30:
             size[3] = 'G';
             break;
         case 40:
             size[3] = 'T';
             break;
         case 50:
             size[3] = 'P';
             break;
    }
}
