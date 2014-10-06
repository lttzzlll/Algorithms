// binary queue implemention
// use fixed array to implement 

#include"binary-heap.h"
#include<stdio.h>
#include<stdlib.h>


// top is the minimum element postition usually it is 1 not 0
const int sentinal = 0;


struct binary_heap {
	int capacity;
	int size;
	element_type *elements;
};


int b_h_init(struct binary_heap *h, int capacity) {
	h = (struct binary_heap*)malloc(sizeof(struct binary_heap));
	if(h==NULL) {
		return -1;
	}

	h->capacity = capacity;
	h->size = 0;
	h->elements = (element_type*)malloc(sizeof(element_type)*(capacity +1));

	if(h->elements == NULL) {
		return -2;
	}

	h->elements[sentinal] = MIN_VALUE;

	return 0;
}

int b_h_is_empty(struct binary_heap *h) {
	return h->size == 0;
}

int b_h_is_full(struct binary_heap *h) {
	return h->size == capacity;
}

int b_h_insert(struct binary_heap *h, element_type *e) {
	if(b_h_is_full(h)) {
		return -1;
	}

	int i;
	for(i= ++h->size; h->elements[i/2] > *e; i/=2) {
		h->elements[i/2] = h->elements[i];
	}

	h->elements[i] = *e;

	return 0;
}

int b_h_delete_min(struct binary_heap *h, element_type *e) {
	if(b_h_is_empty(h)) {
		return -1;
	}

	int i, child;
	element_type last_element;

	*e = h->elements[1];
	last_element = h->elements[h->size--];
	
	for(i=1; i*2<=h->size; i=child) {
		child = i*2;
		if(child != h->size && h->elements[child+1] < h->elements[child]) {
			child++;
		}
		if(last_element > h->elements[child]) {
			h->elements[i] = h->elements[child];
		}else {
			break;
		}
	}

	h->elements[i] = last_element;

	return 0;
}

int find_min(struct binary_heap *h, element_type *e) {
	if(b_h_is_empty(h)) {
		return -1;
	}

	*e = h->elements[1];

	return 0;
}

// insert instead build
int b_h_build(struct binary_heap *h) {
	return 0;
}

