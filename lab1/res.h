
//������������ ���-������� rs ������ l �� ����� �� n �� �����
template <typename Type>
void res(Type x[],int l, int n, Type rs[]){
    for (int i=l-n; i<l;i++){
        rs[i-(l-n)]=x[i];
    }
}