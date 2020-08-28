import java.util.*;
import java.io.*;

public class LongestCommonSubsequence 
{
	public static String longestCommonSubsequence(String s1,String s2) //time=O(N*M*min(N,M) || space=O(N*M*min(N,M)
	{
		String lcs[][]=new String[s2.length()+1][s1.length()+1];
		for(int i=0;i<s2.length()+1;i++)
			for(int j=0;j<s1.length()+1;j++)
				lcs[i][j]="";
		for(int i=1;i<s2.length()+1;i++)
		{
			for(int j=1;j<s1.length()+1;j++)
			{
				if(s2.charAt(i-1)==s1.charAt(j-1))
					lcs[i][j]=String.valueOf(s2.charAt(i-1))+lcs[i-1][j-1];
				else
					lcs[i][j]=lcs[i-1][j].length()>lcs[i][j-1].length()?lcs[i-1][j] : lcs[i][j-1];
			}
		}
		return lcs[s2.length()][s1.length()];
	}
	public static void main(String args[])
	{
		BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
		String s1="",s2="";
		System.out.println("ENTER THE TWO STRINGS\n");
		try
		{
		s1= inp.readLine();
		s2= inp.readLine();
		}
		catch(Exception e1){}
		
		System.out.println("\nLONGEST COMMON SUBSEQUENCE ="+longestCommonSubsequence(s1,s2));
	}
	
}