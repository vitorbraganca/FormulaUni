// Receptor, basico
#include <SPI.h>                      //DECLARA A BIBLIOTECA SPI NECESSÁRIA PARA A COMUNICAÇÃO
#include "nRF24L01.h"                 //DECLARA A BIBLIOTECA ESPECÍFICA PARA O MÓDULO NRF24L01
#include "RF24.h"                     //DECLARA A BIBLIOTECA PARA GERENCIAMENTO DE REDE RF2.4GHZ
int informacao[1];                    //RESERVA ESTA VARIÁVEL PARA RECEBER O VALOR QUE SERÁ TRANSMITIDO
RF24 radio(9,10);                     //DEFINE AS PORTAS DE ENDEREÇO E SELEÇAO DE MODO (CE: Porta 9/CSN: Porta 10)
const uint64_t pipe = 0xE8E8F0F0E1LL; //DEFINE O ENDEREÇO PARA O PIPE
 
void setup(){ 
  Serial.begin(9600);           //INICIALIZA A COMUNICAÇÃO SERIAL
  radio.begin();                //INICIALIZA A COMUNICAÇÃO PELO RADIO
  radio.openWritingPipe(pipe);  //INICIALIZA A TRANSMISSÃO ATRAVÉS DO DUTO
  informacao[0] = 0;            //ATRIBUI VALOR INICIAL PARA A VARIÁVEL
}
 
void loop(){
informacao[0] = map(analogRead(A0),0,1023,0,180);   //MAPEIA A ESCALA DE LEITURA ANALÓGICA EM OUTRA ESCALA E O ARMAZENA NA VARIÁVEL
radio.write(informacao, sizeof(informacao));        //ENVIA O CONTEÚDO DA VARIÁVEL ATRAVÉS DO RÁDIO
}
