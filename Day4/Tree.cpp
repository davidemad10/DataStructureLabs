#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node * Right;
    Node * Left;
    Node(int _data){
        data=_data;
        Right=Left=NULL;
    }
};
class Tree{
    private:
    Node * root;
    Node * getNodeByData(int data){
        Node * current =root;
        while(current != NULL ){
            if(data == current->data){
                return current;
            }else if(data > current->data){
                current=current->Right;
            }else{
                current=current->Left;
            }
        }
        return NULL;

    }
    Node * getParent(Node * node){
        Node * parent=root;
        while(parent != NULL){
            if(node == parent->Right ||node == parent->Left  ){
                return parent;
            }else if(node->data > parent->data){
                parent=parent->Right;
            }else{
                parent=parent->Left;
            }
        }
        return NULL;

    }

    Node * getMaxRight(Node * node){
        Node * current=node;//Start Point
        while(current->Right != NULL){
            current=current->Right;
        }
        return current;
    }
    
    void display(Node *node){
        if(node == NULL){
            return ;
        }
        display(node->Left);
        cout<<node->data<<" : ";
        display(node->Right);


    }


    public:
    Tree(){
        root=NULL;
    }
    void add(int data){
        //Create Node
        Node * newNode=new Node(data);
        if(root == NULL){
            root=newNode;
        }
        else{
            Node * current = root;
            Node * parent = NULL;
            while(current != NULL){
                parent=current; //Before Current Jumping
                if(data > current->data){
                    current=current->Right;
                }else{
                    current=current->Left;
                }
            }
            if(data>parent->data){
               parent->Right=newNode;
            }else{
                parent->Left=newNode;
            }

        }
    }
    int findDataInTree(int data){
        if(getNodeByData(data)== NULL){
            return 0;
        }
            return 1;
    }
    int getParentBydata(int data){
        Node * node = getNodeByData(data);
        if(node == root){
            throw "The Node is Root Not Have Parent";
        }
        if(node != NULL ){
            Node * parent=getParent(node);
            if(parent != NULL){
                return parent->data;
            }
        }else{
            throw " Node Not Found , Not Have Parent";
        }

    }
    void remove(int data){
        Node * node = getNodeByData(data);
        if (!node) throw "Node not found.";
        if (node == root){
            if (node -> Right == NULL && node -> Left == NULL) root = NULL;
            else if (node -> Right != NULL && node -> Left != NULL){
                node = node -> Left;
                node = getMaxRight(node);
                Node * parent = getParent(node);
                parent -> Right = node -> Left;
                node -> Right = root -> Right;
                node -> Left = root -> Left;
                parent = root;
                root = node;
                node = parent;

            }
            else if (node -> Right !=NULL) root = root -> Right ;
            else root = root -> Left;

        }else{
            Node * parent = getParent(node);
            if (node -> Right != NULL && node -> Left != NULL){
                Node * lNode = getMaxRight(node -> Left);
                lNode -> Right = node -> Right;
                if (node -> data > parent -> data) parent -> Right = node ->Left;
                else parent -> Left = node ->Left;
            }
            else if (node -> Right !=NULL && node -> Left == NULL){
                if (node -> data > parent -> data) parent -> Right = node ->Right;
                else parent -> Left = node ->Right;}
            else if(node -> Right ==NULL && node -> Left != NULL){
                if (node -> data > parent -> data) parent -> Right = node ->Left;
                else parent -> Left = node ->Left;}
            else{
                if (node -> data > parent -> data) parent -> Right = NULL;
                else parent -> Left = NULL;}

        }
        delete node;
    }


    int max(){
        Node * current=root;
        if (!current) throw "Empty Tree.";
        while(current->Right != NULL){
            current=current->Right;
        }
        return current -> data;
    }

    int min(){
        Node * current=root;
        if (!current) throw "Empty Tree.";
        while(current->Left != NULL){
            current=current->Left;
        }
        return current -> data;
    }

    void displayAll(){
        display(root);
    }
};

int main()
{
    Tree t;
    t.add(50);
    t.add(40);
    t.add(70);
    t.add(30);
    t.add(65);
    t.add(60);
    t.add(35);
    t.add(42);
    t.add(45);
    t.add(48);
    t.add(25);
    t.add(22);

    try{
        //t.getParentBydata(50);
        cout<<"Parent : "<<t.getParentBydata(35)<<endl;
    }catch(const char * msg){
        cout<<msg;
    }
    t.displayAll();
    cout<<endl;
    //t.remove(40);
    //t.remove(50);
    //t.remove(48);
    try{
        t.remove(89);
    }catch(const char * e){
        cout << e << endl;
    };
    t.displayAll();
    cout<<endl;
    cout<< " Maximum : "<< t.max()<<endl;
    cout<< " Minimum : "<< t.min()<<endl;

    return 0;
}
