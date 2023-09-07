#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("text.txt");
    int a[10],sum=0;
    for(int i=0;i<10;i++){
        fin>>a[i];
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}