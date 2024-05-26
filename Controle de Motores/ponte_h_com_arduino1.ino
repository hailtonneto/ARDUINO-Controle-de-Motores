#define EN1 2
#define IN1 3
#define IN2 4

#define EN2 5
#define IN3 6
#define IN4 7

#define BTN_FRENTE 8
#define BTN_DIREITA 9
#define BTN_TRAS 10
#define BTN_ESQUERDA 11

#define BTN_PARAR 12

void setup(){
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(BTN_FRENTE, INPUT_PULLUP);
  pinMode(BTN_DIREITA, INPUT_PULLUP);
  pinMode(BTN_TRAS, INPUT_PULLUP);
  pinMode(BTN_ESQUERDA, INPUT_PULLUP);
  
  pinMode(BTN_PARAR, INPUT_PULLUP);
  
  /*
  	IN1 | IN2 | MOTOR
    HIGH  LOW	HORARIO
    LOW   HIGH  ANTI-HORARIO
    LOW   LOW   IRRELEVANTE
    HIGH  HIGH  IRRELEVANTE
    
    IN3 | IN4  | MOTOR2
    HIGH  LOW    ANTI-HORARIO
    LOW   HIGH   HORARIO
    LOW   LOW    IRRELEVANTE
    HIGH  HIGH   IRRELEVANTE
  */
}

void plataformaFrente(){
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, HIGH);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void plataformaTras(){
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, HIGH);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void plataformaDireita(){
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, HIGH);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void plataformaEsquerda(){
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, HIGH);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void plataformaParar(){
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, LOW);
}

void loop(){
  if(digitalRead(BTN_FRENTE) == 0){
    plataformaFrente();
  }
  
  if(digitalRead(BTN_DIREITA) == 0){
    plataformaDireita();
  }
  
  if(digitalRead(BTN_TRAS) == 0){
    plataformaTras();
  }
  
  if(digitalRead(BTN_ESQUERDA) == 0){
    plataformaEsquerda();
  }
  
  if(digitalRead(BTN_PARAR) == 0){
    plataformaParar();
  }
}