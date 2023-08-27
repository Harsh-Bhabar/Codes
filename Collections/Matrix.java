package Collections;
import java.util.Scanner;

public class Matrix {
	public static void main(String args[]){
		Solution sol = new Solution();
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        String b = sc.nextLine();
		int len = sol.longestCommonSubsequence(a, b);
		System.out.println(len);
        sc.close();
	}
}

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();

        int[][] dp = new int[m+1][n+1];

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1.charAt(i-1) == text2.charAt(j-1)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        for(int[] x: dp){
            for(int y: x){
                System.out.print(y + " ");
            }System.out.println();
        }

        // System.out.println(Arrays.deepToString(dp));

        return dp[m][n];
    }
}