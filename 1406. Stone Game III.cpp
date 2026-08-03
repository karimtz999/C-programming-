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
private:
    int n;
    vector<vector<int>> dp;

    int dfs(int index, int turn, vector<int>& stoneValue)
    {
        if (index >= n) return 0;
        if (dp[index][turn] != INT_MIN) return dp[index][turn];

        int score = 0;
        int bestScore = (turn == 1) ? INT_MIN : INT_MAX;

        for (int i = 0; i < 3 && index + i < n; ++i)
        {
            score += stoneValue[index + i];
            int nextScore = dfs(index + i + 1, 1 - turn, stoneValue);

            if (turn == 1) // Alice's turn
                bestScore = max(bestScore, score + nextScore);
            else // Bob's turn
                bestScore = min(bestScore, nextScore - score);
        }

        return dp[index][turn] = bestScore;
    }
};