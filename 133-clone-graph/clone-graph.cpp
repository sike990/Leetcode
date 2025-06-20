/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)return node;
        Node* ans = new Node(1);
        
        queue<pair<Node*,Node*>> q;
        //Node* temp = node;
        q.push({node, ans});
        unordered_map<Node* , Node*> vis;
        vis[node] = ans;
        while(!q.empty()){
            pair<Node*,Node*> topel = q.front();
            q.pop();
            Node* firstel = topel.first;
            Node* secel = topel.second;
            for(Node* v : firstel -> neighbors){
                Node* temp2 =  (vis.find(v) == vis.end())?new Node(v -> val):vis[v];
                if(vis.find(v) == vis.end()){
                    vis[v] = temp2;
                    q.push({v,temp2});
                }
                
               secel->neighbors.push_back(temp2);
               
            }
        }

        return ans;
        
    }

};