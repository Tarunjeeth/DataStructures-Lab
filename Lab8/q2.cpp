#include <iostream>
#include <queue>
using namespace std;

class tree
{
    struct Node
    {
        struct Node *left;
        char data;
        struct Node *right;
    } *root;

public:
    tree()
    {
        root = NULL;
    }
    void insertion(char);
    void traverse_lvl();
    void preorder1();
    void preorder(Node *);
    void postorder1();
    void postorder(Node *);
    void inorder1();
    void inorder(Node *);
    int search(char);
    Node *lvl_ins()
    {
        if (root == NULL)
        {
            return NULL;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            else
            {
                return (temp);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            else
            {
                return (temp);
            }
            q.pop();
        }
    };
};

void tree::insertion(char ele)
{
    Node *temp = lvl_ins();
    Node *newnode = new Node;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = ele;
    if (temp == NULL)
    {
        root = newnode;
    }
    else
    {
        if (temp->left == NULL)
        {
            temp->left = newnode;
        }
        else
        {
            temp->right = newnode;
        }
    }
    cout<<"\nData inserted in the tree successfully"<<endl;
}

void tree::preorder1(){
    preorder(root);
}

void tree::preorder(Node *root){
    if (root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void tree::inorder1(){
    inorder(root);
}

void tree::inorder(Node *root){
    if (root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void tree::postorder1(){
    postorder(root);
}

void tree::postorder(Node *root){
    if (root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


void tree::traverse_lvl()
{
    if (root == NULL)
    {
        cout << "\nNo Tree" << endl;
    }
    else
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            q.pop();
        }
    }
}

int tree::search(char data){
    int bool1=0;
    if (root == NULL)
    {
        cout << "\nNo Tree" << endl;
        return bool1;
    }
    else
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            if(temp->data==data){
                bool1=1;
                return bool1;
                break;
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            q.pop();
        }
        return bool1;
    }
}

int main()
{
    class tree tr1;
    int choice;
    char data;
    while (1)
    {
        cout << "\n1. Insert values\n2. Level Order\n3. Pre Order\n4. Post Order\n5. In Order\n6. Search\n7.Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "\nEnter data to be inserted: ";
            cin >> data;
            tr1.insertion(data);
        }
        else if (choice == 2)
        {
            tr1.traverse_lvl();
        }
        else if(choice==3){
            tr1.preorder1();
        }
        else if(choice==4){
            tr1.postorder1();
        }
        else if(choice==5){
            tr1.inorder1();
        }
        else if(choice==6){
            cout<<"\nEnter data to be searched in the tree: ";
            cin>>data;
            int bool1=tr1.search(data);
            if(bool1==1){
                cout<<"\nElement is present";
            }else{
                cout<<"\nElement is not present";
            }
        }
        else{
            break;
        }
    }
}