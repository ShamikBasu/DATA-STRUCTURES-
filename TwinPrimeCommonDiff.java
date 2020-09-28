//	There is a range given l and h 
//	In which we have to find the count all the prime pairs whose difference is k
//	We have to find how many sets are there within a given range.
//	Sample Input:
//	4 l
//	30 h
//	6 k
//	Output:
//	6
//	Explanation:
//	(5, 11) (7, 13) (11, 17) (13, 19) (17, 23) (23, 29) 
//	We have 6 prime pairs.
//	We are using Sieve of 
//	The most efficient way to find all of the small primes (say all those less than 10,000,000) is by using a sieve such as the Sieve of Eratosthenes(ca 240 BC):
//	Make a list of all the integers less than or equal to n (and greater than one). Strike out the multiples of all primes less than or equal to the square root of n, then the numbers that are left are the primes.
//	This method is so fast that there is no reason to store a large list of primes on a computer--an efficient implementation can find them faster than a computer can read from a disk. In fact the problem with the algorithm as presented above is not really speed (it uses O(n(log n)log log n) bit operations), but rather space (it is O(n)). So for large n we usually use a segmented sieve. However, both the time and space theoretically can be improved; for example, Pritchard's "linear segmented wheel sieve" uses O(n log n) bit operations and O(sqrt(n)/log log n) space.
//	For more on this go to- https://primes.utm.edu/glossary/page.php?sort=SieveOfEratosthenes#:~:text=The%20most%20efficient%20way%20to,Eratosthenes(ca%20240%20BC)%3A&text=Strike%20out%20the%20multiples%20of,are%20left%20are%20the%20primes.

import java.util.*;
import java.io.*;
public class TwinPrimeCommonDiff
{
	public static int primeSieve(int l,int h ,int k)
	{
		boolean prime[] = new boolean[h+1]; 
       		for(int i=0;i<=h;i++) 
            		prime[i] = true; 
          
        	for(int p = 2; p*p <=h; p++) 
        	{ 
            		if(prime[p] == true) 
            		{ 
                	for(int i = p*2; i <= h; i += p) 
                    		prime[i] = false; 
            		} 
        	} 
		int c=0;
		/*for(int i=l;i<=h;i++)
			if(prime[i]==true)
				System.out.println(i);*/
		for(int i=l;i<h-k;i++)
		{
			if(prime[i] && prime[i+k])
				c++;
		}
		return c;
	}
	public static void main(String args[])
	{
		BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
		try
		{
			int l= Integer.parseInt(inp.readLine());
			int h= Integer.parseInt(inp.readLine());
			int k= Integer.parseInt(inp.readLine());
			System.out.println(primeSieve(l,h,k));
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
	}
}