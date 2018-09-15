#include <iostream>
#include <cstddef>

using namespace std;	

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
        
        int getHeight(Node* root) {
          //Write your code here
            if(root == NULL) {
                // when leaf node reached return -1
                // b/c latter we'll take max(left,righ)+1
                // +1 would make our leaf node 
                // height to be 1, which is not corret
                // and -1 would make it 0 w/i corret!
                return -1;
            }
            
            int heightLeft = getHeight(root->left);
            int heightRight = getHeight(root->right);
            
            return (heightLeft > heightRight ? heightLeft : heightRight) + 1;
        }
}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0) {
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;

    return 0;
}
