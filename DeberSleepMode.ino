
/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FACULTAD DE INGENIERÍA EN CIENCIAS APLICADAS
 * CARRERA DE INGENIERÍA EN ELECTRÓNICA Y REDES DE COMUNICACIÓN

   Realizar un sistema que permita en intervalos de tiempo (puede ser cada 2 segundos)
   establecido dormir al sistema y levantarse para lecturas de un conversor análogo digital.
   Toma la lectura, la envía por comunicación serial y se vuelve a dormir.
   
   NOMBRE: GUANOTOA ALEXANDER
      
*/

#include <avr/sleep.h>
#include <avr/wdt.h>
#include <EEPROM.h>

byte estado = LOW;
float datoCAD = 0;

void setup() {
  estado = EEPROM.read(0);
  Serial.begin(9600);
  Serial.println("Iniciando...");

  ///////////////////////// Duerme al sistema por 8 seg. ///////////////////////////// 
  if (estado == LOW) {
    set_sleep_mode(SLEEP_MODE_STANDBY);
    sleep_enable();
    EEPROM.write(0, HIGH);                 
    wdt_enable(WDTO_8S);
  ///////////////////////// Duerme al sistema por 8 seg. ///////////////////////////// 
   
  /////////////// Despierta al sistema por 500 ms para tomar lecturas //////////////// 
  } else {
    sleep_disable();
    EEPROM.write(0, LOW);  
    wdt_enable(WDTO_500MS);
  }
  /////////////// Despierta al sistema por 500 ms para tomar lecturas //////////////// 
}

void loop() {
  /////////////////////////////// Entra en modo Sleep /////////////////////////////// 
  if (estado == LOW) {                       
    Serial.println("Suspendiendo...");
    delay(100);
    sleep_mode();    
  /////////////////////////////// Entra en modo Sleep ///////////////////////////////      
                    
  /////////////////// Acciones mientras el sistema esta despierto /////////////////// 
  } else {    
    datoCAD = analogRead(A0);               // Lectura del pin A0      
    Serial.println("Sistema Activo ");
    Serial.println(datoCAD);                // Muestra el valor del CAD
    delay(100);
  }
  /////////////////// Acciones mientras el sistema esta despierto /////////////////// 
}
