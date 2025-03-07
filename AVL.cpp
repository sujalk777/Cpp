#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// class is private by default and struct is public
class AVL {
public:
    struct Node {
        int value;
        Node* left;
        Node* right;
        int height;

        Node(int value) : value(value), left(nullptr), right(nullptr), height(0) {}
    };

private:
    Node* root;

    int height(Node* node) {
        if (node == nullptr) {
            return -1;
        }
        return node->height;
    }

    Node* insert(int value, Node* node) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->value) {
            node->left = insert(value, node->left);
        } else if (value > node->value) {
            node->right = insert(value, node->right);
        }

        node->height = max(height(node->left), height(node->right)) + 1;
        return rotate(node);
    }

    Node* rotate(Node* node) {
        if (height(node->left) - height(node->right) > 1) {
            // left heavy
            if (height(node->left->left) - height(node->left->right) > 0) {
                // left left case
                return rightRotate(node);
            }
            if (height(node->left->left) - height(node->left->right) < 0) {
                // left right case
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }

        if (height(node->left) - height(node->right) < -1) {
            // right heavy
            if (height(node->right->left) - height(node->right->right) < 0) {
                // right right case
                return leftRotate(node);
            }
            if (height(node->right->left) - height(node->right->right) > 0) {
                // right left case
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

    Node* rightRotate(Node* p) {
        Node* c = p->left;
        Node* t = c->right;

        c->right = p;
        p->left = t;

        p->height = max(height(p->left), height(p->right)) + 1;
        c->height = max(height(c->left), height(c->right)) + 1;

        return c;
    }

    Node* leftRotate(Node* c) {
        Node* p = c->right;
        Node* t = p->left;

        p->left = c;
        c->right = t;

        p->height = max(height(p->left), height(p->right)) + 1;
        c->height = max(height(c->left), height(c->right)) + 1;

        return p;
    }

    void populatedSorted(const vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }

        int mid = (start + end) / 2;
        insert(nums[mid]);
        populatedSorted(nums, start, mid);
        populatedSorted(nums, mid + 1, end);
    }

    void display(Node* node, const string& details) {
        if (node == nullptr) {
            return;
        }
        cout << details << node->value << endl;
        display(node->left, "Left child of " + to_string(node->value) + " : ");
        display(node->right, "Right child of " + to_string(node->value) + " : ");
    }

    bool balanced(Node* node) {
        if (node == nullptr) {
            return true;
        }
        return abs(height(node->left) - height(node->right)) <= 1 && balanced(node->left) && balanced(node->right);
    }

public:
    AVL() : root(nullptr) {}

    int height() {
        return height(root);
    }

    void insert(int value) {
        root = insert(value, root);
    }

    void populate(const vector<int>& nums) {
        for (int num : nums) {
            insert(num);
        }
    }

    void populatedSorted(const vector<int>& nums) {
        populatedSorted(nums, 0, nums.size());
    }

    void display() {
        display(root, "Root Node: ");
    }

    bool isEmpty() {
        return root == nullptr;
    }

    bool balanced() {
        return balanced(root);
    }
};

int main() {
    AVL avl;
    vector<int> nums = {10, 20, 30, 40, 50, 25};
    avl.populate(nums);
    avl.display();
    cout << "Is balanced: " << (avl.balanced() ? "Yes" : "No") << endl;
    return 0;
}
