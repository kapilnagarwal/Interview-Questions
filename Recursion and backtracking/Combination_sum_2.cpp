/* 
Question Link : https://leetcode.com/problems/combination-sum-ii/

==========================================================================================
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
======================================================================================
Time Complexity: O(2^n*k)

Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take âkâ//average space for the ds.

Space Complexity: O(k*x)

Reason: if we have x combinations then space will be x*k where k is the average length of the combination
*/

class Solution {
public:
    void findCombination(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        
        for (int i = idx; i < arr.size(); i++)
        {
            if (i > idx && arr[i] == arr[i-1])  continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombination(i+1, target-arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
