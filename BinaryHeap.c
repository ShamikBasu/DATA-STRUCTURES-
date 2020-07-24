//BINARY MAX HEAP USING COMPLETE BINARY TREE
//BINARY MAX HEAP IS A BINARY TREE WHERE THE VALUE OF EACH NODE IS AT LEAST THE VALUE OF ITS CHLIDREN 
// A BINARY TREE IS COMPLETE IF ALL ITS LEVEL ARE FILLED EXCEPT THE LAST WHICH IS FILLED FROM LEFT TO RIGHT
// OPERATIONS-> getMax(),insert(),extractMax(), changePriority(),remove()
// BINARY HEAP IS A WAY TO IMPLEMENT PRIORITY QUEUE 
//ADVANTAGES-> FAST AND SPACE EFFICIENT
// FOR COMPLETE BINARY TREE , THE HEIGHT AT MAX IS CEIL(LOG (N+1))-1 WHERE N= NUMBER OF NODES
// ARRAY INDEX AS PER THE TREE NODES ARE DENOTED IN THE FOLLOWING WAY			
//			     1
//			  /	\
//		    	 2	 3
// 		   	/  \	/  \
//		       4    5   6   7    
// variables-> maxSize = max no. of elements in the heap    size=size of the heap  H[]=the array for the heap 

#include<stdio.h>
#include<math.h>
#define maxSize 100

int size=0,H[maxSize];
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
int extractMax() //time O(log n)
{
	int result=H[1];
	H[1]=H[size];
	size--;
	shiftDown(1);
	return result;
}
void removeNode(int i) //time O(log n)
{
	H[i]=999999;
	shiftUp(i);
	extractMax();
}
void changePriority(int i,int p) ////time O(log n)
{
	int oldp=H[i];
	H[i]=p;
	if(p>oldp)
		shiftUp(i);
	else
		shiftDown(i);
}
void display()
{
	int i;
	for(i=1;i<=size;i++)
		printf("%d	",H[i]);
}
void getMax()//O(1)
{
	printf("MAXIMUM ELEMENT=%d\n",H[1]);
}
int main() //main function , can be done by switch case too 
{
	int ch=1;
	while(ch!=0)
	{
		
		printf("\nENTER YOUR CHOICE 0) EXIT 1) INSERT 2) EXTRACT MAX 3) REMOVE 4)CHANGE PRIORITY 5)DISPLAY 6)GET THE MAXIMUM\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			int p;
			scanf("%d",&p);
			insert(p);		
		}
		else if(ch==2)
			printf("\n MAX=%d\n",extractMax());
		else if(ch==3)
		{		
			int i;
			scanf("%d",&i);
			removeNode(i);
		}
		else if(ch==4)
		{
			int i,p;
			scanf("%d%d",i,p);
			changePriority(p,i);
		}
		else if(ch==5)
			display();
		else if(ch==6)
			getMax();
	}
	return 0;
}
