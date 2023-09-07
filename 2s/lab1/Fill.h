
//заполнение массива X длинной l числами от -k до k
template <typename Type>
void fill(Type x[],int l, int k){
    srand(time(0));
    for (int i=0;i<l;i++){
        Type a=rand()%(k+1);
        if (rand()%2==1){
            a=-a;
        }
        x[i]=a;
    }

}