#include<bits/stdc++.h>
using namespace std;

struct Item{
    int idx;
    int profit;
    int weight;
    double ratio;
};

int partition(vector<Item>& arr, int low, int high){
    int pivot = arr[high].ratio;
    int i = low-1;

    for (int j=low; j<high; j++){
        if (arr[j].ratio > pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quicksort(vector<Item>& arr, int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

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
        items[i].ratio = (double)items[i].profit/items[i].weight;
    }

    int maxcap;
    cin>>maxcap;

    quicksort(items, 0, items.size()-1);

    double totalprofit = 0;
    int curw = 0;
    vector<pair<int, double>> selected;

    for (auto& item:items){
        if (curw + item.weight <= maxcap){
            curw += item.weight;
            totalprofit += item.profit;
            selected.push_back({item.idx, item.weight});
        }
        else{
            int rem = maxcap - curw;
            if (rem > 0){
                double frac = (double)rem/item.weight;
                totalprofit += item.profit*frac;
                selected.push_back({item.idx, rem});
            }
            break;
        }
    }



    cout<<totalprofit<<endl;
    cout<<curw<<endl;

    for (auto& s:selected){
        cout<<s.first<<" "<<s.second<<endl;
    }

    return 0;
}