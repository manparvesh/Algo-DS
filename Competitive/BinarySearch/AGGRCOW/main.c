#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, c;
int ar[100001];

int check(int num){
	int cows = 1, position = ar[0];
	int i;
	for(i=1;i<n;i++){
		if(ar[i] - position >= num){
			position = ar[i];
			cows++;
			if(cows == c){
				return 1;
			}
		}
	}
	return 0;
}

int binary_search(){
	int ini = 0;
	int last = ar[n-1];
	int max = -1;

	while(last > ini){
		int mid = (ini + last) / 2;
		if(check(mid)){
			if(mid > max){
				max = mid;
			}
			ini = mid + 1;
		}else{
			last = mid;
		}
	}
	return max;
}

int compare( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

int sort(){
	qsort( ar, n, sizeof(int), compare);
}

int main(){
	int t;
	scanf("%d", &t);
	int i, x;
	while(t--){
		scanf("%d %d", &n, &c);
		memset(ar, 0, sizeof(ar));
		for(i=0;i<n;i++){
			scanf("%d", &ar[i]);
		}
		sort();
		printf("%d\n", binary_search());
	}
	return 0;
}