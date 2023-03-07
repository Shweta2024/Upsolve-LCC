//This solution throws a TLE(15/60)

//Time Complexity = O(2^n)
//Space Complexity = O(n)

class Solution {
public:
    
    int ways(int currentIndex, int target, int count, vector<vector<int>>& types, unordered_map<string,int>&memo)
    {
        if(target == 0) return 1;
        if(currentIndex >= types.size() || target < 0) return 0;
        
        string key = to_string(currentIndex)+"#"+to_string(target)+"#"+to_string(count);
        if(memo.find(key) != memo.end()) return memo[key];
        
        int take = 0, notTake = 0;
        if(types[currentIndex][1] <= target && count > 0)
            take = ways(currentIndex,target-types[currentIndex][1],count-1,types,memo);
        
        if(currentIndex+1 < types.size())
            notTake = ways(currentIndex+1,target,types[currentIndex+1][0],types,memo);
        
        memo[key] = ((take%1000000007)+(notTake%1000000007))%1000000007;
        return memo[key];
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types)
    {
        unordered_map<string,int>memo;
        return ways(0,target,types[0][0],types,memo);
    }
};
