#include "aeroflot.cpp"

int main(void){
    system("chcp 1251");
    /*aeroflot A[3];
    importA("test.txt",A,3);
    bool F = A[0]<A[1];
    cout<<F;*/


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
                            importA(F,A,n);
                            break;
                        }
                        case 2:{
                            cout<<"������� ��� �����: ";
                            if (!M){
                                
                            }
                            char F[20];
                            cin>>F;
                            exportA(F,A,n);
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