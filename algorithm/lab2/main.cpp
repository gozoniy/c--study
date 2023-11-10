//21. сортировка прямыми обменами; сортировка прямыми включениями. 
#include <iostream>
#include <fstream>
using namespace std;

void fillR(int *A, int size, int n1, int n2){
    srand(time(0));
    for (int i = 0; i < size; i++){
        A[i] = n1 + rand()%(n2-n1+1);
    }
}
void get(int *A, int size){
    cout<<"Массив длинной "<<size<<":\n";
    for (int i = 0; i < size; i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}
void copy(int *A, int *B, int size){
    for (int i = 0; i<size; i++){
        B[i] = A[i];
    }
}
template<typename T>
void mergeSort(T a[], int l)
{
	int BlockSizeIterator;
	int BlockIterator;
	int LeftBlockIterator;
	int RightBlockIterator;
	int MergeIterator;

	int LeftBorder;
	int MidBorder;
	int RightBorder;
	for (BlockSizeIterator = 1; BlockSizeIterator < l; BlockSizeIterator *= 2)
	{
		for (BlockIterator = 0; BlockIterator < l - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
		{
			//Производим слияние с сортировкой пары блоков начинающуюся с элемента BlockIterator
			//левый размером BlockSizeIterator, правый размером BlockSizeIterator или меньше
			LeftBlockIterator = 0;
			RightBlockIterator = 0;
			LeftBorder = BlockIterator;
			MidBorder = BlockIterator + BlockSizeIterator;
			RightBorder = BlockIterator + 2 * BlockSizeIterator;
			RightBorder = (RightBorder < l) ? RightBorder : l;
			int* SortedBlock = new int[RightBorder - LeftBorder];

			//Пока в обоих массивах есть элементы выбираем меньший из них и заносим в отсортированный блок
			while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
			{
				if (a[LeftBorder + LeftBlockIterator] < a[MidBorder + RightBlockIterator])
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
					LeftBlockIterator += 1;
				}
				else
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
					RightBlockIterator += 1;
				}
			}
			//После этого заносим оставшиеся элементы из левого или правого блока
			while (LeftBorder + LeftBlockIterator < MidBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
				LeftBlockIterator += 1;
			}
			while (MidBorder + RightBlockIterator < RightBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
				RightBlockIterator += 1;
			}

			for (MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
			{
				a[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
			}
			delete SortedBlock;
		}
	}
}

void MergeS(int *A, int size, string buffer_filename_1, string buffer_filename_2, string buffer_filename_out){
    if (size <= 1){
        return;
    }
    if (size == 2){
        if (A[0]>A[1])
            swap(A[0], A[1]);
        return;
    }
    int n1 = size / 2;
    int *B = new int [n1];
    int *C = new int [size - n1];
    //Делим на два массива
    for (int i = 0; i<n1; i++){
        B[i] = A[i*2+1];
    }
    for (int i = 0; i<(size - n1); i++){
        C[i] = A[i*2];
    }
    MergeS(B,n1);
    MergeS(C,size-n1);

    //Слияние двух отсортированных частей
    int o, p;
    o = p = 0;
    for (int i = 0; i < size; i++){
        if (p>=(size-n1)||(o<n1 && B[o]<C[p])){
            A[i] = B[o];
            o++;
        }
        else{
            A[i] = C[p];
            p++;
        }
    }
    delete[] B;
    delete[] C;
}

void getFile(string filename, int size, int n1, int n2){
    ofstream out(filename);

    srand(time(0));
    for (int i = 0; i < size; i++){
        out << n1 + rand()%(n2-n1+1)<<" ";
    }
    out.close();
}

void MergeSort(string filename,int size){
    //Делим на два файла
    for (int i = 0; i<n1; i++){
        B[i] = A[i*2+1];
    }
    //как подготовить (поделить) в субфункции половинки файлов к передаче в сортирующую функцию
    for (int i = 0; i<(size - n1); i++){
        C[i] = A[i*2];
    }
}
int main(void){
    system("chcp 1251");
    int f = 1;
    int in;
    while (f){
        cout<<"1) Cортировка одного массива, сформированного случайным образом\n";
        cout<<"2) Режим накопления статистических данных\n";
        cout<<"0) Выход \n";
        cin>>in;;
        switch (in){
            case 1:{
                int n,in2;
                cout<<"Задайте размер массива: ";
                cin>>n;
                int *A;
                A = new int [n];
                cout<<"Введите диапозон генерации от n1 до n2 (n1_n2):";
                int n1, n2;
                cin>>n1>>n2;
                getFile("numbers.txt", n, n1, n2);
                get(A, n);
                int *B = new int [n];
                copy(A,B,n);
                cout<<"1) Сортировка прямым слиянием Merge Sort\n"
                <<"2) Многофазная сортировка Polyphase Merge Sort\n";
                cin>>in2;
                switch (in2){
                    case 1:{
                        MergeS(B, n);
                        break;
                    }
                    case 2:{
                        //B.polyphaseMergeSort();
                        break;
                    }
                }
                
                cout<<"Отсортированный массив: \n";
                get(B, n);
                string name;
                /*cout<<"Укажите имя файла вывода: \n";
                cin>>name;
                ofstream fout(name);
                if (!fout.is_open()){
                    cout<<"Ошибка открытия!";
                }
                else{
                    A.get_file(fout);
                    B.get_file(fout);
                }
                fout.close();*/

                break;
            }
            /*
            case 2:{
                int in2,in3;
                int a1,b1,l;
                cout<<"1) Заполнение случайными значениями\n"
                <<"2) Заполнение упорядоченными значениями\n"
                <<"3) Заполнение обратноупорядоченными значениями\n";
                cin>>in2;
                cout<<"Введите диапазон (от _ до _) и шаг через пробел:\n";
                cin>>a1>>b1>>l;
                arr<int> *A;
                int N = (b1-a1)/l+1;
                A = new arr<int> [N];
                switch (in2){
                    case 1:{
                        for (int i = 0; i<N-1; i++){
                            A[i].setS(((i)*l)+a1);
                            A[i].fillR(1,20);
                        }
                        break;
                    }
                    case 2:{
                        for (int i = 0; i<N-1; i++){
                            A[i].setS(((i)*l)+a1);
                            A[i].fillU();
                        }
                        break;
                    }
                    case 3:{
                        for (int i = 0; i<N-1; i++){
                            A[i].setS(((i)*l)+a1);
                            A[i].fillUr();
                        }
                        break;
                    }
                }
                cout<<"Всего заполнено "<<N-1<<" массивов.\n";

                cout<<"1) Сортировка прямым слиянием Merge Sort\n"
                <<"2) Многофазная сортировка Polyphase Merge Sort\n";
                cin>>in2;
                ofstream fout("results.txt");
                int t1 = clock();
                switch (in2){
                    case 1:{
                        for (int i = 0; i<N-1; i++){
                            int t_1 = clock();
                            A[i].mergeSort();
                            int t_2 = clock();
                            int ans = t_2 - t_1;
                            cout<<A[i].getS()<<" эл отсортированы за "<<ans<<"ms\n";
                            fout<<A[i].getS()<<" "<<ans<<"\n";
                        }
                        break;
                    }
                    case 2:{
                        for (int i = 0; i<N-1; i++){
                            int t_1 = clock();
                            A[i].polyphaseMergeSort();
                            int t_2 = clock();
                            int ans = t_2 - t_1;
                            cout<<A[i].getS()<<" эл отсортированы за "<<ans<<"ms\n";
                            fout<<A[i].getS()<<" "<<ans<<"\n";
                        }
                        break;
                    }
                }
                int t2 = clock();
                int answ = (t2-t1);
                cout<<"Общее время: "<<answ<<"ms\n";
                break;

            }*/
            case 0:{
                f = 0;
                break;
            }
        }
    }
}