#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

class Node {
    public:
        int data;
        Node *left,*right;
        Node(int d) {
            data=d;
            left=right=NULL;
        }
};

class Solution {
    public:
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur=insert(root->left, data);
                    root->left = cur;
                } else {
                   cur=insert(root->right, data);
                   root->right = cur;
                }
                return root;
            }
        }

        void levelOrder(Node* root) {
            if(root != NULL) {
                queue<Node*> q;
                q.push(root);
                
                while(!q.empty()) {
                    // access and remove pattern
                    Node* currentNode = q.front(); q.pop();
    
                    // visiting the node is defined as
                    // printing or performing other 
                    // operations on the data. In this
                    // case we just print the data
                    cout << currentNode->data << ' ';
                    
                    // now enqueue children, left-2-right
                    if(currentNode->left != NULL) q.push(currentNode->left);
                    if(currentNode->right != NULL) q.push(currentNode->right);
                }
            }
        }
};//End of Solution

int main() {
    Solution myTree;
    Node* root=NULL;
    int T,data; cin>>T;

    while(T-- > 0) {
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}
