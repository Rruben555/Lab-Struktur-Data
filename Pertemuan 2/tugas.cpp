#include <iostream>
using namespace std;

//Node untuk linked list
struct Node {
    int value;
    Node* next;
};

//Pointer ke top stack
Node* top=NULL;

//Fungsi push
void push(int n){
    Node* newNode=new Node();
    newNode->value=n;
    newNode->next=top;
    top=newNode;
    cout<<n<<" berhasil di-push ke stack."<<endl;
}

//Fungsi pop
void pop(){
    if (top==NULL) {
        cout<<"Stack kosong!"<<endl;
        return;
    }
    Node* temp=top;
    cout<<"Elemen "<<top->value<<" di-pop dari stack."<<endl;
    top=top->next;
    delete temp;
    //pop top
}

//Fungsi display
void printList(){
    if (top==NULL) {
        cout<<"Stack kosong."<<endl;
        return;
    }
    cout<<"Isi stack: ";
    Node* temp=top;
    while(temp!=NULL){
        cout<<temp->value<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int main(){
    system("cls");
    //Push 3 angka
    push(10);
    push(20);
    push(30);

    printList();

    //Pop 1 angka
    pop();

    printList();

    return 0;
}
