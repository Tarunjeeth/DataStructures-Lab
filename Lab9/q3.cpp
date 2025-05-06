#include <iostream>
#include <stdlib.h>
using namespace std;

class tree{
    struct Node{
        struct Node* left;
        int val;
        struct Node* right;
    }*root;
    public:
        tree(){
            root=NULL;
        }
        void menu(int ch);
        void inorder(Node*);
        void preorder(Node*);
        void postorder(Node*);
        Node* insert(Node* root,int data){
            if(root==NULL){
                Node* newnode=(struct Node*)malloc(sizeof(struct Node));
                newnode->left=NULL;
                newnode->right=NULL;
                newnode->val=data;
                root=newnode;
            }
            else if(root->val>=data){
                root->left=insert(root->left,data);
            }
            else{
                root->right=insert(root->right,data);
            }
            return root;
        }
        int search(int data){
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
                    if(temp->val==data){
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

};

void tree::inorder(Node* root){
    if (root==NULL){
        return;
    }
    preorder(root->left);
    cout<<root->val<<" ";
    preorder(root->right);
}

void tree::preorder(Node* root){
    if (root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void tree::postorder(Node* root){
    if (root==NULL){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->val<<" ";
}

void tree::menu(int ch){
    int data;
    if (ch==1){
        cout << "\nEnter data to be inserted: ";
        cin >> data;
        root=insert(root,data);
        cout<<"\nSuccess";
    }
    if (ch==2){
        preorder(root);
    }
    if (ch==3){
        postorder(root);
    }
    if (ch==4){
        inorder(root);
    }
    if(ch==5){
        cout<<"\nEnter data to be searched: ";
        cin>>data;
        int bool1=search(data);
        if (bool1){
            cout<<"\nElement is present"<<endl;
        }else{
            cout<<"\nElement is not present"<<endl;
        }
    }
}

int main(){
    class tree tr1;
    int choice;
    char data;
    while (1)
    {
        cout << "\n1. Insert values\n2. Pre Order\n3. Post Order\n4. In Order\n5. Search\n6.Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if(choice==6){
            break;
        }
        tr1.menu(choice);
    }   
}