#include <bits/stdc++.h>
using namespace std;

int permutation(vector<int> coins, int n, string psf, int target)
{
   if (target == 0)
   {
      cout << psf << " ";
      return 1;
   }
   int count = 0;
   for (int i = 0; i < n; i++)
   {
      if (target - coins[i] >= 0)
      {
         count += permutation(coins, n, psf + to_string(coins[i]), target - coins[i]);
      }
   }
   return count;
}
int combination_1(vector<int> &coins, int idx, int target, string psf)
{

   if (target == 0)
   {
      cout << psf << endl;
      return 1;
   }
   if (idx < 0)
      return 0;
   int take = 0;
   if (target - coins[idx] >= 0)
      combination_1(coins, idx, target - coins[idx], psf + to_string(coins[idx]));
   int not_take = combination_1(coins, idx - 1, target, psf);
   return take + not_take;
}
int combination_2(vector<int> &coins, int st, int end, string psf, int target)
{
   if (target == 0)
   {
      cout << psf << " ";
      return 1;
   }
   int count = 0;
   for (int i = st; i <= end; i++)
   {
      if (target - coins[i] >= 0)
      {
         count += combination_2(coins, i, end, psf + to_string(coins[i]), target - coins[i]);
      }
   }
   return count;
}
// =========================================================
int combination_sub(vector<int> &coins, int idx, int target, string psf)
{
   if (target == 0 || idx < 0)
   {
      if (target == 0)
      {
         cout << psf << endl;
         return 1;
      }
      return 0;
   }
   int count = 0;
   if (target - coins[idx] >= 0)
      count += combination_sub(coins, idx - 1, target - coins[idx], to_string(coins[idx]) + psf);
   count += combination_sub(coins, idx - 1, target, psf);
   return count;
}
int combination_infi_sub(vector<int> &coins, int idx, int target, string psf)
{
   if (target == 0 || idx < 0)
   {
      if (target == 0)
      {
         cout << psf << endl;
         return 1;
      }
      return 0;
   }
   int count = 0;
   if (target - coins[idx] >= 0)
      count += combination_infi_sub(coins, idx, target - coins[idx], to_string(coins[idx]) + psf);
   count += combination_infi_sub(coins, idx - 1, target, psf);
   return count;
}
int permutation_subse_infi(vector<int> &coins, int target, string psf, int idx, int n)
{
   if (target == 0 || idx < 0)
   {
      if (target == 0)
      {
         cout << psf << " ";
         return 1;
      }
      return 0;
   }
   int count = 0;
   count += permutation_subse_infi(coins, target, psf, idx - 1, n);
   if (target - coins[idx] >= 0)
      count += permutation_subse_infi(coins, target - coins[idx], to_string(coins[idx]) + psf, n - 1, n);

   return count;
}
int permutation_subse_single(vector<int> &coins, int target, string psf, int idx, int n)
{
   if (target == 0 || idx < 0)
   {
      if (target == 0)
      {
         cout << psf << " ";
         return 1;
      }
      return 0;
   }
   int count = 0;
   count += permutation_subse_single(coins, target, psf, idx - 1, n);
   if (coins[idx] > 0 && target - coins[idx] >= 0)
   {
      int val = coins[idx];
      coins[idx] = -val;
      count += permutation_subse_single(coins, target - coins[idx], to_string(coins[idx]) + psf, n - 1, n);
      coins[idx] = val;
   }

   return count;
}
// ================================================================

int queencombination(int tnb, int tnq, int q_no, int b_no, string psf)
{
   if (q_no == tnq)
   {
      cout << psf << endl;
      return 1;
   }
   int count = 0;
   for (int i = b_no; i < tnb; i++)
   {
      count += queencombination(tnb, tnq, q_no + 1, i + 1, psf + "q" + to_string(q_no) + "b" + to_string(i) + " ");
   }
   return count;
}
int queenPermutation(vector<bool> &boxes, int tnb, int tnq, int q_no, string psf)
{
   if (q_no == tnq)
   {
      cout << psf << endl;
      return 1;
   }
   int count = 0;
   for (int i = 0; i < tnb; i++)
   {
      if (boxes[i] == false)
      {
         boxes[i] = true;
         count += queenPermutation(boxes, tnb, tnq, q_no + 1, psf + "q" + to_string(q_no) + "b" + to_string(i) + " ");
         boxes[i] = false;
      }
   }
   return count;
}
// ===================================================================
int queencombination_2D(vector<vector<bool>> &grid, int tnq, int q_no, int b_no, string psf)
{
   if (q_no == tnq)
   {
      cout << psf << endl;
      return 1;
   }
   int n = grid.size();
   int m = grid[0].size();
   int count = 0;
   for (int i = b_no; i < n * m; i++)
   {
      int x = i / m;
      int y = i % m;
      count += queencombination_2D(grid, tnq, q_no + 1, i + 1, psf + "q" + to_string(q_no) + "(" + to_string(x) + "," + to_string(y) + ") ");
   }
   return count;
}
int queenPermutation_2D(vector<vector<bool>> &boxes, int tnq, int q_no, string psf)
{
   if (q_no == tnq)
   {
      cout << psf << endl;
      return 1;
   }
   int count = 0;
   int n = boxes.size();
   int m = boxes[0].size();
   for (int i = 0; i < n * m; i++)
   {
      int x = i / m;
      int y = i % m;
      if (boxes[x][y] == false)
      {
         boxes[x][y] = true;
         count += queenPermutation_2D(boxes, tnq, q_no + 1, psf + "q" + to_string(q_no) + "(" + to_string(x) + "," + to_string(y) + ") ");
         boxes[x][y] = false;
      }
   }
   return count;
}
bool isSafe_combination(vector<vector<bool>> &grid, int x, int y, int n, int m)
{
   if (grid[x][y])
      return false;
   int dir[4][2] = {{-1, -1}, {0, -1}, {-1, 0}, {-1, 1}};
   for (int i = 0; i < 4; i++)
   {
      for (int rad = 1; rad < n; rad++)
      {
         int nx = x + rad * dir[i][0];
         int ny = y + rad * dir[i][1];
         if (nx >= 0 && ny >= 0 && nx < n && ny < m)
         {
            if (grid[nx][ny])
               return false;
         }
         else
         {
            break;
         }
      }
   }
   return true;
}

