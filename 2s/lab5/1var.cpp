//������� ������
void delList(Node *pBegin){
    Node *pv=pBegin;
    while(pv!=0){
		pBegin = pBegin->Next;
		delete(pv);
		pv = pBegin;
	}

}

//������� � �����
void pBeginAdd2(Node* pBegin){
    Node* pv1=pBegin;
    Node* pv2 = new Node;
    bool flag = 0;              //���� ����� ��������� ��������� ����
    while (!flag){              //������ ���� ������ pEnd 
        if (pv1->Next==0){      //����� ����� ������, � ������� ��������� = 0, �.�. ���������, �� ������ ������� - �� �� ��������, ��� � � Node add()
            pv1->Next=pv2;
            pv2->Next=0;
            pv2->Prev=pv1;
            cout<<"��������� ������ � ������: "<<endl;
            setProd(pv2->P);
            flag = 1;
        }
        pv1=pv1->Next;
    }
}

//������� � ����� � �������������� Node add() - ��� ����
void pBeginAdd(Node* pBegin){
    Node* pv1=pBegin;
    Node* pv2 = new Node;
    bool flag = 0;              //���� ����� ��������� ��������� ����
    while (!flag){              //������ ���� ������ pEnd 
        if (pv1->Next==0){      //����� ����� ������, � ������� ��������� = 0, �.�. ���������, �� ������ ������� - �������� Node add() � ��������� pEnd
            add(pv1);
            flag = 1;
        }
        pv1=pv1->Next;
    }
}