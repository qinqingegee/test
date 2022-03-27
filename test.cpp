#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges; // 边
vector<double> succ; // 成功概率
int n; // 边的数目
stack<int> st;
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        typedef pair<int, double> PID;
        typedef pair<double, int> PDI;
        vector<vector<PID>> g(n);
        for (int i = 0; i < edges.size(); i ++ )
        {
            int a, b;
            double c;
            a = edges[i][0], b = edges[i][1];
            c = succ[i];
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        // for(int i = 0; i < g.size(); i++)
        // {
        //     for(int j = 0;j < g[i].size(); j++)
        //     {
        //         cout<<i << ' ' << j <<' ' << g[i][j].first<<' '<<g[i][j].second<<endl;
        //     }
        // }
        vector<double> d(n, 0);
        vector<int> path(n, -1);
        priority_queue<PDI> h; //此时用大根堆，每次取出最大值
        h.push({1.0, start});
        d[start] = 1;
        while (h.size())
        {
            PDI t = h.top();
            h.pop();
            double w = t.first;
            int v = t.second;
            
            for (int i = 0; i < g[v].size(); i ++)
            {
                PID j = g[v][i];
                if (d[j.first] < w * j.second) //判断时注意变号
                {
                    d[j.first] = w * j.second;
                    h.push({d[j.first], j.first});
                    path[j.first] = v;
                }
            }
        }
        int temp = end;
        st.push(end);
        while(path[temp] != -1)
        {
            // cout<<path[temp]<< ' ';
            st.push(path[temp]);
            temp = path[temp];
        }
        cout <<"path is :" ;
        while (!st.empty())
        {
            cout<<st.top() << ' ';
            st.pop();
        }
        cout << endl;
        return d[end];
    }


int main()
{
    int start, end;

    cin >> n ;
    int a, b;
    double c;
    for(int i = 0; i < n; i++)
    {
        cin >>a>>b;
        edges.push_back({a,b});
    }
    for(int i = 0; i < n; i++)
    {
        cin >> c;
        succ.push_back(c);
    }
    cin >> start >> end;
    double ans = maxProbability(n, edges,succ, start, end);
    cout << "succProb is " <<  ans << endl;
    system("pause");
}

    
