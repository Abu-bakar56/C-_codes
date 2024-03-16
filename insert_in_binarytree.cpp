#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *createnode(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}
void preorder(node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
void inorder(node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

bool isBST(node *root, node *&prev)
{

    if (root != NULL)
    {
        if (!isBST(root->left, prev))
        {
            return false;
        }
        if (prev != nullptr && root->data <= prev->data)
        {
            return false;
        }
        prev = root;
        return isBST(root->right, prev);
    }
    else
    {
        return true;
    }
}
node *search(node *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

node *searchiter(node *root, int key)
{
    while (root != nullptr)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return nullptr;
}
void insert(node *root, int key)
{
    node *prev = nullptr;
    while (root != nullptr)
    {
        prev = root;
        if (root->data == key)
        {
            cout << "number is duplicate so insertion is not possible" << endl;
            return ;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
        node *new1 = createnode(key);
        if (prev->data > key)
        {
            prev->left = new1;
        }
        else
        {
            prev->right = new1;
        }
    
}


int main()
{
    // creating the node in for tree
    node *p = createnode(50);
    node *p1 = createnode(40);
    node *p2 = createnode(60);
    node *p3 = createnode(35);
    node *p4 = createnode(45);
    node *p5 = createnode(55);
    node *p6 = createnode(65);

    // linking node in tree
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    // tree look like this
    //        50
    //      /    \
    //    40      60
    //    / \     / \
    //   35  45  55  65

    // call the preoder function which this
    // 50 40 35 45 60 55 65
    cout << " preoder tevarsel of tree" << endl;
    preorder(p);
    cout << endl;
    // call the postoder function which this
    // 35 45 40 55 65 60 50
    cout << " postorder tevarsel of tree " << endl;
    postorder(p);
    cout << endl;
    // call the inoder function which this
    // 35 40 45 50 55 60 65
    cout << " inoder tevarsel of tree" << endl;
    inorder(p);
    code for check tree is bst or not bst
    node *prev = nullptr;
    bool is_bst_result = isBST(p, prev);
    cout << endl;
    if (is_bst_result)
    {
        cout << " THIS TREE IS A BINARY SEARCH TREE" << endl;
    }
    else
    {
        cout << "THIS TREE IS NOT A BINATY SEARCH TREE " << endl;
    }
    // for search recursivly
    node *n = search(p, 45);
    if (n != nullptr)
    {
        cout << " search node  data is  " << n->data<<endl;
    }
    else
    {
        cout << "data is not " << endl;
    }

    // for search iterative
    node *m = searchiter(p, 50);
    if (m != nullptr)
    {
        cout << " search node  data is  " << n->data<<endl;
    }
    else
    {
        cout << "data is not " << endl;
    }
    cout << endl;
    insert(p, 43);
   cout<<p->left->right->left->data;
    return 0;
}
