//22 �������
/*�) ������ ������ ��� ��������� ������ ����������;
�) ������ ������ ��������� ���������� ����;
�) ������ ������ ��� ��������� ��� ������, ����� ������ ������� ��������� � �������� ���������.
*/ 
#include "aeroflot.cpp"


int main(void){
    system("chcp 1251");
    aeroflot A[2];
    importA("test.txt",A,2);
    getMA(A,2);
}