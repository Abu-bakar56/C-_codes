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
int main()
{
    // creating the node in for tree
    node *p = createnode(5);
    node *p1 = createnode(2);
    node *p2 = createnode(3);
    node *p3 = createnode(45);
    node *p4 = createnode(77);
    node *p5 = createnode(1);
    node *p6 = createnode(66);

    // linking node in tree
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    // tree look like this
    //         5
    //      /    \
    //     2       3
    //    / \     / \
    //   45  77  1  66

    // call the preoder function which this
    // 5 2 45 77 3 1 66
    cout<<" preoder tevarsel of tree"<<endl;
    preorder(p);
    cout<<endl;
    // call the postoder function which this
    // 45 77 2 1 66 3 5
    cout<<" postorder tevarsel of tree "<<endl;
    postorder(p);
    cout<<endl;
    // call the inoder function which this
    // 45 2 77 5 1 3 66
    cout<<" inoder tevarsel of tree"<<endl;
    inorder(p);
    return 0;
}