//							Maximum sum such that no two elements are adjacent 
//  [7,10,12,7,9,14]-> output=a[0]+a[2]+a[5]=7+12+14=33 
//	[1,20,5]-> ouput=a[1]=20
//	Solved using Dynamic Programmin=> We will solve smaller problems and summing the smmaller solutions we will reach the final solution
// TIME O(N) 
// SPACE O(1)
// we are using the formula
// we only need to store two conditions -> first= current , second= first , current=max(first, second+array[i])
// THIS REDUCES THE SPACE TO CONSTANT
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
int maxSubsetSum(int array[],int n) //time O(n) space O(1)
{
	
	if(n==0)
		return -1;
	else if(n==1)
		return array[0];
	int first,second,current;
	second=array[0];
	first=max(array[0],array[1]);
	int i;
	for(i=2;i<n;i++)
	{
		current=max(first,second+array[i]);
		second=first;
		first=current;
	}
	return first;
	
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

