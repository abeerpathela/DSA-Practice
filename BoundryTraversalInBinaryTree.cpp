// Boundry Traversal of binary tree 

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    Node* root = new Node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void leftBoundry(Node* root, vector<int>& ans) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    ans.push_back(root->data);

    if (root->left)
        leftBoundry(root->left, ans);
    else
        leftBoundry(root->right, ans);
}

void leafNodes(Node* root, vector<int>& ans) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }

    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
}

void rightBoundry(Node* root, vector<int>& ans) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    if (root->right)
        rightBoundry(root->right, ans);
    else
        rightBoundry(root->left, ans);

    ans.push_back(root->data);
}

vector<int> boundryTraversal(Node* root) {
    vector<int> ans;

    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    leftBoundry(root->left, ans);

    leafNodes(root->left, ans);
    leafNodes(root->right, ans);

    rightBoundry(root->right, ans);

    return ans;
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL):\n";

    Node* root = buildTree();

    vector<int> ans = boundryTraversal(root);

    cout << "\nBoundary Traversal: ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}