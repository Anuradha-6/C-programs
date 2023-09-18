#include<iostream>
#include"Stack.cpp"
#define size 10
using  namespace std;
class Graph_DFT{
public:
    int v,e;
    int mat[size][size];
    int visited[];
    Graph_DFT(){
        cout<<"Enter no. of vertices\n";
        cin>>v;
        cout<<"Enter no. of edges\n";
        cin>>e;
        int x,y;
        mat[v][v];
        visited[v];
        for(int i=0;i<v;i++)
            for(int j=0;j<v;j++)
                mat[i][j]=0;
        for(int i=1;i<=e;i++){
            cout<<"For edge "<<i<<" :\n";
            cout<<"Enter starting vertex\n";
            cin>>x;
            cout<<"Enter ending vertex\n";
            cin>>y;
            mat[x][y]=1;
            mat[y][x]=1;
        }
    }
    void DFS(int v){
        Stack ob;
        visited[v]=1;
        ob.push(v);
        while(!ob.isEmpty()){
            int u=ob.pop();
            cout<<u<<" ";
            for(int i=0;i<v;i++){
                if(mat[v][i]==1){
                    int w=mat[v][i];
                    if(visited[w]!=1){
                        visited[w]=1;
                        ob.push(w);
                    }
                }
            }
        }
    }
    void DFT(){
        for(int i=0;i<v;i++)
            visited[i]=0;
        for(int j=0;j<v;j++){
            if(visited[j]!=1)
                DFS(j);
        }
    }
   /* void DFS(int v){
        visited[v]=1;
        cout<<v<<" ";
        for(int i=0;i<v;i++){
            if(mat[v][i]==1){
                int w=mat[v][i];
                if(visited[w]!=1)
                    DFS(w);
            }
        }
    }
    void DFT(int v){
        visited[v]=1;
        cout<<v<<" ";
        for(int j=0;j<v;j++){
            if(visited[j]!=1)
                DFS(j);
        }
    }*/
    void display(){
         for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cout<<mat[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph_DFT obj;
    cout<<"The Adjacency Matrix is:\n";
    obj.display();
    cout<<"Depth First Traversal of the graph is:\n";
    obj.DFT();
}
