#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <ctime>

#include <C:\Users\User\Desktop\prog\c\lab1\Fill.h>
#include <C:\Users\User\Desktop\prog\c\lab1\printM.h>
#include <C:\Users\User\Desktop\prog\c\lab1\res.h>

int main(){
    
    setlocale(LC_ALL,"Rus");

    int l,n,k;
    int *x,*rs;

    printf("������� ������ ��������� �������: ");
    scanf("%i",&l);
    x=new int[l];

    printf("������� �������� ��������� k [-k;k]: ");
    scanf("%i",&k);

    fill(x,l,k);
 
    pArr(x,l);
    
    printf("\n������������ ���-������� �� n ��������� ���������: ");
    scanf("%i",&n);
    rs=new int[n];
    
    res(x,l,n,rs);

    pArr(rs,n);

    return 0;
}