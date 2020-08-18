// BRANCH SUM
// TAKES THE ROOT OF THE BINARY TREE , AND FINDS THE SUM OF EACH BRANCH
//			 1
// 	               /   \
//		      2     3
//		     / \   / \
//		    4   5 6   7
//		  /  \  /
//   		 8   9 10
//		[15 ,10,18,10,11]
//		1+2+4+8=15....1+3+7=11
//	TIME O(N) 
//	SPACE O(N)

import java.util.*;
import java.io.*;
public class branchSumUsingArray
{	
	static int n;
	static int a[]=new int[100];
	static ArrayList <Integer> sums=new ArrayList<Integer>();
	public static int isRight(int i)
	{
		return (2*i+1);
	}
	public static int isLeft(int i)
	{
		return (2*i);
	}
	
	public static void branchSum(int node,int runningSum) //TIME  O(N) SPACE O(N)
	{
		if(node>n)
		{
			return;
		}
		int newRunningSum=runningSum+a[node];
		if(isLeft(node)>n && isRight(node)>n)
		{
			sums.add(newRunningSum);
			return;
		}
		branchSum(isLeft(node),newRunningSum);
		branchSum(isRight(node),newRunningSum);
	} 
	public static void main(String args[])
	{
		BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("ENTER THE NUMBER OF NODES\n");
		try
		{
		n = Integer.parseInt(inp.readLine());
		
		for(int i=1;i<=n;i++)
		{	
			a[i]=Integer.parseInt(inp.readLine());	
		}
		}
		catch(Exception e){}
		branchSum(1,0);
		System.out.println("SUM LIST="+sums);
	}
}