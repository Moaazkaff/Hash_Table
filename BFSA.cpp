#include<iostream>
#include<vector>
#include<queue>


using namespace std;

// BFS FOR CONNECTED GRAPH
// 1. Create a queue and push the starting vertex into it
// 2. Mark the starting vertex as visited
// 3. While the queue is not empty, do the following:
// 4. Pop the front element from the queue and print it
// 5. For each adjacent vertex of the popped element, if it is not visited, mark it as visited and push it into the queue
// 6. Repeat until the queue is empty
// 7. Return the final vector
// 8. The final vector will contain the BFS traversal of the graph
// 9. The BFS traversal will be in the order of the vertices visited

// vector<int> BFS(vector<vector<int>>& adj ,int start) //O(V + E)
// {
//     vector<bool> visited(adj.size() , false);
//     vector<int> final;
//     queue<int> q;
//     visited[start] = true;
//     q.push(start);

//     while (!q.empty())
//     {
//         int curr = q.front();
//         q.pop();
//         final.push_back(curr);

//         for(auto i: adj[curr])
//         {
//             if(!visited[i])
//             {
//                 visited[i] = true;
//                 q.push(i);
//             }
//         }
//     }
    
//     return final;
// }


// BFS FOR DISCONNECTED GRAPH
// 1. Traverse all the vertices of the graph
// 2. If the vertex is not visited, call BFS function on that vertex
// 3. Repeat until all vertices are visited
// 4. Return the final vector
// 5. The final vector will contain the BFS traversal of the graph
// 6. The BFS traversal will be in the order of the vertices visited

void bfs(vector<vector<int>>& adj ,int start ,vector<bool>& visited ,vector<int>& final) //O(V + E)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        final.push_back(curr);

        for(auto i: adj[curr])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    

}

vector<int> BFS(vector<vector<int>>& adj) //O(V + E)
{
    int v = adj.size();

    vector<bool> visited(v , false);

    vector<int> final;

    for(int i = 0;i < v;i++)
    {
        if(!visited[i])
        {
            bfs(adj , i , visited , final);
        }
    }
    return final;
}

int main()
{
    vector<vector<int>> adj = { {2, 3, 1}, {0},
                                {0, 4}, {0}, {2}};
    // vector<int> ans = BFS(adj , 0);
    vector<int> ans = BFS(adj);
    for(auto i: ans) 
    {
        cout<< i << " ";
    }
    cout << endl;

    return 0;
}