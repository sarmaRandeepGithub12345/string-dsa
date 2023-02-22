//Rabin-Karp Algorithm

//Worst case time complexity  - O(N*M)
int search(string text, string pat)
	{
	    // Your code goes here
	 int patSize=pat.size(),tempSize=text.size();   
	 int patSum=0;
	 int tempSum=0;
	 int pro=1;
	 int d=256;
	 int mod=INT_MAX;
	 for(int i=0;i<patSize-1;i++)
	     pro=(pro*d)%mod;
	 
	 for(int i=0;i<patSize;i++){
	     patSum= (patSum*d+pat[i])%mod;
	     tempSum=(tempSum*d+text[i])%mod;
	 }
     //Average case time complexity  - O(N+M-1)
	 for(int i=0;i<=tempSize-patSize;i++){
	     if(patSum==tempSum){
	         int j=0;
	         for(;j<patSize;j++){
	             if(pat[j]!=text[i+j])break;
	         }
	         if(j==patSize)return 1;
	     }
	     if(i<tempSize-patSize){
	      tempSum=(d*(tempSum-text[i]*pro)+text[i+patSize])%mod;   
	     }
	 }
	    return 0;
	}
};
