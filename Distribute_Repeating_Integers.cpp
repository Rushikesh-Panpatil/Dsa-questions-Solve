#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

    bool canDistributeHelper(vector<int>& counts, vector<int>& quantity, int ithcustomer){
        //base
        if(ithcustomer == quantity.size()){
          
            return true;
        }

        for(int i =0; i<counts.size(); ++i){
            if(counts[i] >= quantity[ithcustomer]){
                counts[i] -=quantity[ithcustomer];
                if(canDistributeHelper(counts, quantity ,ithcustomer+1)){
                    return true;
                }
                counts[i] += quantity[ithcustomer];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int , int> countMap;
        for(auto num :nums)
        countMap[num]++;
        vector<int>counts;
        for(auto it:countMap)
         counts.push_back(it.second);
         sort(quantity.rbegin(), quantity.rend());
         return canDistributeHelper(counts, quantity, 0);
             
    }

int main(){
    vector<int>nums={1,2,3,3};
    vector<int>quantity={2};
    bool ans = canDistribute(nums, quantity);
    if(ans == 1){
        cout<<"True";
    }
    else{
        cout<<"false";
    }
    return 0;
}





