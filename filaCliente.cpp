#include <iostream>
#include <queue>
#include <random>

using namespace std;

struct cliente{
    bool novo_cliente;
    int idCliente;
};

 int main(){ 
        //gerando o caixa
        bool caixa_livre = true;
        //gerando a fila 
        queue<int> fila;
        //gerando o relógio
        int relogio = 0; 
        //gerando cliente 
        struct cliente cliente; 
        //gerando tempo de trabalho do caixa 
        int tempoCaixa = 60*6;
        // Inicializa o gerador de números aleatórios
        std::random_device rd;
        std::mt19937 gen(rd()); // Semente aleatória a partir do dispositivo de hardware ou de um gerador

        // Define o intervalo desejado
        int min = 1;
        int max = 100;

        // Cria uma distribuição uniforme de inteiros dentro do intervalo
        std::uniform_int_distribution<int> dist(min, max);
        //criar o cliente
        //cliente.idCliente = dist(gen); 
        //cliente.novo_cliente = true; 
        int media = 0;
        
        //tempo de chegada do próximo cliente
        //int chegadaCliente = 60*8;

        while(++relogio < (10*3600)){
            //implementar possível chegada de novo cliente
            if(relogio % (6*60) == 0){  //mudar esse tempo para aleatório
                cliente.novo_cliente = true;
                cliente.idCliente = dist(gen);
            }
            if(cliente.novo_cliente == true){
                fila.push(cliente.idCliente);
                cliente.novo_cliente = false;
            }
            if(caixa_livre && !fila.empty()){ 
                caixa_livre = false;
                fila.pop();
                tempoCaixa = relogio + (8*60); //mudar esse tempo pra aleatório
            }
            if(!caixa_livre && (relogio == tempoCaixa)){
                caixa_livre = true;
            }
            //contabilizar tamanho médio da fila
            media = media + fila.size();
            //printf("relogio: %d  tamanho da fila: %d\n", relogio, fila.size());
        }
        
        int mediaFila = media/(10*3600);
        printf("tamanho medio da fila:%d\n", mediaFila);
        
  return 0;
 }    