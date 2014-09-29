// distist point pair 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int input_data[100][2];

int cmp(const void *a, const void *b) {
	int *p = (int*)a;
	int *q = (int*)b;
	if(p[0] == q[0]) {
		return p[1] - q[1];
	}else {
		return p[0] - q[0];
	}
}

void sort(int arr[][2], int n) {
	qsort(arr, n, sizeof(arr[1]), cmp);
}

void random_range(int arr[][2], int n, int xlimit, int ylimit) {
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++) {
		arr[i][0] = rand() % xlimit;
		arr[i][1] = rand() % ylimit;
	}
}

double dist(int a[], int b[]) {
	return sqrt( (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]) );
}

void random_unique(int arr[][2], int n, int xlimit, int ylimit) {
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++) {
		for(int j;;) {
			arr[i][0] = rand() % xlimit;
			arr[i][1] = rand() % ylimit;
			for(j=0; j<i; j++) {
				if(arr[i][0] == arr[j][0] && arr[i][1] == arr[j][1]) {
					break;
				}
			}
			if(j==i) {
				break;
			}
		}
	}
}

void display(int arr[][2], int n) {
	printf("display an array\n");
	for(int i=0; i<n; i++) {
		printf("(%d, %d) ", arr[i][0], arr[i][1]);
	}
	printf("\nend display\n");
}

double find_closet_point_pair(int arr[][2], int a[], int b[], int n) {
	double cur_dist, closet = 999999999;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			cur_dist = dist(arr[i], arr[j]);
			if(cur_dist < closet) {
				closet = cur_dist;
				a[0] = arr[i][0];
				a[1] = arr[i][1];
				b[0] = arr[j][0];
				b[1] = arr[j][1];
			}
		}
	}
	return closet;
}

int main() {
	int n = 100, select, xlimit, ylimit;
	select = 0;
	xlimit = ylimit = 100;
	if(select) {
		random_unique(input_data, 100, xlimit, ylimit);
	}else {
		random_range(input_data, 100, xlimit, ylimit);
	}
	
	display(input_data, n);

	int a[2], b[2];
	double closet;
	
	closet = find_closet_point_pair(input_data, a, b, n);

	printf("closet dist is %lf, points is (%d, %d) and (%d, %d) \n", closet, a[0], a[1], b[0], b[1]);

	printf("after sort\n");
	sort(input_data, n);
	display(input_data, n);

	return 0;
}
