/* Programa: Carrinho, sem comunicacao wireless
   Autor: Vitor Braganca
   Data: 04/11/2019
*/

// *** Estaticas ***
//botao
const int pinBtnFrente = 2;
const int pinBtnTras = 3;
//Joystick
const int eixo_X = A0;
//Motor
const int pinMotor_Frente = 4;
const int pinMotor_Tras = 5;
const int pinMotorEixo_R = 6;
const int pinMotorEixo_L = 7;
void setup() {
  //Serial
  Serial.begin(9600);
  //pinMode
  //input
  pinMode(pinBtnFrente, INPUT_PULLUP);
  pinMode(pinBtnTras, INPUT_PULLUP);
  pinMode(pinEixo_X, INPUT);
  //output
  pinMode(pinMotor_Frente, OUTPUT);
  pinMode(pinMotor_Tras, OUTPUT);
  pinMode(pinMotorEixo_R, OUTPUT);
  pinMode(pinMotorEixo_L, OUTPUT);
}

void loop() {
  reading_Frente = digitalRead(pinBtnFrente);
  reading_Tras = digitalRead(pinBtnTras);
  eixo_X = analogRead(pinEixo_X);
  if (reading_Frente) == LOW{
    Frente();
  } else if (reading_Tras) == LOW {
    Tras();
  }
  if (eixo_X > 512) {
     Direita();
  } else if (eixo_Y < 512) {
    Esquerda();
  }
}

void Frente() {
  digitalWrite(pinMotor_Frente, HIGH);
  digitalWrite(pinMotor_Tras, LOW);
}

void Tras() {

  digitalWrite(pinMotor_Frente, LOW);
  digitalWrite(pinMotor_Tras, HIGH);
}

void Direita() {
  digitalWrite(pinMotorEixo_R, HIGH);
  digitalWrite(pinMotorEixo_L, LOW);
}

void Esquerda() {
  digitalWrite(pinMotorEixo_R, LOW);
  digitalWrite(pinMotorEixo_L, HIGH);
}
