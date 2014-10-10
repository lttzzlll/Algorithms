// 循环赛日程表
#include<stdio.h>
#include<stdlib.h>

int a[65][65];

void cycle(int k, int a[][65]) {
	int n = 1;

	for(int i=1; i<=k; i++) { n *= 2; }
	for(int i=1; i<=n; i++) { a[1][i] = i; }
	
	int m = 1;
	for(int s=1; s<=k; s++) {
		n /= 2;
		for(int t=1; t<=n; t++) {
			for(int i=m+1; i<=2*m; i++) {
				for(int j=m+1; j<=2*m; j++) {
					// down  right       up    left
					a[i][j+(t-1)*m*2] = a[i-m][j+(t-1)*m*2-m];
					// down left         up    right
					a[i][j+(t-1)*m*2-m] = a[i-m][j+(t-1)*m*2];
				}
			}
		}
		m *= 2;
	}
}

// failed
// now succeed : the reason is that the martrix is [symmetrical]
void cycle2(int k, int a[][65]) {
	int n = 1;

	// n is the population of the objects
	for(int i=1; i<=k; i++) { n *= 2; }
	// view the table first column is the number of each object
	for(int i=1; i<=n; i++) { a[i][1] = i; }

	/* how to understand the code is depend on how you observe the martrix
	 * the martrix is symmetrical about coordinate and each symmetrical part
	 * is obvious and how to generate he martrix ? 
	 * will be review tomorrow
	 */
	// m is the step size
	int m = 1;
	// s is the looptimes
	for(int s=1; s<=k; s++) {
		n /= 2;
		// t is the current number of each object
		for(int t=1; t<=n; t++) {

			/* the copy part define here */
			// i  and j  loop is used for copy to each symmetrical part
			for(int i=m+1; i<=2*m; i++) {
				for(int j=m+1; j<=2*m; j++) {
					// down right     =   up    left
//					a[i][j+(t-1)*m*2] = a[i-m][j+(t-1)*m*2-m];
					// up   right     =   down  left
//					a[i-m][j+(t-1)*m*2] = a[i][j+(t-1)*m*2-m];

					// differ
					// coordinate [symmetrical]!
					// explicity compliant
					//   down     right       up        left
					a[i+(t-1)*m*2][j] = a[i+(t-1)*m*2-m][j-m];
					//   up         right     down      left
					a[i+(t-1)*m*2-m][j] = a[i+(t-1)*m*2][j-m];
				}
			}
		}
		m *= 2;
	}
}

void display(int arr[][65], int k) {
	int n = 1;
	for(int i=1; i<=k; i++) { n *= 2; }
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int k = 3;
	printf("enter k===> n=2**k: ");
	scanf("%d", &k);
	if(k>4 || k<0) {
		printf("k(%d) is too big or too small\n", k);
		exit(-1);
	}
	cycle2(k, a);
	display(a, k);
	return 0;
}
