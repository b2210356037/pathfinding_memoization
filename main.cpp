#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

int pathFind(vector<vector<int>>& grid, vector<vector<int>>& memo, int row, int col){
    for(int i = row-1; i >= 0; i--){
        for(int j = col-1; j >= 0; j--){
            if(grid[i][j] == 1) continue;
            if(i == row-1 && j == col-1) continue;
            memo[i][j] = memo[i+1][j] + memo[i][j+1];
        }
    }
    return memo[0][0];
}

int main(){
    //2d vector for reperesenting the grid, for pathfinding algo
    vector<vector<int>> grid = {
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 0, 1, 0},
            {0, 1, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0}
    };
    vector<vector<int>> memo(grid.size()+1, vector<int>(grid[0].size()+1, 0));
    int row = grid.size();
    int col = grid[0].size();
    memo[row-1][col-1] = 1;
    int res = pathFind(grid, memo, row, col); //8 8

    cout << res;

    return 0;
}