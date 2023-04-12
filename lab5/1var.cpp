//Удалить список
void delList(Node *pBegin){
    Node *pv=pBegin;
    while(pv!=0){
		pBegin = pBegin->Next;
		delete(pv);
		pv = pBegin;
	}

}

//Вставка в конец
void pBeginAdd2(Node* pBegin){
    Node* pv1=pBegin;
    Node* pv2 = new Node;
    bool flag = 0;              //флаг чтобы нормально закончить цикл
    while (!flag){              //циклом ищем индекс pEnd 
        if (pv1->Next==0){      //когда нашли ячейку, у которой следующий = 0, т.е. последнюю, то делаем вставку - те же действия, что и в Node add()
            pv1->Next=pv2;
            pv2->Next=0;
            pv2->Prev=pv1;
            cout<<"Заполните данные о товаре: "<<endl;
            setProd(pv2->P);
            flag = 1;
        }
        pv1=pv1->Next;
    }
}

//Вставка в конец с использованием Node add() - как надо
void pBeginAdd(Node* pBegin){
    Node* pv1=pBegin;
    Node* pv2 = new Node;
    bool flag = 0;              //флаг чтобы нормально закончить цикл
    while (!flag){              //циклом ищем индекс pEnd 
        if (pv1->Next==0){      //когда нашли ячейку, у которой следующий = 0, т.е. последнюю, то делаем вставку - вызываем Node add() с найденным pEnd
            add(pv1);
            flag = 1;
        }
        pv1=pv1->Next;
    }
}