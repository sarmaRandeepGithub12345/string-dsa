    bool match(string pattern, string text)
    {
        // code here
        int n=text.length(),m =pattern.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    dp[n][m]=1;
    int k=m-1;
    while(pattern[k]=='*'){
        dp[n][k]=1;
        k--;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
         if(text[i]==pattern[j])dp[i][j]=dp[i+1][j+1];
         else if(pattern[j]=='?')dp[i][j]=dp[i+1][j+1];
         else if(pattern[j]=='*')dp[i][j]=max(dp[i][j+1],max(dp[i+1][j],dp[i+1][j+1]));   
        }
    }
    
    return dp[0][0];
    }
