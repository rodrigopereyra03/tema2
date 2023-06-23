#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pedirCantidad();
int generarAleatorio(int min, int max);
void cargarVectorAleatorio(int v[], int tam);
void mostarVector(int v[], int tam);
void mostrasPosicionesImpares(int v[], int tam);
int mayorMenoresNumero50(int v[], int tam);

int main(){
    srand(time(0));

    generarAleatorio(10,99);

    int tam=pedirCantidad();
    int v[tam];
    cargarVectorAleatorio(v,tam);
    mostarVector(v,tam);

    mostrasPosicionesImpares(v,tam);

    mayorMenoresNumero50(v,tam);

    return 0;
}

int pedirCantidad(){
    int cant;
    do{
        printf("Ingrese un tamanio de 11 a 29, \nque no se pueda dividir ni por 2 ni por 5 \n");
        scanf("%d",&cant);
    } while(cant<10 || cant>30 || cant%2==0 || cant%5==0);
    return cant;
};

int generarAleatorio(int min, int max){
    int ale;
    do{
    ale= min+rand()%(max-min+1);
    } while (ale%2==1);
    return ale;
};

void cargarVectorAleatorio(int v[], int tam){
    for(int i=0; i<tam; i++){
        v[i]=generarAleatorio(10,99);
    }
};

void mostarVector(int v[], int tam){
    printf("||");
    for(int i=0; i<tam; i++){
        printf(" %d ", v[i]);
    }
    printf("||");
};

void mostrasPosicionesImpares(int v[], int tam){
    printf("\n");
    printf("||");
    for(int i=0; i<tam; i++){
        if(i%2==1){
            printf(" %d ", v[i]);
        }
    }
    printf("||");
};

int mayorMenoresNumero50(int v[], int tam){
    int mayor=-1;

    for(int i=0; i<tam; i++){
        if(v[i]<50 && v[i]>mayor){
            mayor=v[i];
        }
    }
    if(mayor!=-1){
    printf("\nEl mayor menor a 50 es: %d", mayor);
    } else {
    printf("no hay menor a 50");
    }
    return mayor;
};
