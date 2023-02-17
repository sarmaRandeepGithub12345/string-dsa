  int expansion(int i,int j,string str){
      
      while(i>=0 && j<str.length() && str[i]==str[j]){
          i--;
          j++;
      }
      return j-i-1;
    } 
    string longestPalindrome(string S) {
        if(S.length()==0)return "";
        int n=S.length();
        int start=0,end=0;
        for(int i=0;i<n;i++){
            //check for odd
          int one=  expansion(i,i,S);
          int two=  expansion(i,i+1,S);
          int len=max(one,two);
           if(end-start+1<len){
           if(len%2){
             start=i-len/2;
             end=i+len/2;
           }else{
             start=i-(len/2-1);
             end=i+len/2;
           }
           }
        }
        string t="";
        for(int i=start;i<=end;i++){
            t+=S[i];
        }
        return t;
    }
