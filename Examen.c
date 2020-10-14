#include<stdio.h>
#include<stdlib.h>

FILE * datos;

int nBoletas, dd, mm, aa, tot;
int gBoletas, gDia,i=0;
int contBoletas, totMes;

struct boletas{
    int dInicial;
    int dFinal;
    int tot;
}V[10];



void primerRegistro();
void corteDia();
void procesarRegistro();
void corteBoleta();

int main() {
    datos = fopen("datosMathias.txt", "r");
    if(datos == NULL) {
        printf("No se pudo abrir el archivo");
    }
    fscanf(datos, "%d %d %d %d %d", &nBoletas, &dd, &mm, &aa, &tot);
    primerRegistro();
    while ( !feof(datos) ){
        if(gDia != dd ){
            corteDia();
        }
        if(nBoletas != contBoletas) {
            corteBoleta();
        }
        procesarRegistro();
        fscanf(datos, "%d %d %d %d %d", &nBoletas, &dd, &mm, &aa, &tot);

    }
    
}

void primerRegistro() {
    gBoletas = nBoletas;
    contBoletas = nBoletas;
    gDia = dd;
}

void procesarRegistro() {
    totMes = totMes + tot;
    contBoletas = contBoletas + 1;
}
void corteDia() {
    int j = 0;
    printf("\nDia: %d", gDia);
    printf("\nBoletas \tMonto");
    for ( j = 0; i < i; j++){
        printf("%d al %d \t%d",V[j].dInicial,V[j].dFinal,V[j].tot);
        V[j].dInicial = 0;
        V[j].dFinal = 0;
        V[j].tot = 0; 
    }
    printf("\nTotal %d:",totMes);
    totMes = 0;
    primerRegistro();
    
}

void corteBoleta() {
    V[i].dInicial = gBoletas;
    V[i].dFinal = contBoletas - 1;
    V[i].tot = totMes;
    i++;
    primerRegistro();
}