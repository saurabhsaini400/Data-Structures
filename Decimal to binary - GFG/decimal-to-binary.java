//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;

class GFG{
	public static void main(String [] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		while(test-- > 0) {
			int N = sc.nextInt();
			Solution obj = new Solution();
			obj.toBinary(N);
			System.out.println();
		}
	}
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    String s="";
    public String fun(int n){
        if(n==0)return "";
        
        fun(n/2);
        s = s + n%2;
        return s;
    }
	void toBinary(int N) {
		//Write your code here
		System.out.print(fun(N));
	}
}