	int search(string text, string pat)
	{
	      int tempSize=pat.size();
	   pat+='#';
	   pat+=text;
	   vector<int>dp(pat.size(),0);
	   
	   for(int i=1;i<pat.size();i++){
	       int j= dp[i-1];
	       while(j>0 && pat[i]!=pat[j])j=dp[j-1];
	       if(pat[j]==pat[i])j++;
	       dp[i]=j;
	      if(dp[i]==tempSize)return 1;
	   }
	
	   return 0;
	
	}
