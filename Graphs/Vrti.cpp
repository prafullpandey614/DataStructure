class Solution {

public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

         vector<int> res, visited(n);

        // mark the node which can be visited by e 

        for (auto& e: edges)

            visited[e[1]] = 1;

        // push the node which are not visited because we will need those nodes to traverse the whole graph

        for (int i = 0; i < n; ++i)

            if (visited[i] == 0)

                res.push_back(i);

                

        return res;

        

    }

};
