#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
};

void printpath(int v, vector<int>& parent){
    if (v == -1) return;
    printpath(parent[v], parent);
    cout<<v<<" ";
}

int main(){
    int V, E;
    cout<<"Enter V, E"<<endl;
    cin>>V>>E;
    vector<Edge> edges(E);
    cout<<"Enter u, v, w"<<endl;
    for (int i=0; i<E; i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }

    cout<<"u, v, w are: "<<endl;
    for (auto &e : edges) {
        cout << e.u << " -> " << e.v << ", weight = " << e.w << "\n";
    }

    cout<<"ENter src, dest"<<endl;
    int src, dest;
    cin>>src>>dest;

    vector<int> dist(V+1, INT_MAX), parent(V+1, -1);
    dist[src] = 0;

    bool updated;
    for (int i=1; i<=V-1; i++){
        updated = false;
        for (auto& e : edges){
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]){
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                cout<<"updated dist to vertex "<<e.v<<" to "<<dist[e.v]<< " via edge " << e.u << "->" << e.v << "\n";
                updated = true;
            }
        }
        if (!updated){
            break;
        }
    }

    int cyclestart = -1;
    for (auto& e : edges){
        if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]){
            cyclestart = e.v;
            break;
        }
    }

    if (cyclestart != -1){
        cout<<"negative cycle detected"<<endl;
        for (int i=0; i<V; i++){
            cyclestart = parent[cyclestart];

        }

        vector<int> cycle;
        int v = cyclestart;
        do{
            cycle.push_back(v);
            v = parent[v];
        } while (v != cyclestart && v != -1);
        cycle.push_back(cyclestart);

        reverse(cycle.begin(), cycle.end());

        cout<<"cycle: "<<endl;
        for (auto& x:cycle) cout<<x<<" ";
        cout<<endl;
        return 0;
    }

    cout<<endl;
    cout<<"distance array:"<<endl;
    for (int i=1; i<=V; i++){
        cout<<i<<" - ";
        if (dist[i] == INT_MAX) cout<<"INF";
        else cout<<dist[i];
        if (i != V) cout<<", ";

    }
    cout<<endl;

    cout<<"dist from "<<src<<" to "<<dest<<" :"<<endl;
    if (dist[dest] == INT_MAX) cout<<"no path exists"<<endl;
    else{
        cout<<"shortest distance: "<<dist[dest]<<endl;
        cout<<"path: "<<endl;
        printpath(dest, parent);
        cout<<endl;
    }



    return 0;
}