// Transmissor, codigo basico
#include <SPI.h>                      //DECLARA A BIBLIOTECA SPI NECESSÁRIA PARA A COMUNICAÇÃO
#include "nRF24L01.h"                 //DECLARA A BIBLIOTECA ESPECÍFICA PARA O MÓDULO NRF24L01
#include "RF24.h"                     //DECLARA A BIBLIOTECA PARA GERENCIAMENTO DE REDE RF2.4GHZ
#include <Servo.h>                    //DECLARA A BIBLIOTECA PARA OPERAR SERVO MOTORES
Servo myservo;                        //DEFINE O OBJETO SERVO E SEU NOME
int informacao[1];                    //RESERVA ESTA VARIÁVEL PARA RECEBER O VALOR QUE SERÁ RECEBIDO
 RF24 radio(9,10);                    //DEFINE AS PORTAS DE ENDEREÇO E SELEÇAO DE MODO (CE: Porta 9/CSN: Porta 10)
const uint64_t pipe = 0xE8E8F0F0E1LL; //DEFINE O ENDEREÇO PARA O PIPE
 
void setup(){
  Serial.begin(9600);             //INICIALIZA A COMUNICAÇÃO SERIAL
  radio.begin();                  //INICIALIZA A COMUNICAÇÃO PELO RADIO
  radio.openReadingPipe(1,pipe);  //INICIALIZA A RECEPÇÃO ATRAVÉS DO DUTO
  radio.startListening();         //INICIALIZA O RECEBIMENTO
  myservo.attach(3);              //DEFINE O PINO PARA A SAÍDA DIGITAL DO SERVO MOTOR
}
 
void loop(){
  informacao[0] = 0;              //ATRIBUI VALOR INICIAL PARA A VARIÁVEL
  if (radio.available()){         //ROTINA PARA A VERIFICAÇÃO DE RECEPÇÃO
    bool done = false;            //FUNÇÃO PARA VERIFICAR SE NAO EXISTE SINAL
    while (!done){                //CONDIÇÃO PARA VERIFICAR SE O SINAL É CONTRARIO DE INEXISTENTE
      done = radio.read( informacao, sizeof(informacao) );  //SE FOR CONTRÁRIO, A VARIÁVEL LOCAL RECEBE O SINAL LIDO
      myservo.write( informacao[0]);                        //O SINAL LIDO É APLICADO PARA A EXECUÇÃO DO SERVO
      delay(100);                                           //ATRASO PARA A EXECUÇÃO
     }
   }
}
