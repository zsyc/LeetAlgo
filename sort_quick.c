#include <stdio.h>

#define LEN 10
int a[LEN] = {5,2,4,7,1,3,2,6,10,9};

int partition (int start, int end){
	int key = a[start], i = start, j = end;
	int tmp;
	while(i<j){
		if (a[j]>=key){
			--j;
			continue;
		}
		if (a[i]<=key){
			++i;
			continue;
		}
		tmp = a[i];
		a[i]= a[j];
		a[j--]= tmp;
	}
    a[start] = a[i];
	a[i] = key;
	return i;
}

void quicksort (int start, int end){
	int mid;
	if (end>start){
		mid = partition(start, end);
		quicksort(start, mid-1); 
		quicksort(mid+1,end);
	}
}

int main(void){
	quicksort(0,LEN-1);
	printf("%d %d %d %d %d %d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
	return 0;
}

