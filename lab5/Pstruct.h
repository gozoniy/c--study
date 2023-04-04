//Структура одной связяи двусвязного списка
struct Node
{
    product P;
    Node *Next;
    Node *Prev;

};

//Задание первого элемента списка
Node* first(void){
    Node* pv = new Node;
    cout<<"Заполните данные о товаре: "<<endl;
    setProduct(pv->P);
    pv->Next=0;
    pv->Prev=0;
    return pv;
}

//Добавление элемента в конец списка
Node* add(Node* pEnd){
    Node* pv = new Node;
	cout<<"Заполните данные о товаре: "<<endl;
    setProduct(pv->P);
    pv->Next=0;
    pv->Prev=pEnd;
    pEnd->Next=pv;
    return pv;
}

//Вывод списка
void print(Node* pBegin){
    Node* pv=pBegin;
    for(pv=pBegin;pv!=0;pv=pv->Next){
        readProduct(pv->P);
    }
}

//Вывод списка наоборот
void backwardPrint(Node* pEnd){
    Node* pv;
	for(pv=pEnd;pv!=0;pv=pv->Prev){
		readProduct(pv->P);
    }
}

//Удалить список
void delList(Node *pBegin){
    Node *pv=pBegin;
    while(pv!=NULL)
	{
		pBegin = pBegin->Next;
		delete(pv);
		pv = pBegin;
	}

}

