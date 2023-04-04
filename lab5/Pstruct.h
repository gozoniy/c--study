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

//�������� �� ��������� ����
void delP(Node* pBegin){
    Node* pv=pBegin;
    char name1[20];
    cout<<"������� �������� ���� �����:\n";
    cin>>name1;
    int i=0;
    Node *pv1, *pv2;
    for(pv=pBegin;pv!=0;pv=pv->Next){
        i++;
        if (!strcmp(pv->P.name,name1)){
            if ((pv->Prev==0)||(pv->Next==0)){
                return;
            }
            pv1=pv->Prev;
            pv2=pv->Next;
            pv1->Next=pv2;
            pv2->Prev=pv1;
            delete(pv);
            cout<<"������� "<<i<<" ������."<<endl;
            break;


        

        }
    }
}