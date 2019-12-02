/*
  Programa: Formula Uni - SEM COMUNICACAO VIA RADIO
  Autor: Vitor Eduardo Braganca
*/

// *** VARIAVEIS ***

// CARRINHO
const int pinMotor_F = 2; //  PONTE H - Frente
const int pinMotor_R = 3; //  PONTE H - RE
// CONTROLE
const int pinBtn_F = 4; // CONTROLE - FRENTE
const int pinBtn_R = 5; // CONTROLE - RE
const int pinEixo_X = A0; // CONTROLE - DIRECAO (joystick)
const int pinEixo_Y = A1; // CONTROLE - ACELERACAO (joystick)
//
int eixo_X = 0; // LEITURA EIXO X
int eixo_Y = 0; // LEITURA EIXO Y
int btn_F = 0; // LEITURA BOTAO FRENTE
int btn_R = 0; // LEITURA BOTAO RE

void setup() {
  //
  Serial.begin(9600);
  Serial.println("Iniciando...");
  //
  pinMode(pinMotor_F, OUTPUT);
  pinMode(pinMotor_R, OUTPUT);
  pinMode(pinBtn_F, INPUT_PULLUP);
  pinMode(pinBtn_R, INPUT_PULLUP);
  Serial.print("DADOS: | eixo X: ");
  Serial.print(eixo_X);
  Serial.print("| eixo Y: ");
  Serial.print(eixo_Y);
  Serial.print(" | btn Frente: ");
  Serial.print(btn_F);
  Serial.print(" | btn Re: ");
  Serial.println(btn_R);

}

void loop() {
  // put your main code here, to run repeatedly:
  // Leitura
  eixo_Y = analogRead(pinEixo_Y);
  eixo_X = analogRead(pinEixo_X);
  btn_F = digitalRead(pinBtn_F);
  btn_R = digitalRead(pinBtn_R);
  Serial.print("DADOS: | eixo X: ");
  Serial.print(eixo_X);
  Serial.print("| eixo Y: ");
  Serial.print(eixo_Y);
  Serial.print(" | btn Frente: ");
  Serial.print(btn_F);
  Serial.print(" | btn Re: ");
  Serial.println(btn_R);

  if (eixo_Y > 600) {
    Frente();
  } else if (eixo_Y < 400) {
    Re();
  } else {
    Tracao_Neutro();
  }
  //

}

//
void Frente() {
  Serial.println("FRENTE");
  digitalWrite(pinMotor_F, HIGH);
  digitalWrite(pinMotor_R, LOW);
}
void Re() {
  Serial.println("RE");
  digitalWrite(pinMotor_F, LOW);
  digitalWrite(pinMotor_R, HIGH);
}

void Direita() {

}
void Esquerda() {

}
void Direcao_Neutro() {

}
void Tracao_Neutro() {
  digitalWrite(pinMotor_F, LOW);
  digitalWrite(pinMotor_R, LOW);
}
