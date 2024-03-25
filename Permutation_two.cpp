#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

   void permutehelp(vector<int>& nums, vector<vector<int>>&ans, int start){
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map<int, bool>visited;
        for(int i = start; i<nums.size(); i++){
            if(visited.find(nums[i]) != visited.end()){
                continue;
            }
            visited[nums[i]] = true;
            swap(nums[i], nums[start]);
            permutehelp(nums, ans, start +1);
            //backtrack
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permutehelp(nums, ans, 0);
        return ans;
    }
  

int main(){
    vector<int> nums={1,1,2};
    vector<vector<int>> result = permuteUnique(nums);
    for(int i =0; i<result.size(); i++){
        cout<<"[";
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"]";
        cout<<endl;
    }

    return 0;
}