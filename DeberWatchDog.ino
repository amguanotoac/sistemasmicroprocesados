/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FACULTAD DE INGENIERÍA EN CIENCIAS APLICADAS
 * CARRERA DE INGENIERÍA EN ELECTRÓNICA Y REDES DE COMUNICACIÓN

   Realizar un programa que reinicie el sistema al tener la hora 00:10:50.
   Cuando vuelva a funcionar, deberá empezar con la hora 00:11:10.
   El proceso se observa en una LCD. No habrá extensión de plazo.

   NOMBRE: GUANOTOA ALEXANDER
*/

#include <LiquidCrystal.h>
#include <MsTimer2.h>
#include <EEPROM.h>
#include <avr/wdt.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int horas;
int minutos;
int segundos;
byte estado = LOW;

int i = 0;
String sh, sm, ss;

void setup() {

  /////////////// BLOQUE DE REINICIO DE MEMORIAS /////////////////
  //  EEPROM.write(0, 0);
  //  EEPROM.write(1, 0);
  //  EEPROM.write(2, 0);
  //  EEPROM.write(3, 0);
  /////////////// BLOQUE DE REINICIO DE MEMORIAS /////////////////

  ////////////// LECTURA ANTERIOR DE LAS MEMORIAS ////////////////
  horas = EEPROM.read(1);
  minutos = EEPROM.read(2);
  segundos = EEPROM.read(3);
  ////////////// LECTURA ANTERIOR DE LAS MEMORIAS ////////////////

  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("HORA: ");
  lcd.setCursor(7, 0);
  lcd.print("00");
  lcd.setCursor(9, 0);
  lcd.print(":");
  lcd.setCursor(10, 0);
  lcd.print(minutos);
  lcd.setCursor(12, 0);
  lcd.print(":");
  lcd.setCursor(13, 0);
  lcd.print(segundos);

  MsTimer2::set(10, reloj);
  MsTimer2::start();
}
void loop() {

}

void reloj() {
  if (segundos < 59) {
    segundos++;
    ss = String(segundos);
    if (ss.length() == 1) {
      lcd.setCursor(13, 0);
      lcd.print("0");
      lcd.setCursor(14, 0);
      lcd.print(segundos);
    } else {
      lcd.setCursor(13, 0);
      lcd.print(segundos);
    }
  } else {
    if (minutos < 59) {
      lcd.setCursor(13, 0);
      lcd.print("00");
      segundos = 0;
      minutos++;
      sm = String(minutos);
      if (sm.length() == 1) {
        lcd.setCursor(10, 0);
        lcd.print("0");
        lcd.setCursor(11, 0);
        lcd.print(minutos);
      } else {
        lcd.setCursor(10, 0);
        lcd.print(minutos);
      }
    } else {
      if (horas < 23) {
        lcd.setCursor(10, 0);
        lcd.print("00");
        minutos = 0;
        segundos = 0;
        horas++;
        sh = String(horas);
        if (sh.length() == 1) {
          lcd.setCursor(7, 0);
          lcd.print("0");
          lcd.setCursor(8, 0);
          lcd.print(horas);
        } else {
          lcd.setCursor(7, 0);
          lcd.print(horas);
        }
      }
    }
  }

  ////////////// CONDICION DE PRIMER Y UNICO REINICIO ////////////////
  if (minutos == 11 && segundos == 10 && EEPROM.read(0) == LOW) {
    lcd.setCursor(0, 1);
    lcd.print("REINICIANDO...");
    estado = HIGH;

    ////////////// ESCRITURA DE LAS VARIABLES EN MEMORIA ///////////////
    EEPROM.write(0, estado);
    EEPROM.write(1, horas);
    EEPROM.write(2, minutos);
    EEPROM.write(3, segundos);
    ////////////// ESCRITURA DE LAS VARIABLES EN MEMORIA ///////////////

    wdt_enable(WDTO_500MS);
    Serial.println("REINICIANDO...");
  }
  ////////////// CONDICION DE PRIMER Y UNICO REINICIO ////////////////
}
