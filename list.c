#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

    //tivial case - node belongs in the beginning
    if (new_element -> index <= head -> index) {
        new_element -> next = head;
        return new_element;
    }

    // find the node to insert after
    list_t* insert_after = NULL;
    list_t* node_ptr;
    for (node_ptr = head; node_ptr; node_ptr = node_ptr -> next) {
        if (node_ptr -> index >= new_element -> index) break;
        insert_after = node_ptr;
    }

    assert(insert_after);
    new_element -> next = insert_after -> next;
    insert_after -> next = new_element;

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
    list_t* prev_node = NULL;
    list_t* node_ptr;
    for (node_ptr = head; node_ptr;) {
        list_t* next_node = node_ptr -> next;

        node_ptr -> next = prev_node;

        prev_node = node_ptr;
        node_ptr = next_node;
    }

	return prev_node;
}

