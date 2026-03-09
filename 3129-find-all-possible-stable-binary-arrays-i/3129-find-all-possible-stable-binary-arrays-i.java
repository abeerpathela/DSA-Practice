class Solution {

    static final int MOD = 1000000007;

    int[][][][] dp;

    public int dfs(int zero, int one, int last, int count, int limit){

        if(zero == 0 && one == 0) return 1;

        if(dp[zero][one][last+1][count] != -1)
            return dp[zero][one][last+1][count];

        long ways = 0;

        // place 0
        if(zero > 0){
            if(last != 0)
                ways += dfs(zero-1, one, 0, 1, limit);
            else if(count < limit)
                ways += dfs(zero-1, one, 0, count+1, limit);
        }

        // place 1
        if(one > 0){
            if(last != 1)
                ways += dfs(zero, one-1, 1, 1, limit);
            else if(count < limit)
                ways += dfs(zero, one-1, 1, count+1, limit);
        }

        ways %= MOD;

        return dp[zero][one][last+1][count] = (int)ways;
    }

    public int numberOfStableArrays(int zero, int one, int limit) {

        dp = new int[zero+1][one+1][3][limit+1];

        for(int i=0;i<=zero;i++)
            for(int j=0;j<=one;j++)
                for(int k=0;k<3;k++)
                    for(int l=0;l<=limit;l++)
                        dp[i][j][k][l] = -1;

        return dfs(zero, one, -1, 0, limit);
    }
}