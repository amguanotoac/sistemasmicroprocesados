/* 
 *  UNIVERSIDAD TÉCNICA DEL NORTE 
 *  FICA-CIERCOM 
 *  SISTEMAS MICROPROCESADOS 
 *   
 *  Autor: Guanotoa Alexander 
 *  Programa: Validacion de CI ecuatoriana
 *  
 *  Descripcion:
 *  El proceso para la validación es el siguiente:
 *  La cédula ecuatoriana está formada por los dos primeros dígitos que corresponden a la provincia
 *  donde fue expedida, por lo cual, los dos primeros dígitos no serán mayores a 24 ni menores a 0.
 *  El tercer dígito es un número menor a 6 (0,1,2,3,4,5).  * Los siguientes hasta el noveno dígito son un número consecutivo.
 *  El décimo es el dígito verificador.
 *  Los coeficientes usados para verificar el décimo dígito de la cédula, mediante el “Módulo 10”.
 */

String  CI;
String  CIguion;
String  CIvector[9];
int     CIint[9];
int     total=0;
int     coeficientes[]={2,1,2,1,2,1,2,1,2};
int     producto=1;
int     prov;
int     tercer;
int     verificador;
void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese la cedula con el formato XXXXXXXXX-X\n");
}

void loop() {
  if(Serial.available()>0){
    CIguion=Serial.readString();                           // Captura el dato con guion en la variable
    CI=CIguion.substring(0,9) + CIguion.substring(10,11);       // Captura de numeros
    if(CI.length()==10){
      for(int i=0;i<10;i++){   //Guardo CI en un vector
        CIvector[i]=CI.substring(i,i+1);
      }
      for(int i=0;i<9;i++){   //Transformo el String a int array
        CIint[i]=(CIvector[i]).toInt();
      }
      String provSTR = CI.substring(0,2);                     // Toma el 1er y 2do digito
      prov=provSTR.toInt();
      String tercerSTR = CI.substring(2,3);                  // Toma el 3er digito
      tercer=tercerSTR.toInt();
      String verificadorSTR = CI.substring(9,10);            // Toma el 10mo digito
      verificador=verificadorSTR.toInt();
      
      if((prov > 0 && prov <= 24) && tercer < 6){
        for(int i=0;i<9;i++){
          producto = coeficientes[i]*CIint[i];
          if(producto >= 10){
            producto = producto-9;
          }
        }
        total = total+producto;
        total = total % 10;
        total = 10 - total;
        if(total == 10){
          total = 0;
        }
        
        // VERIFICACION DEL ULTIMO DIGITO
        if (verificador == total){
          Serial.println("");
          Serial.println("La CI que ha ingresado es correcta");
        }else{
          Serial.println("");
          Serial.println("La CI que ha ingresado no existe\n");
        }
      }
    }else if(CI.length()<10){
      Serial.println("");
      Serial.println("No ha ingresado los suficientes digitos\n");
    }
    Serial.println("");
    Serial.println("Ingrese otra CI que desee validar\n");
  }
}
