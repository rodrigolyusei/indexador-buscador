#include <stdio.h>

int matrx [][5] = { 1,2,2,4,3,6,4,8,5,10 };

int main(){
    int i, j;
    /*for(i=0; i<5; i++){
        for(j=0; j<2; j++){
            printf("%d ", matrx[i][j]);
        }
        printf("\n");
    }*/

    float end[1] = {2};

    printf("\n");
    for(i=0; i<100; i++){
        printf("%f ", end[i]);
    }



    return 0;
}