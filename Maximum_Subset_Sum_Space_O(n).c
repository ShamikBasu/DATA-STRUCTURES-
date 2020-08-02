//							Maximum sum such that no two elements are adjacent 
//  [7,10,12,7,9,14]-> output=a[0]+a[2]+a[5]=7+12+14=33 
//	[1,20,5]-> ouput=a[1]=20
//	Solved using Dynamic Programmin=> We will solve smaller problems and summing the smmaller solutions we will reach the final solution
// TIME O(N) 
// SPACE O(N)
// we are using the formula
//maxSum[i]= maximum of(maxSum[i-1] , maxSum[i-2]+array[i]) where array is the input array
// HOWEVER THERE IS A CONSTRAINT OF THE ELEMENTS HAS TO BE POSITIVE , BECAUSE NEGATIVE VALUE WOULD TWEAK THE SUM AND HENCE THE FORMULA

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int max(int a,int b) //to find the maximum
{
	if(a>b)
		return a;
	else 
		return b;
}
int maxSubsetSum(int array[],int n) //time O(n) space O(n)
{
	
	if(n==0)
		return -1;
	else if(n==1)
		return array[0];
	int *maxSum;
	maxSum=(int*)malloc(n*sizeof(int));
	maxSum[0]=array[0];					//the first sum would be the first element itself
	int i;
	maxSum[1]=max(array[0],array[1]);
	for(i=2;i<n;i++)
		maxSum[i]=max(maxSum[i-1],maxSum[i-2]+array[i]);
	return maxSum[n-1];
	
}
int main()
{
	int n,array[MAX];
	
	printf("ENTER THE NUMBER OF ELEMENTS \n");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n ENTER THE %d th ELEMENT = ",i+1);	
		scanf("%d",&array[i]);
	}
	printf("\n MAXIMUM SUM =%d", maxSubsetSum(array,n) );
	return 0;
}

