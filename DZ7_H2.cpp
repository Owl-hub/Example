/*
Эйлеров цикл

Определить, существует ли в графе, содержащем N вершин, путь, 
содержащий все M рёбер, который проходит по каждому из них ровно один раз.
*/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<vector <int> > g;
vector <int> deg;

void print(vector < vector < int > > D) {
    for (int i = 0; i < D.size(); ++i) {
        cout << i << ": ";
        for (int j = 0; j < D[i].size(); ++j) {
                cout << D[i][j] << " ";
            }
        cout << endl;
    }
}

void search_euler (int v, vector < vector < int > > &D, vector < int > &c)
{
    for (int i = 0; i < D[v].size(); ++ i){
        int u = D[v][i];
        if (D[v][i] >= 0) {
            D[v][i] = -1;
            for (int j = 0; j < D[u].size(); ++j) {
                if (D[u][j] == v) {
                    D[u][j] = -1;
                }
            }
            search_euler (u, D, c);
        }
    }
    c.push_back (v);
}
void euler (vector < vector < int > > D, vector < int > &c)
{
    int n = D.size ();
    c.clear ();

    int count = 0;
    int j = 0;
    for (int i = 0; i < n; ++ i) {
        if (deg[i] % 2 != 0)
        {
            ++count;
            if (count > 2) {
                cout << "NO" << endl;
                return;
            }
            j = i;
        }
    }


    search_euler (j, D, c);
    for (int i = 0; i < n; ++ i) {
         for (int j = 0; j < D[i].size(); ++ j) {
             if (D[i][j] > -1) {
                 cout << "NO" << endl;
                 return;
             }
         }
    }
    cout << "YES" << endl;
}



int main() {
    int n, m;
    cin >> m >> n;
    g.resize(n);
    deg.resize(n);
    deg.assign(n, 0);


    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
        deg[u-1]++;
        deg[v-1]++;
    }


    vector<int> res;

    euler(g, res);




    return 0;
}



