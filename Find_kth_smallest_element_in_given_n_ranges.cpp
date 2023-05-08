vector<int>kthSmallestNum(vector<vector<int>>&range, vector<int>queries){
        //Write your code here
        sort(range.begin(),range.end(),[&](vector<int>&a,vector<int>&b){
            return a[0]!=b[0]?a[0]<b[0]:a[1]<b[1];
        });
        vector<vector<int>>temp;
        temp.push_back({range[0][0],range[0][1]});
        
        for(int i=1;i<range.size();i++){
            int s =temp.size();
            if(temp[s-1][1]>=range[i][0] && temp[s-1][1]>=range[i][1])continue;
            else if(temp[s-1][1]>=range[i][0] && temp[s-1][1]<=range[i][1]){
                temp[s-1][1]=range[i][1];
            }else{
                temp.push_back(range[i]);
            }
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int k=queries[i];
            
            for(int j=0;j<temp.size();j++){
                int tempTotal=temp[j][1]-temp[j][0]+1;
                //cout<<temp[j][0]<<" "<<temp[j][1]<<endl;
                if(tempTotal==1)tempTotal++;
                if(tempTotal<k)
                    k-=tempTotal;
                else if(tempTotal==k){
                    ans.push_back(temp[j][1]); 
                    break;
                }else{
                    ans.push_back(temp[j][0]+k-1);
                    break;
                }
            }
            if(ans.size()<i+1){
                ans.push_back(-1);
            }
        }
        return ans;
    }
