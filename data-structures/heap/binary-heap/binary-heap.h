// binary queue interface
#ifndef _binary_queue_
#define _binary_queue_

// customized before used
// this is int type mini value is -9999...
#define MIN_VALUE -99999999

// this item should be fixed by users
// customized not machine or code can do
// note:: ++++
typedef int element_type;



// return 0 is ok, -1 is failed
int b_h_init(struct binary_heap *h, int capacity);

// return 0 if empty,  -1if not
int b_h_is_empty(struct binary_heap *h);

// return 0 if full, -1 is not
int b_h_is_full(struct binary_heap *h);

// return 0 if insert success, -1 if failed
int b_h_insert(struct binary_heap *h, element_type *e);

// return 0 if delete min success, -1 if failed
int b_h_delete_min(struct binary_heap *h, element_type *e);

// return 0 if build heap success, -1 if failed
int b_h_build(struct binary_heap *h);

// return 0 if find min success, -1 failed
int b_h_find_min(struct binary_heap *h, element_type *e);

#endif
