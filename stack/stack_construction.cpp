// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//    vector<vector<int>>mat={{1,2,7,9,7},
//                            {4,5,8,3,5},
//                            {3,2,11,4,6},
//                            {6,0,7,12,5}};
//    vector<vector<int>>pre(4,vector<int>(5,0));
//    int presum=0;
//    for(int i=0;i<5;i++){
//       pre[0][i]=presum+mat[0][i];
//       presum=pre[0][i];
//    } 
//    presum=0;
//    for(int i=0;i<4;i++){
//       pre[i][0]=presum+mat[i][0];
//       presum=pre[i][0];
//    }  
//    for(int i=1;i<4;i++){
//       for(int j=1;j<5;j++){
//         pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+mat[i][j];
//       }
//    }
//    for(int i=0;i<4;i++){
//       for(int j=0;j<5;j++){
//          cout<<pre[i][j]<<" ";
//       }
//       cout<<endl;
//    }                   
// return 0;
// }    

