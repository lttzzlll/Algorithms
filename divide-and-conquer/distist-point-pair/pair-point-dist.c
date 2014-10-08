// distist point pair
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define N 105

const double INF = 1e20;
const int limit = 100;

struct point {
	double x;
	double y;
};

int n;
int tmpt[N];

int cmpxy(const void *a, const void *b) {
	struct point *u = (struct point *)a;
	struct point *v = (struct point *)b;
	if( u->x != v->x ) {
		return u->x < v->x;
	}
	return u->y < v->y;
}

/*
int cmpy(const void *a, const void *b) {
	struct point *u = (struct point *)a;
	struct point *v = (struct point *)b;
	return u->y < v.y;
}
*/

int cmpy(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

double min(double a, double b) {
	return a < b ? a : b;
}

double distance(struct point a, struct point b) {
	double x = a.x - b.x;
	double y = a.y - b.y;
	return sqrt(x*x + y*y);
}

// need to be improved
double distist(struct point *arr, int left, int right, struct point *u, struct point *v) {
	double d = INF;
	if(left == right) {

		return d;
	}
	if(left + 1 == right) {
		*u = arr[left];
		*v = arr[right];
		return distance(arr[left], arr[right]);
	}

	


	int mid = left + (right - left) / 2;

	double d1 = distist(arr, left, mid, u, v);
	
	struct point e1, e2;
	double d2 = distist(arr, mid+1, right, &e1, &e2);

	if(d2 < d1) {
		*u = e1;
		*v = e2;
		d = d2;
	}
	

	int i, j, k=0;
	double d3=INF;
	for(i=left; i<=right; i++) {
		if(fabs(arr[mid].x - arr[i].x) <= d) {
			tmpt[k++] = i;
		}
	}

	// integer sort
	qsort(tmpt, k, sizeof(tmpt[0]), cmpy);

	for(i=0; i<k; i++) {
		for(j=i+1; j<k && arr[tmpt[j]].y - arr[tmpt[i]].y < d; j++) {
			d3 = distance(arr[tmpt[i]], arr[tmpt[j]]);
			if(d > d3) {
				d = d3;
				*u = arr[tmpt[i]];
				*v = arr[tmpt[j]];
		//		printf("in dist===>point (%.2lf, %.2lf) and point (%.2lf, %.2lf) distist distance is %.2lf\n", u->x, u->y, v->x, v->y, d);
			}
		}
	}

	return d;
}

void random_unique(struct point *arr, int left, int right, int limit) {
	srand((unsigned)time(NULL));
	for(int i=left; i<=right; i++) {
		for(int j;;) {
			arr[i].x = rand() % limit;
			arr[i].y = rand() % limit;
			for(j=left; j<i; j++) {
				if(arr[j].x == arr[i].x && arr[j].y == arr[i].y) {
					break;
				}
			}
			if(j == i) {
				break; 
			}
		}
	}
}

void display(struct point *p, int left, int right) {
	printf("in display\n");
	for(int i=left; i<=right; i++) {
		printf("(%.2lf, %.2lf) ", p[i].x, p[i].y);
	}
	printf("\nend display\n");
}

// test drive
int main() {
	// test drive define here
	
	int n = 100;
	struct point *p = (struct point *)malloc(sizeof(struct point) * n + 1);
	struct point u, v;
	u.x = v.x = -1;
	u.y = v.y = -1;

	if(p==NULL) {
		printf("error\n");
		exit(-1);
	}

	random_unique(p, 0, n-1, limit);

	display(p, 0, n-1);

	double d = distist(p, 0, n-1, &u, &v);

	printf("point (%.2lf, %.2lf) and point (%.2lf, %.2lf) distist distance is %.2lf\n", u.x, u.y, v.x, v.y, d);

	return  0;
}


