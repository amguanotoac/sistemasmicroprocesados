#include <TimerOne.h>

byte outPins[]  = {8, 9, 10, 11, 12}; // comedor, sala, dormitorio, banio, cocina. (orden Luces)
boolean estadoLuz = false; // boolean de encendido y apagado
String clave;

int sensorLuz = 6;

void setup() {
  Serial.begin(9600);
  Timer1.initialize(1000000); // contador a 1 seg
  Timer1.attachInterrupt(encendido); // funcion de interrupcion
}

void loop() {
  if (Serial.available() > 0) {
    clave = Serial.readString();
    if (clave == "1234") {
      Serial.println("contraseña correcta");
      sensorLuz = analogRead(0); //Instrucción para obtener dato analógico
      if (sensorLuz < 700)  {
        digitalWrite(sensorLuz, HIGH);
      } else {
        digitalWrite(sensorLuz, LOW);
      }
      delay(1000);
    }
    else {
      Serial.println("contraseña incorrecta");
    }
  }
}

void encendido() {
  if (sensorLuz == HIGH) {
    for (byte i = 0; i < sizeof(outPins) / sizeof(outPins[0]); i++ ) { //recorremos los pins
      analogWrite( outPins[i], ((estadoLuz) ? 0 : random(8, 12)) ); //Si está encendido, lo apagamos y viceversa (cuartos aleatorios)
    }
    estadoLuz = !estadoLuz; //Cambiamos el estado
    Timer1.setPeriod((estadoLuz) ? 360000000 : 18000000); //Cambiamos el periodo, 60 min para con la luz encendida, 30 min con la luz apagada.
  }
}
