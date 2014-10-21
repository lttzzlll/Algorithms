// counting sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// the number limits
#define LIMIT 1000
// the	numofcounts limits 
#define SIZE 101

void random_range(int *arr, int l, int r, int limit) {
    srand((unsigned)time(NULL));
    for(int i=l; i<=r; i++) {
        arr[i] = rand() % limit;
    }
}

void display(int *arr, int l, int r) {
    printf("in display\n");
    for(int i=l; i<=r; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nend display\n");
}

void counting_sort(int *a, int *b, int l, int r, int k) {
    int c[SIZE];
    
    for(int i=0; i<=k; i++) {
        c[i] = 0;
    }
    
    for(int j=1; j<=r; j++) {
        c[a[j]] = c[a[j]] + 1;
    }
    
    for(int i=1; i<=k; i++) {
        c[i] = c[i] + c[i-1];
    }
    
    for(int j=r; j>=1; j--) {
        b[c[a[j]]] = a[j];
        c[a[j]] = c[a[j]] - 1;
    }
    
}


// all of the files are counting sort interface
// so use these and think how to add new protocols
// counting sort driver
int counting_sort_main() {
    // test block
    int a[SIZE];
    int b[SIZE];
    int limit = 100;
    int n = 100;
    
    random_range(a, 1, n, limit);
    
    display(a, 1, n);
    
    counting_sort(a, b, 1, n, limit);
    
    display(b, 1, n);
    
    return 0;
}

void offset_random_unique(int *arr, int start, int end, int limits, int offset) {
	srand((unsigned)time(NULL));
	for(int i=start; i<=end; i++) {
		int j;
		for(;;) {
			arr[i] = rand() % limits + offset;
			for(j=start; j<i; j++) {
				if(arr[j] == arr[i]) {
					break;
				}
			}
			if(j==i) {
				break;
			}
		}
	}
}


void stable_sort(int *arr, int start, int end, int digit) {
	// copy the counting sort manually
	int b[SIZE];
	// as a return value : for easy
	//int *b = (int *)malloc(sizeof(int) * SIZE);
	// in case : factly it is not happened!
	/*
	if(b==NULL) {
		printf("alloc error in stable sort\n");
		exit(-1);
	}*/


	int c[SIZE];
	// set
	for(int i=0; i<SIZE; i++) {
		b[i] = c[i] = 0;
	}
	
	// default base-value
	int base = 10;
	int cutoff = 1;
	int tmp;

	for(int i=1; i<digit; i++) {
		cutoff *= base;
	}

	for(int i=start; i<=end; i++) {
		tmp = arr[i] / cutoff % base;
		c[tmp] += 1;
	}

	//c[0] is zero[clear]
	for(int i=start; i<=end; i++) {
		c[i] += c[i-1];
	}
	
	for(int i=start; i<=end; i++) {
		tmp = arr[i] / cutoff % base;
		// this is the error  0 <= tmp < base len ( c ) <= base
		// truble occured here!
		b[c[tmp]] = arr[i];
		c[tmp] -= 1;
	}
	// array b has the after sort information
	// copy it back to array arr [may be this is a good way] { not tested! }
	for(int i=start; i<=end; i++) {
		arr[i] = b[i];
	}
}

void radix_sort(int *arr, int start, int end, int num_of_digits) {
	// inteface implementation
	for(int i=1; i<=num_of_digits; i++) {
		stable_sort(arr, start, end, i);
	}
}

int main() {
	int arr[SIZE];
	int d = 3;
	int k;
	n = 20;
	int limits = 1000;
	int offset = 100;
	
	offset_random_unique(arr, 1, n, limits - offset, offset);
	display(arr, 1, n);

	// needs: array, start, end, digits numbers
	// each element is the same digit numbers
	radix_sort(arr, 1, n, d);

	display(arr, 1, n);

	return 0;
}

