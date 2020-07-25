// QUICK SORT ALGORITHM
// IT IS DIVIDE AND CONQUER-> CHOOSE A PIVOT AT RANDOM AND SORT THE ARRAY BASED ON PIVOT
// TIME COMPLEXITY-> BEST=O(N LOG N) AVERAGE=O(N LOG N) WORST=O(N*N)
// SPACE COMPLEXITY -> O(LOG N)
// ALWAYS APPLY THE QUICK SORT FIRST ON SMALLER SUB-ARRAY, BECAUSE IT MAKES O(LOG N) SPACE USED ON CALL STACK, USING TAIL RECURSION REDUCES MEMORY ON CALL STACK
// 
#include<stdio.h>
#define maxSize 100
int array[maxSize];

void swap(int *,int *);
void quickSort(int);
void quickSortHelper(int,int);

void swap(int *a,int *b) //call by reference 
{
	int c=*a;
	*a=*b;
	*b=c;
}
void quickSort(int n)
{
	quickSortHelper(0,n-1);
}
void quickSortHelper(int startIdx,int endIdx ) //TIME -> BEST=O(N LOG N) AVERAGE=O(N LOG N) WORST=O(N*N)
{
	if(startIdx>=endIdx)
		return;
	int pivotIdx=startIdx;  //HERE WE ARE TAKING PIVOT AS THE FIRST ELEMENT , YOU CAN ALWAYS USE A RANDOM FUCTION TO GENERATE ANY INDEX TO BE THE PIVOT
	int leftIdx=startIdx+1;
	int rightIdx=endIdx;
	while(rightIdx>=leftIdx)
	{
		if(array[leftIdx]>array[pivotIdx] && array[rightIdx]<array[pivotIdx])
			swap(&array[leftIdx],&array[rightIdx]);
		if(array[leftIdx]<=array[pivotIdx])
			leftIdx++;
		if(array[rightIdx]>array[pivotIdx])
			rightIdx--;
	}
	swap(&array[pivotIdx],&array[rightIdx]);
	int leftSubArrayIsSmaller=rightIdx-1-startIdx<endIdx-(rightIdx+1);
	if(leftSubArrayIsSmaller)
	{
		quickSortHelper(startIdx,rightIdx-1);
		quickSortHelper(rightIdx+1,endIdx);
	}		
	else
	{
		quickSortHelper(rightIdx+1,endIdx);
		quickSortHelper(startIdx,rightIdx-1);		
	}
}
void display(int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d	",array[i]);
}
int main() //main function , can be done by switch case too
{
	int ch=1;
	while(ch!=0)
	{
		
		printf("\nENTER YOUR CHOICE 0) EXIT 1) RUN QUICK SORT\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			int n,i;
			printf("\nEnter the Number of Elements\n");
			scanf("%d",&n);			
			for(i=0;i<n;i++)
			{
				printf("\nENTER THE %d th ELEMENT	",(i+1));
				scanf("%d",&array[i]);
				//display(n); un  comment this to check the array insertion 
			}
			//display(n); to display the unsorted array
			quickSort(n);
			printf("\n");
			display(n);				
		}
		else if(ch!=0)
			printf("\n WRONG INPUT\n");
	}
	return 0;
}


