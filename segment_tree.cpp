#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    struct Node {
        int data;
        int startInterval;
        int endInterval;
        Node* left;
        Node* right;

        Node(int start, int end) : startInterval(start), endInterval(end), data(0), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* constructTree(const vector<int>& arr, int start, int end) {
        if (start == end) {
            Node* leaf = new Node(start, end);
            leaf->data = arr[start];
            return leaf;
        }

        Node* node = new Node(start, end);
        int mid = (start + end) / 2;

        node->left = constructTree(arr, start, mid);
        node->right = constructTree(arr, mid + 1, end);
        
        node->data = node->left->data + node->right->data;
        return node;
    }

    void display(Node* node) {
        if (!node) return;

        string str = "";
        if (node->left) {
            str += "Interval=[" + to_string(node->left->startInterval) + "-" + to_string(node->left->endInterval) + "] and data: " + to_string(node->left->data) + " => ";
        } else {
            str += "No left child ";
        }

        str += "Interval=[" + to_string(node->startInterval) + "-" + to_string(node->endInterval) + "] and data: " + to_string(node->data) + " <= ";
        
        if (node->right) {
            str += "Interval=[" + to_string(node->right->startInterval) + "-" + to_string(node->right->endInterval) + "] and data: " + to_string(node->right->data);
        } else {
            str += "No right child";
        }

        cout << str << endl;
        display(node->left);
        display(node->right);
    }

    int query(Node* node, int qsi, int qei) {
        if (node->startInterval >= qsi && node->endInterval <= qei) {
            return node->data;
        } else if (node->startInterval > qei || node->endInterval < qsi) {
            return 0;
        } else {
            return query(node->left, qsi, qei) + query(node->right, qsi, qei);
        }
    }

    int update(Node* node, int index, int value) {
        if (index >= node->startInterval && index <= node->endInterval) {
            if (index == node->startInterval && index == node->endInterval) {
                node->data = value;
                return node->data;
            } else {
                int leftAns = update(node->left, index, value);
                int rightAns = update(node->right, index, value);
                node->data = leftAns + rightAns;
                return node->data;
            }
        }
        return node->data;
    }

public:
    SegmentTree(const vector<int>& arr) {
        root = constructTree(arr, 0, arr.size() - 1);
    }

    void display() {
        display(root);
    }

    int query(int qsi, int qei) {
        return query(root, qsi, qei);
    }

    void update(int index, int value) {
        root->data = update(root, index, value);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);
    
    cout << "Segment Tree Display:\n";
    st.display();
    
    cout << "Query (1, 3): " << st.query(1, 3) << endl;
    st.update(2, 10);
    cout << "Updated value at index 2 to 10" << endl;
    cout << "Query (1, 3): " << st.query(1, 3) << endl;
    return 0;
}