int nqueen_combination(vector<vector<bool>> &grid, int idx, int q_no, int tnb, string psf)
{
   if (q_no == tnb)
   {
      cout << psf << endl;
      return 1;
   }
   int n = grid.size();
   int m = grid[0].size();
   int count = 0;
   for (int i = idx; i < n * m; i++)
   {
      int x = i / m;
      int y = i % m;
      if (isSafe_combination(grid, x, y, n, m))
      {
         grid[x][y] = true;
         count += nqueen_combination(grid, i + 1, q_no + 1, tnb, psf + "q" + to_string(q_no) + "(" + to_string(x) + "," + to_string(y) + ") ");
         grid[x][y] = false;
      }
   }
   return count;
}
bool isSafe_permutation(vector<vector<bool>> &grid, int x, int y, int n, int m)
{
   if (grid[x][y])
      return false;
   int dir[8][2] = {{-1, -1}, {0, -1}, {-1, 0}, {-1, 1}, {1, 1}, {0, 1}, {1, 0}, {1, -1}};
   for (int i = 0; i < 8; i++)
   {
      for (int rad = 1; rad < n; rad++)
      {
         int nx = x + rad * dir[i][0];
         int ny = y + rad * dir[i][1];
         if (nx >= 0 && ny >= 0 && nx < n && ny < m)
         {
            if (grid[nx][ny])
               return false;
         }
         else
         {
            break;
         }
      }
   }
   return true;
}
int nqueen_permutation(vector<vector<bool>> &grid, int idx, int q_no, int tnb, string psf)
{
   if (q_no == tnb)
   {
      cout << psf << endl;
      return 1;
   }
   int n = grid.size();
   int m = grid[0].size();
   int count = 0;
   for (int i = idx; i < n * m; i++)
   {
      int x = i / m;
      int y = i % m;
      if (isSafe_permutation(grid, x, y, n, m))
      {
         grid[x][y] = true;
         count += nqueen_permutation(grid, 0, q_no + 1, tnb, psf + "q" + to_string(q_no) + "(" + to_string(x) + "," + to_string(y) + ") ");
         grid[x][y] = false;
      }
   }
   return count;
}

int ksubset(vector<int> &sum, vector<int> &arr, int idx, vector<vector<int>> &res)
{
   if (idx == arr.size())
   {
      for (int i = 1; i < sum.size(); i++)
      {
         if (sum[i] != sum[i - 1])
         {
            return 0;
         }
      }
      for (int i = 0; i < res.size(); i++)
      {
         for (auto val : res[i])
         {
            cout << val << " ";
         }
         cout << endl;
      }
   }
   int k = sum.size();
   for (int i = 0; i < k; i++)
   {
      sum[i] += arr[idx];
      res[i].push_back(arr[idx]);
      ksubset(sum, arr, idx + 1, res);
      sum[i] -= arr[idx];
      res[i].pop_back();
      // if (res[i].size() == 0)
      //    break;
   }
}
int main()
{
   vector<int> coins{2, 3, 5, 7};
   // cout << permutation(coins, 4, "", 10);
   // combination_1(coins,3,10,"");
   // combination_2(coins,0,3,"",10);
   // ================================================
   // combination_sub(coins, 3, 10, "");
   // combination_infi_sub(coins, 3, 10, "");
   // cout << endl;
   // cout << permutation_subse_infi(coins, 10, "", 3, 4);
   // permutation_subse_single(coins, 10, "", 3, 4);
   // cout << queencombination(5, 3, 0, 0, "");
   // vector<bool> boxes(5, false);
   // cout<<queenPermutation(boxes,5,3,0,"");
   vector<vector<bool>> grid(4, vector<bool>(4, false));
   // queencombination_2D(grid,3,0,0,"");
   // cout<<queenPermutation_2D(grid,2,0,"");
   // cout << nqueen_combination(grid, 0, 0, 4, "");
   // cout << nqueen_permutation(grid, 0, 0, 4, "");
   int k = 3;
   vector<int> arr = {1, 2, 3, 4, 5, 6};
   vector<int> sum(k, 0);
   vector<vector<int>> res(k);
   ksubset(sum, arr, 0, res);
   return 0;
}