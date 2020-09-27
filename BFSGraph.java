

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
public class BFSGraph
{
	int size;
	AdjList array[];
	public BFSGraph(int size)
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
	public void bfsExplore(int startVertex)
	{
		Boolean []visited=new Boolean[size];
		for(int i=0;i<size;i++)
			visited[i]=false;
		Queue <Integer>q=new LinkedList<Integer>();
		q.add(startVertex);
		while(!q.isEmpty())
		{
			int m=q.poll();
			System.out.println(m);
			visited[m]=true;
			Node head=array[m].head;
			Boolean isDone=true;
			while(head!=null)
			{
				if(visited[head.value]==false)
				{
					q.add(head.value);
					visited[head.value]=true;
				}
				else
					head=head.next;
			}
			
		}
	}
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("\n ENTER THE  NUMBER OF NODES\n");
		int n=sc.nextInt();
		BFSGraph g=new BFSGraph(n);
		
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
		g.bfsExplore(sc.nextInt());		
	}
}