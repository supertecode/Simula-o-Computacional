#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <random>

using namespace std;

struct cliente{
    bool novo_cliente;
    int idCliente;
};


int dist1(){

   int oi = (rand()%100);

    if(oi< 10){
        return 1*60;
    }
    else if(oi < 25){
        return 3*60; 
    }
    else if(oi< 75){
        return 6*60; 
    }
    else if(oi < 90){
        return 9*60;
    }
    else{
        return 12*60;
    }
}

int dist2(){

   int oi = (rand()%100);

    if(oi< 10){
        return 1*60;
    }
    else if(oi < 25){
        return 5*60; 
    }
    else if(oi< 75){
        return 10*60; 
    }
    else if(oi < 90){
        return 15*60;
    }
    else{
        return 20*60;
    }
}

int main(){ 

    srand(time(NULL));
    bool caixa_livre = true;
    queue<int> fila;
    int relogio = 0; 
    struct cliente cliente;
    int tempoCaixa = 0;
    int media = 0;
    int tempoCliente = 1;

            while(++relogio < (10*3600)){
            
            if(relogio == tempoCliente){  
                cliente.novo_cliente = true;
                cliente.idCliente = (rand()%100);
                tempoCliente = tempoCliente + dist2();
            }
            if(cliente.novo_cliente == true){
                fila.push(cliente.idCliente);
                cliente.novo_cliente = false;
            }
            if(caixa_livre && !fila.empty()){ 
                caixa_livre = false;
                fila.pop();
                tempoCaixa = tempoCaixa + dist1(); 
            }
            if(!caixa_livre && (relogio == tempoCaixa)){
                caixa_livre = true;
            }
            
            media = media + fila.size();
            printf("relogio: %d  tamanho da fila: %d\n", relogio, fila.size());
        }
        
        int mediaFila = media/(10*3600);
        printf("tamanho medio da fila:%d\n", mediaFila);

    return 0;
}
