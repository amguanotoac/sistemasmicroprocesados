/* 
 *  UNIVERSIDAD TÉCNICA DEL NORTE 
 *  FICA-CIERCOM 
 *  SISTEMAS MICROPROCESADOS 
 *   
 *  Autor: Guanotoa Alexander 
 *  Programa: Identificador de Placas vehiculares Ecuador
 *  
 *  Descripcion:
 *  El siguiente programa identifica si la placa ingresada es
 *  correcta, ademas verifica y muestra la provincia a la que pertenece
 */

String  placaCompleta;
char    placa[7];
boolean numeros, letras;
 
void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese la placa con el formato LLL-NNNN");
}

void loop() {
  if(Serial.available()>0){
    placaCompleta=Serial.readString();
    placaCompleta=placaCompleta.substring(0,3)+placaCompleta.substring(4,placaCompleta.length());   // Eliminar el guion
    if(placaCompleta.length()==6){
      placaCompleta=placaCompleta.substring(0,3)+"0"+placaCompleta.substring(3,placaCompleta.length());   // Aumentar el 0 si solo tiene 3 dig.
    }
    for(int i=0;i<placaCompleta.length();i++){
      placa[i]=placaCompleta.charAt(i);
    }
    for(int i=0;i<3;i++){
      if(placa[i] >= 'A' && placa[i] <= 'Z'){
        letras=true;
        for(int i=3;i<7;i++){
          if(placa[i] >= '0' && placa[i] <= '9'){
            numeros=true;
          }else{
            numeros=false;
          }
        }
      }else{
        letras=false;
      }
    }
    if(numeros==true && letras==true){
      Serial.println("");
      provincias();
    }else{
      Serial.println("");
      Serial.println("No VALIDA");
    }
  }
}

void provincias(){
  if(placa[0]=='A'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Azuay");
  }
  if(placa[0]=='B'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Bolívar");
  }
  if(placa[0]=='U'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Cañar");
  }
  if(placa[0]=='C'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Carchi");
  }
  if(placa[0]=='X'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Cotopaxi");
  }
  if(placa[0]=='H'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Chimborazo");
  }
  if(placa[0]=='O'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a El Oro");
  }
  if(placa[0]=='E'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Esmeraldas");
  }
  if(placa[0]=='W'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Galápagos");
  }
  if(placa[0]=='G'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Guayas");
  }
  if(placa[0]=='I'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Imbabura");
  }
  if(placa[0]=='L'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Loja");
  }
  if(placa[0]=='R'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Los Ríos");
  }
  if(placa[0]=='M'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Manabí");
  }
  if(placa[0]=='V'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Morona Santiago");
  }
  if(placa[0]=='N'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Napo");
  }
  if(placa[0]=='S'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Pastaza");
  }
  if(placa[0]=='P'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Pichincha");
  }
  if(placa[0]=='Q'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Orellana");
  }
  if(placa[0]=='K'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Sucumbíos");
  }
  if(placa[0]=='T'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Tungurahua");
  }
  if(placa[0]=='Z'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Zamora Chinchipe");
  }
  if(placa[0]=='Y'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Santa Elena");
  }
  if(placa[0]=='J'){
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a Santo Domingo de los Tsáchilas");
  }
}
