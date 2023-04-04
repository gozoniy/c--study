//��������� ����� ������ ����������� ������
struct Node
{
    product P;
    Node *Next;
    Node *Prev;

};

//������� ������� �������� ������
Node* first(void){
    Node* pv = new Node;
    cout<<"��������� ������ � ������: "<<endl;
    setProduct(pv->P);
    pv->Next=0;
    pv->Prev=0;
    return pv;
}

//���������� �������� � ����� ������
Node* add(Node* pEnd){
    Node* pv = new Node;
	cout<<"��������� ������ � ������: "<<endl;
    setProduct(pv->P);
    pv->Next=0;
    pv->Prev=pEnd;
    pEnd->Next=pv;
    return pv;
}

//����� ������
void print(Node* pBegin){
    Node* pv=pBegin;
    for(pv=pBegin;pv!=0;pv=pv->Next){
        readProduct(pv->P);
    }
}

//����� ������ ��������
void backwardPrint(Node* pEnd){
    Node* pv;
	for(pv=pEnd;pv!=0;pv=pv->Prev){
		readProduct(pv->P);
    }
}

//������� ������
void delList(Node *pBegin){
    Node *pv=pBegin;
    while(pv!=NULL)
	{
		pBegin = pBegin->Next;
		delete(pv);
		pv = pBegin;
	}

}

