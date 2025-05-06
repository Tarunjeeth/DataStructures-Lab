#include <iostream>
#include <stdlib.h>
using namespace std;

class tree
{
    struct Node
    {
        struct Node *left;
        char data;
        struct Node *right;
    } *root;
    char postfix[100];
    public:
        tree()
        {
            root = NULL;
        }
        void insertion();
        void inorder(Node*);
        void preorder(Node*);
        void postorder(Node*);
        void menu(int ch);
};
void tree::inorder(Node* root){
    if (root==NULL){
        return;
    }
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}

void tree::preorder(Node* root){
    if (root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void tree::postorder(Node* root){
    if (root==NULL){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}
void tree::insertion()
{
    int i=0;
    stack <Node *> st;
    while (postfix[i]!='\0'){
        if (postfix[i]=='*' || postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='/'){
            struct Node* newnode=new Node();
            root=newnode;
            newnode->data=postfix[i];
            newnode->right=st.top();
            st.pop();
            newnode->left=st.top();
            st.pop();
        }else{
            Node* newnode=new Node();
            newnode->data=postfix[i];
            newnode->left=NULL;
            newnode->right=NULL;
            st.push(newnode);
        }
        i++;
    }
    if (!st.empty()) {
        root = st.top();
        st.pop();
    }
}
void tree::menu(int ch){
    int data;
    if (ch==1){
        cout<<"\nEnter postfix expression: ";
        cin>>postfix;
    }
    if(ch==2){
        insertion();
    }
    if (ch==3){
        preorder(root);
    }
    if (ch==4){
        postorder(root);
    }
    if (ch==5){
        inorder(root);
    }
}

int main(){
    class tree tr1;
    int choice;
    char data;
    while (1)
    {
        cout << "\n1. PostFixExpression\n2. Construct expression Tree\n3. Pre Order\n4. Post Order\n5. In Order\n6.Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if(choice==6){
            break;
        }
        tr1.menu(choice);
    }   
}