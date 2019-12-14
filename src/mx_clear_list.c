#include "uls.h"

void mx_clear_list(t_list **list) {
	if (*list == NULL || list == NULL)
		return;

	t_list *p = *list; // запомнить начало
	if (!p) return;
	while (p != NULL) { // найти предпоследний
		t_list *tmp = p->next;
		free(p); // удалить последний
		p = tmp; // указатель на NULL
	}
	*list = NULL;
}
