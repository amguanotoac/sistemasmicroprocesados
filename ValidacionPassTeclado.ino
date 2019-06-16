/*
  Universidad Técnica del Norte
  Facultad de Ingenieria y ciencias aplicada
  Carrera de Ingenieria en electrónica y redes de comunicación

  Nombre:     Alexander Guanotoa
  Asignatura: Sistemas Microprocesados
  Tarea:      Validacion de contrasena con Keypad
  Fecha:      16 de jun. de 2019.
*/

#include <Keypad.h>;
#include <LiquidCrystal.h>
LiquidCrystal lcd {23, 22, 27, 26, 25, 24};

char contrasena[] = "1234";
char contrasenaKeypad[4];
int cont = 0;

const byte filas = 4;
const byte columnas = 4;

char hexaKeys[filas][columnas] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte filasPines[filas] = {7, 8, 9, 6};
byte columnasPines[columnas] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), filasPines, columnasPines, filas, columnas); //En este punto el teclado se inicia y realiza el mapeo de sus teclas con respecto a la matriz colocada arriba

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT); //El pin 13 sera nuestra salida digital (así aprovecharemos el led que pose)
  lcd.begin(16, 2);   // (8,4)
}

void loop() {
  char customKey = customKeypad.getKey();
  if (customKey != NO_KEY) {
    contrasenaKeypad[cont] = customKey;
    Serial.print(contrasenaKeypad[cont]);
    for (int i = 0; i < 4; i++) {
      lcd.setCursor ( i + 5, 1 );
      lcd.print(contrasenaKeypad[i]);
    }

    delay(400);
    cont = cont + 1;
    if (cont == 4) {
      if (contrasenaKeypad[0] == contrasena[0] && contrasenaKeypad[1] == contrasena[1] && contrasenaKeypad[2] == contrasena[2] && contrasenaKeypad[3] == contrasena[3]) {
        lcd.clear();
        lcd.setCursor ( 0, 0 );
        lcd.print("PASS CORRECTO");
      } else if (contrasenaKeypad != contrasena) {
        lcd.clear();
        lcd.setCursor ( 0, 0 );
        lcd.print("PASS INCORRECTO");
      }
      contrasenaKeypad[0] = ' ';
      contrasenaKeypad[1] = ' ';
      contrasenaKeypad[2] = ' ';
      contrasenaKeypad[3] = ' ';
      cont = 0;
    }
  }
}
