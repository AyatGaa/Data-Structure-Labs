#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    char data;
    Node* left;
    Node* right;
    Node()
    {
        data = ' ';
        left = right = NULL;
    }
    Node(char d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }


    void inOrder(Node* node) // left -> process -> right
    {
        if(node == NULL)
        {
            return;
        }
        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }

    void preOrder(Node* node) // process -> left -> right
    {
        if(node == NULL)
        {
            return;
        }
        cout<<node->data<<" ";
        preOrder(node->left);
        preOrder(node->right);


    }

    void postOrder(Node* node) // left-> right -> process
    {
        if(node == NULL)
        {
            return;
        }
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->data<<" ";
    }

    Node* insertNode(Node* root, char d)
    {
        if(root == NULL){
            root = new Node(d);
            return root;
        }
        else  if(d < root->data){ // left
            root->left = insertNode(root->left,d);
       }
       else
       {
            root->right = insertNode(root->right,d);
       }

     return root;
    }

};
int main()
{

   Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C') ;
    root->left->left = new Node('D');
  Node d;
    cout << "Inorder traversal before insertion: ";
    d.inOrder(root);
    cout << endl;

    root = d.insertNode(root, 'Z');
    root = d.insertNode(root, 'c');\
        root = d.insertNode(root, 'W');
    cout << "Inorder traversal after insertion: ";
    d.inOrder(root);
    cout << endl;

   /*
    //Build a tree
    Node* root = new Node('F');
    root->left = new Node('A');

    (root->left)->left =  new Node('E');
    (root->left)->right =  new Node('K');
    (root->left)->right->left =  new Node('C');
    root->right =  new Node('D');
    (root->right)->left =  new Node('H');
    (root->right)->right =  new Node('G');
    (root->right)->right ->right =  new Node('B');

    cout<<"Root = "<<root->data<<endl;
    Node d;
    cout<<"In-Order: \n";
    d.inOrder(root);
    cout<<endl;

    cout<<"Pre-Order: \n";
    d.preOrder(root);
    cout<<endl;
    cout<<"Post-Order: \n";
    d.postOrder(root);
    cout<<endl;
*/
    return 0;
}
