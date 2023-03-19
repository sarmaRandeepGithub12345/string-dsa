//https://www.codingninjas.com/codestudio/problems/count-customers-who-did-not-get-a-computer_1115775?leftPanelTab=0
#include <bits/stdc++.h> 
int countCustomers(vector<int> &arr, int k)
{
    //    Write your code here
     int res=0;
     int n=arr.size();
     int ch[n+1]={0};
     for(auto it:arr){
         if(ch[it]==0){
           if(k>0){
               k--;
               ch[it]=1;
           }else {
               res++;
               ch[it]=2;
           }   
         }else if(ch[it]==1){
               k++;
               ch[it]=0;
         }
     }
return res;
}
