#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* determinarPrimos(int cantidadPrimos);

int main(){
//     int matriz[3][2];
//     int contador = 1;
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 2; j++){ 
//             matriz[i][j] = contador++;
//             printf("Dato: %d Posicion %p", matriz[i][j], &matriz[i][j]);
//         }
//         printf("\n");
//     }
// Hacer una matriz con los primero primos 
    int count = 0;
    int rows = 4;
    int columns = 2;
    int* primos = determinarPrimos(100);
    int** Array = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++){
        Array[i] = (int*) malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++){
            Array[i][j] = primos[count++];
            printf("Dato: %d, Direccion: %p\n",Array[i][j],&Array[i][j]);
        }
    }
    

}
int* determinarPrimos(int cantidadPrimos){
    int candidato = 2;
    int contador = 0;
    int* Array = (int*)malloc(cantidadPrimos * sizeof(int));
    while(1){
        int raizEntera = (int)sqrt(candidato); 
        for(size_t i = 2; i <= raizEntera || raizEntera == 1; i++){
            if(candidato % i == 0 && candidato != 2){
                break;
            }
            else{
                if(i >= raizEntera){
                    Array[contador++] = candidato;
                }
            }
            if(raizEntera == 1){
                break;
            }
        } 
        if (contador == cantidadPrimos){
            break;
        }
        candidato++;
    }
    return Array;
}