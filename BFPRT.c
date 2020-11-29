/* BFPRT算法，俗称中位数的中位数，由五个人共同发明，字母为五人首字母缩写
 * 第k小元素问题的另一种解法见findkth.c
 * 最差时间复杂度为O(n),最差空间复杂度为O(logN)。*/

/* 将n个元素分为n/5组，每组5个
 * 寻找每个组中位数，可使用插入排序完成
 * 将各组的中位数与数组最前方元素交换，递归找到中位数的中位数pivot
 * 最终剩下的为pivot，大于它的在右边，剩下在其左边
 * 判断pivot位置与k的大小，有选择的对左边或者右边递归*/

#include <stdio.h>
void swap(int[],int,int);
int insertsort(int[],int,int);
int partition(int[],int,int,int);
int pivot_index(int[],int,int);
int BFPRT(int[],int, int,int);
int getPivotIndex(int[],int,int);

// exchange arr[i] and arr[j]
void swap(int arr[],int i, int j){
	if (i!=j){
		int tmp;
		tmp = arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
	}
}

//插入排序,返回中位数下标
int insertsort(int arr[], int low, int high){
	for (int i=low+1; i<=high; ++i)
		for (int j=i; j>low & arr[j-1]>arr[j]; --j)
			swap(arr, j, j-1);
	return (high-low)/2+low;
}

int partition(int arr[], int left, int right, int pivot_i){
	swap(arr,right, pivot_i);	//这样，pivot_i索引的数值在最右侧
	int i=left-1;
	for (int j=left; j<right;++j)
		if(arr[j]<arr[right]) swap(arr,++i,j);
	swap(arr,++i,right);
	return i;
}

//求第k大数值索引
int BFPRT(int arr[], int low, int high, int k){
	int pivot_index = getPivotIndex(arr,low,high);//得到中位数的中位数下标
	int divide_index = partition(arr,low,high,pivot_index);//返回划分边界,目的是获得上述中位数在low-high分组排序中的实际位置
	int num = divide_index-low+1;//获得在整个数组中中位数的实际位置,为了与最终目的k对比
	if (num==k) return divide_index;	//没有返回num是因为在递归中，返回的始终是子序列的索引
	else if (num>k) return BFPRT(arr, low, divide_index-1,k);
	else return BFPRT(arr, divide_index+1, high, k-num);	//若k为7,num为5,则在divide_i右方「子数列」中寻找第2小的即可
}

//寻找中位数的中位数下标
int getPivotIndex(int arr[], int low, int high){
	if (high-low<5) return insertsort(arr,low,high);
	int subRight=low-1;//low减1是为了一循环方便，二数值始终处于有效区域，而不是+1区域
	for (int i=low; i+4<=high; i+=5){
		int index = insertsort(arr,i,i+4);
		swap(arr,++subRight,index);	//这样，中位数们就会排列在数组最左侧
	}

	return BFPRT(arr,low,subRight,((subRight-low+1)/2)+1);	//重点，通过BFPRT，以中位数为目标获得中位数索引
	//假设low=3, subR=7,subR-low+1为一共有多少个数值，/2+1表明这其中第几个数为中位数
}

int main(void){
	int arr[10] = {5,4,76,1,88,7,10,120,0,10};	//0 1 4 5 7 10 10 76 88 120
//	for (int i=0;i<10;++i)
//		printf("%d ",arr[i]);
	printf("%d\n", arr[BFPRT(arr,0,9,8)]);
	return 0;
}
