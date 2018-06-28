    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <stdlib.h>
    #include <assert.h>
    #include<iostream>
    using namespace std;
    void insertionSort(int ar_size, int *  ar) {
        int i,value,hole,j;
        for(i=1;i<ar_size;i++)
            {
            value=ar[i];
            hole=i;
            while(hole>0 && ar[hole-1]>value)
                {
                ar[hole]=ar[hole-1];
                hole=hole-1;

                }
            ar[hole]=value;
            for(j=0;j<ar_size;j++)
                cout<<ar[j]<<" ";
            cout<<endl;
        }
    }
    int main(void) {

       int _ar_size;
    cin>>_ar_size;
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
       cin>>_ar[_ar_i];
    }

    insertionSort(_ar_size, _ar);

       return 0;
    }
