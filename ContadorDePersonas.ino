/*
 * Contador de Personas
 * - Guanotoa Alexander
 * - Ubidia Jonathan
 * - Bolaños Santiago
 */

// Entradas decodificador
int A=22;
int B=23;
int C=24;
int D=25;

// Variables para Multiplexar Displays
int decenas, unidades;
int dec=30;
int uni=31;

// Switchs para los sensores
int emi1=32;
int emi2=33;
int swt1=34;
int swt2=35;

//Contador
int cuenta=0;

// En el setup establecemos los parámetros iniciales.
void setup() {
  pinMode(swt1, INPUT); // El switch 1 será entrada. Receptor IR.
  pinMode(swt2, INPUT); // El switch 2 será entrada. Receptor IR.
  pinMode (emi1, OUTPUT);
  pinMode (emi2, OUTPUT);
  pinMode (A, OUTPUT);
  pinMode (B, OUTPUT);
  pinMode (C, OUTPUT);
  pinMode (D, OUTPUT);
  pinMode (dec, OUTPUT);
  pinMode (uni, OUTPUT);

  digitalWrite(emi1,HIGH);    // Encendido inicial del emisor 1.
  digitalWrite(emi2,HIGH);    // Encendido inicial del emisor 2.
    
 }

void loop() {
  // CONTADOR PARA LAS PERSONAS QUE ENTRAN
  if (digitalRead(swt1)==LOW && digitalRead(swt2)==HIGH){
    digitalWrite(emi1,LOW);
    
    while(digitalRead(swt1)==LOW && digitalRead(swt2)==HIGH){ //Condicion para evitar activacion si no se completa el trayecto de ida.
      digitalWrite(emi1,LOW);
    }
    
    delay(400);
    if (cuenta<99){
      cuenta++;
    } 
  }

  // CONTADOR PARA LAS PERSONAS QUE SALEN
  if (digitalRead(swt1)==HIGH && digitalRead(swt2)==LOW){
    digitalWrite(emi2,LOW);

    while(digitalRead(swt2)==LOW && digitalRead(swt1)==HIGH){ //Condicion para evitar activacion si no se completa el trayecto de vuelta.
      digitalWrite(emi2,LOW);
    }
    
    delay(400);
    if (cuenta>0 && cuenta<99){ // Condicion para contar unicamente entre 0 y 99
    cuenta--;
    }
  }

  digitalWrite(emi1,HIGH);    // Reinicio del emisor 1 a su estado natural.
  digitalWrite(emi2,HIGH);    // Reinicio del emisor 2 a su estado natural.
  
  decenas=cuenta/10;
  unidades=cuenta-decenas*10;
  digitalWrite(dec, HIGH);
  digitalWrite(uni,LOW);
  contador(decenas);
  delay(10);
  digitalWrite(dec,LOW);
  digitalWrite(uni,HIGH);
  contador(unidades);
  delay(10);
  
}

void contador (int dato){
  switch(dato){
    case 0:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;

    case 1:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;

    case 2:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;

    case 3:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    
    case 4:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;

    case 5:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;

    case 6:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;

    case 7:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    
    case 8:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
    break;

    case 9:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
    break;
  }
}
