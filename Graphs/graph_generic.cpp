#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
map<T,list<T> > adjlist;
public:
    Graph(){
    }
    void addEdge(T u, T v, bool bidir = true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }

    void print(){
        for(auto i:adjlist){
            cout<<i.first<<"->";
            for(T entry:i.second){
                cout<<entry<<',';
            }
            cout<<endl;
        }
    }
    void bfs(T src){

        queue<T> q;
        map<T,bool> visited;
        q.push(src);
        visited[src] = true;
            while(!q.empty()){
                T node = q.front();
                q.pop();
                cout<<node<<" ";
            for(auto neighbour: adjlist[node]){
                if(visited[neighbour] != true){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }
    void bfs_short(T src){
        queue<T> q;
        map<T, int> dist;
        map<T,T> parent;
        for(auto i:adjlist){
            dist[i.first] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        parent[src] = src;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node;
            for(auto neighbour:adjList[node]){
                if(dist[neighbour] == INT_MAX){
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
         }
         for(auto i : adjlist){
            T node = i.first;
            cout<<"Dist. of "<<node<<"from"<<src<<"is"<<dist[node]<<endl;
         }
      }
      void dfshelper(T node,map<T,bool > &visited){
        visited[node] = true;
        T temp = node;
        cout<<node<<" ";
        for(T neighbour:adjlist){
            if(!visited[neighbour]){
                dfshelper(neighbour , visited);
            }
        }
      }
      void dfs(T src){
        map<T ,bool > visited;
        dfshelper(src,visited);

        int components = 1;

        for(auto i:adjlist){
            T lol = i.first;
            if(!visited[lol]){
                dfshelper(src,visited);
                components++;
            }
        }
        cout<<endl;
        cout<<"The graphs have "<<components<<"Components";
      }
      void dfsHelper(T node,map<T ,bool > &visited, list<T> &ordering){
        visited[node] = true;
        for(T neighbour:adjlist[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited,ordering);
            }
        }
      }
      void dfsTopologicalSort(){
        map<T,bool > visided;
        list<T> ordering;

        for(auto i:adjlist){
            T node = i.first;
            if(!visited[node]){
            dfsHelper(node,visited,ordering);
            }
        }
      }
};

int main(){
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(5,4);
    g.bfs(5);
    cout<<endl;
    g.bfs_short(5);
    cout<<endl;
    g.dfs(5);
return 0;
}
