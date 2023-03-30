#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <string.h>
#include <locale.h>
#include <cstdlib>

struct Tel
{
	char Fio[80];
	long number;
};
struct Node
{
	Tel t;
	Node *next;
};


Node* first(void)
{
	Node* pv=new Node;
	cout<<"¬ведите данные";
	In(pv->t);
    pv->next=0;
    return pv;
}


Node* add(Node *pEnd)
{
	Node *pv=new Node;
	cout<<"¬ведите инфо-поле";
    In(pv->t);
    pv->next=0;
    pEnd->next=pv;
    return pv;

}

void print(Node* pBegin){
    Node* pv; 
    for(pv=pBegin;pv!=0;pv=pv->next){
        Out(pv->t);
    }
}

int main(void){
    Node *pBegin=0,*pEnd=0;
    pBegin=pEnd=first();
    cout<<"—колько элементов добавить?";
    int n;
    cin>> n;
    for (int i = 0; i<n ; i++){
        pEnd=add(pEnd);
    cout<<"¬аш список:\n";

    }
}
