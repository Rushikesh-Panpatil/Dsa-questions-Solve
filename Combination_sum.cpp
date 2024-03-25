#include<iostream>
#include<vector>
using namespace std;

    void combinationSum_Helper(vector<int>& candidates, int target,  vector<int>&v, vector<vector<int>>&ans,  int index){
        //base
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target < 0){
            return;
        }

        for(int i = index; i<candidates.size(); i++){
            v.push_back(candidates[i]);
            combinationSum_Helper(candidates, target - candidates[i], v, ans, i);
            v.pop_back();

        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        combinationSum_Helper(candidates, target, v, ans, 0);
        return ans;
    }

int main(){
    vector<int>candidates ={2,3,6,7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates,target);
       for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        } 
        cout<<endl;
    }
    return 0;
}