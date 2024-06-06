#include<stdio.h>
#include<stdlib.h>
int main(){
	int size;
	printf("Enter the size of the array\n");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the elements into the array :");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int ele;
	printf("Enter the element to be search : ");
	scanf("%d",&ele);
	int binaryresult=binarySearch(arr,ele,size);
	printf("BInary search : \n");
	if(binaryresult!=-1){
		printf("Element %d is found at the index %d\n",ele,binaryresult);
	}
	else{
		printf("Element %d is not found\n",ele);
	}
	return 0;
}
int binarySearch(int arr[],int ele,int size){
	int low=0;
	int high=size-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==ele){
			return mid;
		}
		else if(arr[mid]<ele){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return -1;
}