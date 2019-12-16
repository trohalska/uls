#include "uls.h"

static void initialize(t_maxlens_for_print *len);
static void compare_str(int *max, char *str);
static void compare_numb(int *max, int numb);

t_maxlens_for_print *mx_get_lens_for_print(t_list *lf) {
	t_maxlens_for_print *len;

	if(!lf)
		return NULL;
	len = malloc(sizeof(t_maxlens_for_print));
	initialize(len);
	for (t_list *q = lf; q != NULL; q = q->next) {
		t_file *tmp = q->data;
		compare_numb(&len->l_links, tmp->links) ;
		compare_str(&len->l_owner, tmp->owner);
		compare_str(&len->l_group, tmp->group);
		compare_numb(&len->l_size, tmp->size);
	}
	return len;
}

static void initialize(t_maxlens_for_print *len) {
	len->l_links = 0;
	len->l_owner = 0;
	len->l_group = 0;
	len->l_size = 0;
}

static void compare_str(int *max, char *str) {
	int c = mx_strlen(str);

	if (*max < c) {
		*max = c;
	}
}

static void compare_numb(int *max, int numb) {
	char *tmp = mx_itoa(numb);
	int c = mx_strlen(tmp);

	if (*max < c) {
		*max = c;
	}
	free(tmp);
}
