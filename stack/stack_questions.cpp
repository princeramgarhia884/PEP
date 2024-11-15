#include <bits/stdc++.h>
using namespace std;
vector<int> NGOR(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (st.size() > 0 && arr[st.top()] < arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
vector<int> NSOR(vector<int>arr)
{
    int n=arr.size();
    vector<int>res(n,n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(st.size()>0 && arr[st.top()]>arr[i]){
            res[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    return res;
}
vector<int>NGOL(vector<int>arr){
    int n=arr.size();
    stack<int>st;
    vector<int>res(n,-1);
    for(int i=n-1;i>=0;i--){
        while(st.size()>0 && arr[st.top()]<arr[i]){
            res[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    return res;
}
vector<int>NSOL(vector<int>arr){
    int n=arr.size();
    stack<int>st;
    vector<int>res(n,-1);
    for(int i=n-1;i>=0;i--){
        while(st.size()>0 && arr[st.top()]>arr[i]){
            res[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    return res;
}
void Print(vector<int> arr)
{
    for (auto val : arr)
    {
        cout << val << " ";
    }
    return;
}
int main()
{
    vector<int> arr = {2, 1, 3, 2, 1, 0, 4, 9, 6};
    // vector<int> res = NGOR(arr);
    // vector<int> res = NSOR(arr);
    // vector<int> res = NGOL(arr);
    vector<int> res = NSOL(arr);
    Print(res);
    return 0;
}