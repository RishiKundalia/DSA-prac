#include <iostream>
#include <queue>

using namespace std;

struct Node {
    char name;
    int data;
    Node* left;
    Node* right;
};

//Create a new node
Node* createNode(int data, char name) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

//Insert a node
Node* insert(Node* root, int data, char name) {
    if (root == nullptr) {
        return createNode(data, name);
    }

    if (data < root->data) {
        root->left = insert(root->left, data, name);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data, name);
    }
    else {
        cout << "Duplicate entry! " << data << " already exists.\n";
    }

    return root;
}

//Find the minimum node in a tree
Node* findMin(Node* root) {
    Node* current = root;

    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }

    return current;
}

//Delete a node
Node* deleteNode(Node* root, int data) {
    if (root == nullptr) {
        cout << "Node not found.\n";
        return nullptr;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // Case 1: No child (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: Only right child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: Only left child
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 4: Two children
        Node* temp = findMin(root->right);

        root->data = temp->data;
        root->name = temp->name;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

//Search for a node
Node* search(Node* root, int data) {
    if (root == nullptr || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}

//Display tree using traversals

// Inorder
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << "(" << root->name << ") ";
        inorder(root->right);
    }
}

// Preorder
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << "(" << root->name << ") ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder 
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "(" << root->name << ") ";
    }
}

//Display depth of tree
int depth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

// Create mirror image
Node* mirror(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* newRoot = createNode(root->data, root->name);

    newRoot->left = mirror(root->right);
    newRoot->right = mirror(root->left);

    return newRoot;
}

// Create a copy of tree
Node* copyTree(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* newRoot = createNode(root->data, root->name);

    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);

    return newRoot;
}

// Display all parent nodes with their children
void displayParents(Node* root) {
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr || root->right != nullptr) {
        cout << "Parent " << root->data << "(" << root->name << ") -> ";

        if (root->left != nullptr) {
            cout << "Left Child: "
                 << root->left->data << "(" << root->left->name << ") ";
        }

        if (root->right != nullptr) {
            cout << "Right Child: "
                 << root->right->data << "(" << root->right->name << ") ";
        }

        cout << endl;
    }

    displayParents(root->left);
    displayParents(root->right);
}

// Display leaf nodes
void displayLeaves(Node* root) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << "(" << root->name << ") ";
        return;
    }

    displayLeaves(root->left);
    displayLeaves(root->right);
}

// Display tree level wise
void levelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        while (levelSize--) {
            Node* current = q.front();
            q.pop();

            cout << current->data << "(" << current->name << ") ";

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        cout << endl;
    }
}

// Display a tree using all three traversals
void displayTree(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    cout << "Inorder:   ";
    inorder(root);
    cout << endl;

    cout << "Preorder:  ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;
}

int main() {
    Node* root = nullptr;
    Node* copiedTree = nullptr;
    Node* mirrorTree = nullptr;

    int choice;
    int data;
    char name;

    do {
        cout << "\n========== BINARY SEARCH TREE ==========\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display Tree (Traversal)\n";
        cout << "5. Display Depth of Tree\n";
        cout << "6. Display Mirror Image\n";
        cout << "7. Create a Copy\n";
        cout << "8. Display Parent Nodes with Children\n";
        cout << "9. Display Leaf Nodes\n";
        cout << "10. Display Tree Level Wise\n";
        cout << "0. Exit\n";
        cout << "=========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter data: ";
                cin >> data;

                cout << "Enter name (single character): ";
                cin >> name;

                root = insert(root, data, name);
                break;

            case 2:
                cout << "Enter data to delete: ";
                cin >> data;

                if (search(root, data) != nullptr) {
                    root = deleteNode(root, data);
                    cout << "Node deleted successfully.\n";
                }
                else {
                    cout << "Node not found.\n";
                }
                break;

            case 3:
                cout << "Enter data to search: ";
                cin >> data;

                if (search(root, data) != nullptr) {
                    cout << "Node found.\n";
                }
                else {
                    cout << "Node not found.\n";
                }
                break;

            case 4:
                displayTree(root);
                break;

            case 5:
                cout << "Depth of tree: " << depth(root) << endl;
                break;

            case 6:
                if (root == nullptr) {
                    cout << "Tree is empty.\n";
                }
                else {
                    mirrorTree = mirror(root);

                    cout << "Mirror Image:\n";
                    displayTree(mirrorTree);
                }
                break;

            case 7:
                copiedTree = copyTree(root);

                cout << "Copy created successfully.\n";
                cout << "Copied Tree:\n";
                displayTree(copiedTree);
                break;

            case 8:
                if (root == nullptr) {
                    cout << "Tree is empty.\n";
                }
                else {
                    cout << "Parent nodes with their children:\n";
                    displayParents(root);
                }
                break;

            case 9:
                if (root == nullptr) {
                    cout << "Tree is empty.\n";
                }
                else {
                    cout << "Leaf nodes: ";
                    displayLeaves(root);
                    cout << endl;
                }
                break;

            case 10:
                if (root == nullptr) {
                    cout << "Tree is empty.\n";
                }
                else {
                    cout << "Level-wise tree:\n";
                    levelOrder(root);
                }
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}