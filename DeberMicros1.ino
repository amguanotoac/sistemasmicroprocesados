int i,j;
int leds[8]={0,1,2,3,4,5,6,7};
void setup() {
  // put your setup code here, to run once:
  for (i=0;i<8;i++) {
    pinMode(leds[i],OUTPUT);
  }
}

void loop() {
  // 1) Leds de numero par
  for (i=0;i<8;i+=2) {
    digitalWrite(leds[i],HIGH);
    delay(200);
    digitalWrite(leds[i],LOW);  
    delay(200);
  }

  // 2) Leds de numero impar
  for (i=1;i<8;i+=2) {
    digitalWrite(leds[i],HIGH);
    delay(200);
    digitalWrite(leds[i],LOW);  
    delay(200);
  }

  // 3) Leds secuenciales con encendido y apagado sostenido
  for (i=7;i>=0;i--) {
    digitalWrite(leds[i],HIGH);
    delay(100);
  }
  for (i=0;i<8;i++) {
    digitalWrite(leds[i],LOW);
    delay(100);
  }

  // 4)  Leds secuenciales con encendido y apagado sostenido
  for (i=0;i<4;i++) {
    digitalWrite(leds[i],HIGH);
    delay(100);
  }
  for (i=7;i>3;i--) {
    digitalWrite(leds[i],HIGH);
    delay(100);
  }
  for (i=0;i<4;i++) {
    digitalWrite(leds[i],LOW);
    delay(100);
  }
  for (i=7;i>3;i--) {
    digitalWrite(leds[i],LOW);
    delay(100);
  }

  // 5) Leds pares asc. - impares des.
  for (i=0;i<8;i+=2) {
    digitalWrite(leds[i],HIGH);
    delay(100);
  }
  for (i=7;i>=0;i-=2) {
    digitalWrite(leds[i],HIGH);
    delay(100);
  }
  for (i=7;i>=0;i-=2) {
    digitalWrite(leds[i],LOW);
    delay(100);
  }
  for (i=0;i<8;i+=2) {
    digitalWrite(leds[i],LOW);
    delay(100);
  }
}
