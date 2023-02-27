
//формирование рес-массива rs длинны l по срезу от n до конца
template <typename Type>
void res(Type x[],int l, int n, Type rs[]){
    for (int i=l-n; i<l;i++){
        rs[i-(l-n)]=x[i];
    }
}