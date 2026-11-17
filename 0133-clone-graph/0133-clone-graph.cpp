class Solution {
    Node* dfs(Node* node, unordered_map<Node*, Node*>& clones) {
        if (clones.count(node)) {
            return clones[node];
        }

        Node* copy = new Node(node->val);
        clones[node] = copy;

        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(dfs(neighbor, clones));
        }

        return copy;
    }

public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<Node*, Node*> clones;
        return dfs(node, clones);
    }
};