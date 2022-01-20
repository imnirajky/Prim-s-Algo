#include <bits/stdc++.h>
using namespace std;


int main(){
    int node, edge;
    cin>>node>>edge;
    vector<int> visit(node, 0), weight(node, INT_MAX), parent(node);
    vector<vector<int>> link(node, vector<int> (node, 0));

    

    for(int i=0; i<edge; i++){
        int a, b, w;
        cin>>a>>b>>w;
        link[a][b] = w;
        link[b][a] = w;
    }

    weight[0] = 0;

    //Smallest Weight Node and Un-visited
    int currNode, count = 0;

    for(int i=0; i<node; i++){
    int val = INT_MAX;
    for(int i=0; i<node; i++){
        if(visit[i] == 0){
        if(val>weight[i]){
            currNode = i;
            val = weight[i];
        }
    }
    }  
    visit[currNode] = 1;
    
    for(int j=0; j<node; j++){
        if(link[currNode][j] && visit[j] == 0){
            weight[j] = min(link[currNode][j], weight[j]);
            parent[j] = currNode;
        }
    }
    }

    for(int i=1; i<node; i++){
        cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
    }
}