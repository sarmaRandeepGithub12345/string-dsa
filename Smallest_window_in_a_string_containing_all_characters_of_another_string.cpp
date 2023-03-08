#include <bits/stdc++.h>

using namespace std;

  string smallestWindow (string small, string big)
    {
        // Your code here
        int smap[26]={0};
        int bmap[26]={0};
        for(auto it:small)smap[it-'a']++;
        int start=-1,end=-2,mi=INT_MAX;
        int j=-1,i=-1;
        int n=big.length(),count=0;
        while(j<n){
            if(count<small.length()){
                j++;//j enters as 0(j) and leaves as 1(j++)
              
                if(bmap[big[j]-'a']<smap[big[j]-'a'])
                count++;
                
                bmap[big[j]-'a']++;
            }else if(count==small.length()){
                i++;
               
                if(bmap[big[i]-'a']==smap[big[i]-'a']){
                    count--;
                }
               
                bmap[big[i]-'a']--;
                
               if(mi>j-i+1){
                   mi=j-i+1;
                   start=i;
                   end=j;
               }
            }
        }
        string temp="";
        for(int i=start;i<=end;i++)temp+=big[i];
        return temp;
    }
int main()
{
    string t="timetopractice";
    cout<<smallestWindow("toc",t);

    return 0;
}
