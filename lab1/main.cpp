#include "aeroflot.cpp"

int main(void){
    system("chcp 1251");
    bool f = true, M = false;
    int sw,n;
    aeroflot* A;
    
    while (f){
        cout<<"*������� ����*\n"
        <<"1) ������� ������\n"
        <<"2) ������ �������\n"
        <<"3) ����� �������\n"
        <<"4) ���������� �������\n"
        <<"5) �������\n"
        <<"6) ������ � �������\n"
        <<"0) ��������� ������ � ����������\n";
        cin>>sw;
        switch (sw){
            case 1:{//�������� �������
                cout<<"������� ����� �������: ";
                cin>>n;
                M = true;
                A = new aeroflot[n];
                break;
            }
            case 2:{//������
                if (!M){
                        cout<<"������ �� ������!\n";
                    }
                    else{
                        setMA(A,n);
                        break;
                    }
            }
            case 3:{//������
                if (!M){
                    cout<<"������ �� ������!\n";
                }
                else{
                    cout<<"������ ������� "<<n<<" ���������:\n";
                    getMA(A,n);
                    system("pause");
                }
                break;
            }
            case 4:{//����������
                if (!M){
                    cout<<"������ �� ������!\n";
                }
                else{
                    SORTer(A,n);
                    cout<<"������ ������������ �� ������� ������.\n";
                }
                break;
            }
            case 5:{//�������
                cout<<"1) ������� �� ������ ����������\n"
                <<"2) ������� �� ����\n"
                <<"3) ������� �� ���������� �������\n";
                int sw2;
                cin>>sw2;
                switch (sw2){
                    case 1:{
                        cout<<"������� ����� ����������: ";
                        char inp[20];
                        cin>>inp;
                        DEST(A,n,inp);
                        break;
                    }
                    case 2:{
                        cout<<"������� ���: ";
                        char inp[20];
                        cin>>inp;
                        TYPE(A,n,inp);
                        break;
                    }
                    case 3:{
                        cout<<"������� ���� ������, ����� �� � ��:  ";
                        char inp[20];
                        int t1,t2;
                        cin>>inp>>t1>>t2;
                        TIME(A,n,inp,t1,t2);
                        break;
                    }
                    sw2 = 0;
                }
                break;
            }
            case 6:{//����
                if (!M){
                        cout<<"������ �� ������!\n";
                    }
                else{
                    cout<<"1) ������ �� �����\n"
                    <<"2) ������ � ����\n";
                    int sw3;
                    cin>>sw3;
                    switch (sw3){
                        case 1:{
                            cout<<"������� ��� �����: ";
                            string F;
                            cin>>F;
                            if (F == "1"){F = "test.txt";}
                            ifstream fin(F);
                            if (!fin.is_open()){
                                cout << "������ �������� ����� �����!" << endl;
                            }
                            else
                            {
                                cout << "���� ������." << endl;
                                importA(fin,A,n);
                                fin.close();
                            }
                            break;
                        }
                        case 2:{
                            cout<<"������� ��� �����: ";
                            char F[20];
                            cin>>F;
                            ofstream fout(F);
                            if (!fout.is_open())
                            {
                                cout << "������ �������� ����� �����!" << endl;
                            }
                            else
                            {
                                cout << "���� ������." << endl;
                                exportA(fout,A,n);
                                fout.close();
                            }
                            break;
                        }
                        sw3 = 0;
                    }
                }
                break;
            }
            case 0:{//�����
                f = false;
                break;
            }
            sw = 0;
        }
    }
}