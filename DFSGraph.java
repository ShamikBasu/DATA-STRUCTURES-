//				DEPTH FIRST SEARCH
//	Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures
//	The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and explores as far as possible along each branch before backtracking.
// 	Basically we will explore a branch all the way, before moving to the next.
// 				         0
//			      /	   |    \
//			      1    2     3
//			    /	\	        / \
//			   4	 5       6   7
//			       / \	    \
//			      8   9	    10
// 			starting vertex=0 output-> 7,10,6,3,2,9,8,5,4,1,0
//	TIME=O(V+E) 


import java.util.*;
import java.io.*;

class Node
{
	int value;
	Node next;
	public Node(int value,Node next)
	{
		this.value=value;
		this.next=next;
	}
}
class AdjList
{
	Node head;
}
public class DFSGraph
{
	int size;
	AdjList array[];
	public DFSGraph(int size)
	{
		this.size=size;
		array=new AdjList[this.size];
		for(int i=0;i<size;i++)
		{
			array[i]=new AdjList();
			array[i].head=null;
		}
	}
	public void add(int src,int dest)
	{
		Node n=new Node(dest,null);
		n.next=array[src].head;
		array[src].head=n;
	}
	public void dfsExplore(int startVertex)
	{
		Boolean []visited=new Boolean[size];
		for(int i=0;i<size;i++)
			visited[i]=false;
		Stack <Integer>st=new Stack<Integer>();
		st.push(startVertex);
		while(!st.isEmpty())
		{
			int m=st.pop();
			st.push(m);
			visited[m]=true;
			Node head=array[m].head;
			Boolean isDone=true;
			while(head!=null)
			{
				if(visited[head.value]==false)
				{
					st.push(head.value);
					visited[head.value]=true;
					isDone=false;
					break;
				}
				else
					head=head.next;
			}
			if(isDone==true)
				System.out.println("\nVISITED = "+st.pop());
		}
	}
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("\n ENTER THE  NUMBER OF NODES\n");
		int n=sc.nextInt();
		DFSGraph g=new DFSGraph(n);
		
		System.out.println("\n WANT TO ENTER EDGE? Y OR N\n");
		char c=sc.next().charAt(0);
		while(c=='y' || c=='Y')
		{
			
			System.out.println("\n ENTER THE NODES BETWEEN WHICH THE EDGE IS\n");
			g.add(sc.nextInt(),sc.nextInt());
			System.out.println("\n WANT TO ENTER EDGE? Y OR N\n");
			c=sc.next().charAt(0);	
		}
		System.out.println("\n ENTER THE STARTING VERTEX\n");
		g.dfsExplore(sc.nextInt());		
	}
}
