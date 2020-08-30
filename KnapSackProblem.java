//	KNAPSACK PROBLEM
// 	WE HAVE TWO ARRAYS COST AND WEIGHT , AS PER THE NAME , IT CONTAINS THE COST AND WEIGHT OF N ITEMS , THE PROBLEM IS TO FIND THE MAXIMUM PROFIT WE CAN OOZE OUT WITHIN A GIVEN CAPACITY
//  	FORMULA-> VALUE[i][j]=MAX(VALUE[i-1][j],VALUE[i-1][j-w]) as long as w<=j -> w = Weight of the current item
//	TIME=O(NC) N= NUMBER OF ITEMS C=CAPACITY OF OUR BAG
//	SPACE=O(NC)
//	WE CAN ALWAYS USE 2D ARRAY WITH TWO COLUMNS TO REPRESENT THE ITEMS AS PRICE AND WEIGHT AS TWO COLUMNS
//	WE CAN ALSO BACKTRACK AND BUILD THE KNAPSACK ITEMS




import java.util.*;
import java.io.*;

public class KnapSackProblem
{
	public static int knapsack(int cost[],int weight[],int capacity) //TIME O(NC) SPACE O(NC)
	{
		int knapsackValues[][]=new int[cost.length+1][capacity+1];
		for(int i=0;i<cost.length+1;i++)
			for(int j=0;j<capacity+1;j++)
				knapsackValues[i][j]=0;
		for(int i=1;i<cost.length+1;i++)
		{
			int currentWeight=weight[i-1];
			int currentValue=cost[i-1];
			for(int c=0;c<capacity+1;c++)
			{
				if(currentWeight>c)
					knapsackValues[i][c]=knapsackValues[i-1][c];
				else
					knapsackValues[i][c]=Math.max(knapsackValues[i-1][c],currentValue+knapsackValues[i-1][c-currentWeight]);
			}
		}
		return knapsackValues[cost.length][capacity];
	}
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("enter the number of items");
		int n=sc.nextInt();
		int cost[]=new int[n];
		int weight[]=new int[n];
		for(int i=0;i<n;i++)
		{
			System.out.println("Enter the cost and weight of the"+(i+1)+"th item");
			cost[i]=sc.nextInt();
			weight[i]=sc.nextInt();
		}
		System.out.println("Enter the capacity");
		int capacity=sc.nextInt();
		System.out.println("THE MAXIMUM PROFIT IS = "+knapsack(cost,weight,capacity));
	}
}