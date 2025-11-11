#include<bits/stdc++.h>
using namespace std;

struct Item{
    int idx;
    int weight;
    int profit;
};

int main(){
    
    int n;
    cin>>n;
    vector<Item> items(n);
    for (int i=0; i<n; i++){
        cin>>items[i].weight;
        items[i].idx = i+1;
    }

    for (int i=0; i<n; i++){
        cin>>items[i].profit;
    }

    int W;
    cin>>W;

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i=1; i<=n; i++){
        int wt = items[i-1].weight;
        int pr = items[i-1].profit;
        for (int w=0; w<=W; w++){
            if (wt > w){
                dp[i][w] = dp[i-1][w];
            }
            else{
                dp[i][w] = max(dp[i-1][w], pr + dp[i-1][w-wt]);
            }
        }
    }

    cout<<endl;
    cout<<setw(6)<<"i"<<setw(8)<<"pi"<<setw(8)<<"wi";
    for (int w=0; w<=W; w++){
        cout<<setw(5)<<w;
    }
    cout<<endl;

    for (int i=0; i<=n; i++){
        if (i == 0){
            cout<<setw(6)<<i<<setw(8)<<"-"<<setw(8)<<"-";
        }
        else{
            cout<<setw(6)<<i<<setw(8)<<items[i-1].profit<<setw(8)<<items[i-1].weight;
        }
        for (int w=0; w<=W; w++){
            cout<<setw(5)<<dp[i][w];
        }
        cout<<endl;
    }

    cout<<endl;

    vector<Item> selected;
    int res = dp[n][W];
    int w = W;

    for (int i=n; i>0 && res > 0; i--){
        if (res != dp[i-1][w]){
            selected.push_back(items[i-1]);
            res -= items[i-1].profit;
            w -= items[i-1].weight;
        }
    }

    cout<<"max profit: " << dp[n][W]<<endl;
    for (auto& item:selected){
        cout<<"index: "<<item.idx;
        cout<<", weight: " <<item.weight;
        cout<<", profit: "<<item.profit<<endl;
    }
    cout<<endl;

    return 0;
}