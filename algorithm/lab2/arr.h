#ifndef ARR_H
#define ARR_H

template<typename T>
class arr{
        int size;
        T *a;
    public:
        arr();
        arr(int n);
        arr(const arr &A);
        ~arr(){delete a;}

        void setS(int S);                    //������ �����
        int getS();                          //������� �����
        void fill();                         //���� � ����������
        void fillR(int n1, int n2);          //��������� � ���������
        void fillU();                        //�������������
        void fillUr();                       //������������� � �������� �������
        void get();                          //����� �� �����
        void get_file(ofstream &fin);        //����� � �����
        void mergeSort();                    //���������� ������ ��������
        void polyphaseMergeSort();           //����������� ����������
};
#endif //ARR_H