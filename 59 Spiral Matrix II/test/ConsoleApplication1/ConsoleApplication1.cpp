#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int count = 1, row = 0, arr = 0, dir = 1;
    while (count <= n)
    {
        ans[row][arr] = count;
        cout << count;

        if (dir == 1)
        {
            if (arr + 1 >= n || ans[row][arr + 1] != 0)
            {
                dir++;
                continue;
            }
            arr++;
        }
        else if (dir == 2)
        {
            if (row + 1 >= n || ans[row + 1][arr] != 0)
            {
                dir++;
                continue;
            }
            row++;
        }
        else if (dir == 3)
        {
            if (arr - 1 < 0 || ans[row][arr - 1] != 0)
            {
                dir++;
                continue;
            }
            arr--;
        }
        else
        {
            if (row - 1 < 0 || ans[row - 1][arr] != 0)
            {
                dir = 1;
                continue;
            }
            row--;
        }
        count++;
    }
    return ans;
}

int main()
{
    generateMatrix(3);
    return 0;
}