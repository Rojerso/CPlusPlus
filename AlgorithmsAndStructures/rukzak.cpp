#include <iostream>

using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;
    int dp[n + 1][n + 1];  // матрица dynamic programming
    int w[n + 1], v[n + 1];  // weights and values
    
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= W; j++)
        {
            if(w[i] > j) dp[i][j] = dp[i-1][j];  // если не помещается, то цена и вместимость прежняя
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);  // либо кладём и складываем с предыдущим максимумом, либо не кладём
        }

    cout << dp[n][W] << endl;
    return 0;
}
