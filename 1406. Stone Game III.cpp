class Solution 

{
public:
    string stoneGameIII(vector<int>& stoneValue)
    {
        n = stoneValue.size();
        dp.assign(n, vector<int>(2, INT_MIN));

        int result = dfs(0, 1, stoneValue);
        if (result == 0) return "Tie";
        return result > 0 ? "Alice" : "Bob";
    }
};