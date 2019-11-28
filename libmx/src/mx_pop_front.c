#include "libmx.h"

void mx_pop_front(t_list **head) {
	if (!head || !(*head)) return;

	if ((*head)->next == NULL) { // if first is NULL-node
		free(*head);
		*head = NULL;
		return;
	}
	else {
		t_list *p = (*head)->next; // remember second node
		(*head)->data = NULL;
		free(*head); 
		*head = p;
	}
}
