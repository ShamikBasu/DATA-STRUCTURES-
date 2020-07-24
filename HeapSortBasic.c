//HEAP SORT ALGORITHM (ASCENDING ORDER)
//Time Complexities BEST=O(N LOG N) AVERAGE=O(N LOG N) WORST=O(N LOG N)
//THE RESULTING ALGORITHM IS COMPARISON BASED AND HAS RUNNING TIME OF o(N LOG N) , HENCE IT IS ASYMTOTICALLY OPTIMAL
//NATURAL GENERALISATION OF SELECTION SORT: INSTEAD OF SIMPLY SCANNING THE REST OF THE ARRRAY TO FIND THE MAXIMUM VALUE WE USE A SMART DATA STRUCTURE (BINARY HEAP)
// DISADVANTAGE: USES ADDITIONAL SPACE TO STORE THE PRIORITY QUEUE (BINARY HEAP) 
// TO CURE THIS DISADVANTAGE WE USE THE "IN PLACE HEAP SORT ALGORITHM" , YOU WILL FIND IT IN THE REPOSITORY (IF UPLOADED)

#include<stdio.h>
#include<math.h>
#define maxSize 100

int size=0,H[maxSize],A[maxSize];
void swap(int *a,int *b) //call by reference 
{
	int c=*a;
	*a=*b;
	*b=c;
}
int parent(int i) 
{
	return floor(i/2);
}
int leftChild(int i) 
{
	return 2*i;
}
int rightChild(int i)
{
	return 2*i+1;
}
void shiftUp(int i) //shifting the node up by comparing it with it's parent node
{
	while(i>1 && H[parent(i)]<H[i])
	{
		swap(&H[parent(i)],&H[i]);
		i=parent(i);
	}
}
void shiftDown(int i) //Shifting the node down by comparing it with its child nodes
{
	int maxIndex=i;
	int l=leftChild(i);
	if(l<=size && H[l]>H[maxIndex])
		maxIndex=l;
	int r=rightChild(i);
	if(r<=size && H[r]>H[maxIndex])
		maxIndex=r;
	if(i!=maxIndex)
	{
		swap(&H[i],&H[maxIndex]);
		shiftDown(maxIndex);	
	}	
}
void insert(int p) //time O(log n)
{
	if(size==maxSize)
		return ;
	
	size++;	
	H[size]=p;
	
	shiftUp(size);
}
void heapSort(int n) //time O(n log n) 
{
	int i;
	for(i=0 ;i<n; i++)
	{
		insert(A[i]);
	}
	for(i=n-1;i>=0;i--)
	{
		A[i]=extractMax();
	}
}
int extractMax() //time O(log n)
{
	int result=H[1];
	H[1]=H[size];
	size--;
	shiftDown(1);
	return result;
}

void display(int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d	",A[i]);
}
int main() //main function , can be done by switch case too
{
	int ch=1;
	while(ch!=0)
	{
		
		printf("\nENTER YOUR CHOICE 0) EXIT 1) RUN HEAP SORT\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			int n,i;
			printf("\nEnter the Number of Elements\n");
			scanf("%d",&n);			
			for(i=0;i<n;i++)
			{
				printf("\nENTER THE %d th ELEMENT	",(i+1));
				scanf("%d",&A[i]);
				//display(n); un  comment this to check the array insertion 
			}
			//display(n); to display the unsorted array
			heapSort(n);
			printf("\n");
			display(n);				
		}
		else if(ch!=0)
			printf("\n WRONG INPUT\n");
	}
	return 0;
}
