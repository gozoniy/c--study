#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
class array{
        int size;
        T *arr;
    public:
        array();
        array(int n);
        array(const array &A);
        ~array(){delete arr;}

        void setS(int S);                    //������ �����
        int getS();                          //������� �����
        void fill();                         //���� � ����������
        void fillR(int n1, int n2);          //��������� � ���������
        void fillU();                        //�������������
        void fillUr();                       //������������� � �������� �������
        void get();                          //����� �� �����
        void get_file(ofstream &fin);        //����� � �����
        void shakerSort();                   //���������� ������� ������� ��������
        void insertSort();                   //���������� ������� ������� �����������
};
#endif //ARRAY_H