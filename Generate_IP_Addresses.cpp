int check(string s){
        int n=s.length();
        
        if(n<=0 || n>3)return 0;
        
        if(s[0]=='0' && n>1)return 0;
        int num=stoi(s);
        if(num>=0 && num<=255)return 1;
        return 0;
        
    }
    vector<string>ans;
    void generate(int i,int j,int k,string s){
        string s1=s.substr(0,i+1);
        string s2=s.substr(i+1,j-i);
        string s3=s.substr(j+1,k-j);
        string s4=s.substr(k+1,s.length()-k);
        
        if(check(s1) && check(s2) && check(s3) && check(s4)){
            ans.push_back(s1+'.'+s2+'.'+s3+'.'+s4);    
        }
        
    }
    vector<string> genIp(string &s) {
        // Your code here
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    generate(i,j,k,s);
                }
            }
        }
        return ans;
    }
