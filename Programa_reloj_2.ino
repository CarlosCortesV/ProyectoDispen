/*
  Capitulo 38 de Arduino desde cero en Español.
  Programa que establece una alarma para escribir en monitor serie el texto Alarma
  exactamente a las 14:30 hs. todos los dias.

  Autor: bitwiseAr

*/
#include<Servo.h>   // Incluye libreria para Servos
#include<Keypad.h>  //  Incluye libreria para teclado
#include <Wire.h>   // Incluye libreria para interfaz I2C
#include <RTClib.h>   // Incluye libreria para el manejo del modulo RTC
#include <LiquidCrystal_I2C.h> //Incluye libreria para el manejo LCD
#include <LCD.h> //Inlcuye libreria para funciones de LCD
LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7); // DIR, E, RW, RS, D4, D5, D6, D7
RTC_DS3231 rtc;     // Crea objeto del tipo RTC_DS3231
Servo motor;
const byte FILAS = 4;
const byte COLUMNAS = 4;
char keys[FILAS][COLUMNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinesFilas[FILAS] = {9, 8, 7, 6};
byte pinesColumnas[COLUMNAS] = {5, 4, 3, 2};
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);
bool alarma = true;   // Variable de control con valor verdadero
int led = 11; // Pin para encender led
int servo1; // Pines para servos
int servo2;
int servo3;
int servo4;
int buzz = 10; //Pin para buzz
char TECLA;
char TECLA2;
int h = 6;
int n;
int m = 0;
int verifica = "S";
int control;
void setup () {
  motor.attach(3);
  lcd.setBacklightPin(3, POSITIVE); // Puerto P3 de PCF8574 como positivo
  lcd.setBacklight(HIGH);   // Habilita iluminacion posterior de LCD
  lcd.begin(16, 2);     // 16 columnas por 2 lineas para LCD 1602A
  lcd.clear();      // Limpia pantalla
  Serial.begin(9600);    // Inicializa comunicacion serie a 9600 bps
  pinMode(led, OUTPUT); //Habilitamos el led como salida
  pinMode(buzz, OUTPUT); //Habilitamos el buzz como salida
  if (! rtc.begin()) {   // Si falla la inicializacion del modulo
    Serial.println("Modulo RTC no encontrado !");  // Muestra mensaje de error
    while (1);         // Bucle infinito que detiene ejecucion del programa
  }
}

void loop () {
  TECLA =  teclado.getKey(); //Nos devuelve el valor del teclado como un string
  DateTime fecha = rtc.now();        // Funcion que devuelve fecha y horario en formato
  // DateTime y asigna a variable fecha
  // Alarma 1
  Alarma1();
  Alarma2();
  Alarma3();
  Alarma4();
  Alarma5();
  Alarma6();
  Alarma7();
  Alarma8();
 if (TECLA != NO_KEY)                    //si tecla es diferente de "no tecla"... (si se presiona una tecla)
  {    
    Controlador();
  }
 


  lcd.setCursor(0, 0);    // Ubica cursor en columna 0 y linea 0
  lcd.print("D:"); // Establece
  lcd.print(fecha.year());
  lcd.print("/");
  lcd.print(fecha.month());
  lcd.print("/");
  lcd.print(fecha.day());
  lcd.print(" ");
  lcd.setCursor(0, 1);
  lcd.print("T: ");
  lcd.print(fecha.hour());
  lcd.print(":");
  lcd.print(fecha.minute());
  lcd.print(":");
  lcd.print(fecha.second());
  if ( fecha.hour() == 2 && fecha.minute() == 0 )   // si hora = 2 y minutos = 0 restablece valor de
    alarma = true;          // variable de control en verdadero


//Crear codigo para poder entrar al menu varias veces.
 if (TECLA == '5'){
    Controlador();
    }
  Serial.print(TECLA);

}
void Alarma1() {
  DateTime fecha = rtc.now();
  if ( fecha.hour() == h && fecha.minute() == m) { // Si hora = 6 y minutos = 0
    if ( alarma == true ) {       // Si alarma tiene un valor verdadero
      motor.write(0);
      delay(1000);
      motor.write(90);
      delay(1000);
      digitalWrite(buzz, HIGH);   // Enciende buzz
      Serial.print(h);
      digitalWrite(led, HIGH);    // Enciende led
      delay(2000);                // Durante 2s
      digitalWrite(buzz, LOW);    // Apaga buzz
      digitalWrite(led, LOW);     // Apaga led
      alarma = false;         // Carga valor falso en variable de control
    }             // Para evitar ingresar mas de una vez
  }
}
void Alarma2() {
  // Alarma 2
  DateTime fecha = rtc.now();
  if ( fecha.hour() == 7 && fecha.minute() == 0) { // si hora = 7 y minutos = 0
    if ( alarma == true ) {       // si alarma tiene un valor verdadero
      motor.write(0);
      delay(1000);
      motor.write(90);
      delay(1000);
      digitalWrite(buzz, HIGH);   // Enciende buzz
      digitalWrite(led, HIGH);    // Enciende led
      delay(2000);                // Durante 2s
      digitalWrite(buzz, LOW);    // Apaga buzz
      digitalWrite(led, LOW);     // Apaga led
      alarma = false;         // Carga valor falso en variable de control
    }             // Para evitar ingresar mas de una vez
  }
}
void Alarma3() {
  // Alarma 3
  DateTime fecha = rtc.now();
  if ( fecha.hour() == 8 && fecha.minute() == 0) { // si hora = 8 y minutos = 0
    if ( alarma == true ) {       // si alarma tiene un valor verdadero
      motor.write(0);
      delay(1000);
      motor.write(90);
      delay(1000);
      digitalWrite(buzz, HIGH);   // Enciende buzz
      digitalWrite(led, HIGH);    // Enciende led
      delay(2000);                // Durante 2s
      digitalWrite(buzz, LOW);    // Apaga buzz
      digitalWrite(led, LOW);     // Apaga led
      alarma = false;         // Carga valor falso en variable de control
    }             // Para evitar ingresar mas de una vez
  }
}
void Alarma4() {
  // Alarma 4
  DateTime fecha = rtc.now();
  if ( fecha.hour() == 10 && fecha.minute() == 0) { // si hora = 10 y minutos = 0
    if ( alarma == true ) {       // si alarma tiene un valor verdadero
      motor.write(0);
      delay(1000);
      motor.write(90);
      delay(1000);
      digitalWrite(buzz, HIGH);   // Enciende buzz
      digitalWrite(led, HIGH);    // Enciende led
      delay(2000);                // Durante 2s
      digitalWrite(buzz, LOW);    // Apaga buzz
      digitalWrite(led, LOW);     // Apaga led
      alarma = false;         // Carga valor falso en variable de control
    }             // Para evitar ingresar mas de una vez
  }
}
void Alarma5() {
  // Alarma 5
  DateTime fecha = rtc.now();
  if ( fecha.hour() == 14 && fecha.minute() == 0) { // si hora = 14 y minutos = 0
    if ( alarma == true ) {       // Si alarma tiene un valor verdadero
      digitalWrite(buzz, HIGH);   // Enciende buzz
      digitalWrite(led, HIGH);    // Enciende led
      delay(2000);                // Durante 2s
      digitalWrite(buzz, LOW);    // Apaga buzz
      digitalWrite(led, LOW);     // Apaga led
      alarma = false;         // Carga valor falso en variable de control
    }             // Para evitar ingresar mas de una vez
  }
}
void Alarma6() {
  // Alarma 6
  DateTime fecha = rtc.now();
  if ( fecha.hour() == 20 && fecha.minute() == 0) { // si hora = 20 y minutos = 0
    if ( alarma == true ) {       // Si alarma tiene un valor verdadero
      digitalWrite(buzz, HIGH);   // Enciende buzz
      digitalWrite(led, HIGH);    // Enciende led
      delay(2000);                // Durante 2s
      digitalWrite(buzz, LOW);    // Apaga buzz
      digitalWrite(led, LOW);     // Apaga led
      alarma = false;         // Carga valor falso en variable de control
    }             // Para evitar ingresar mas de una vez
  }
}
void Alarma7() {
  // Alarma 7
  DateTime fecha = rtc.now();
  if ( fecha.hour() == 21 && fecha.minute() == 0) { // si hora = 21 y minutos = 0
    if ( alarma == true ) {       // Si alarma tiene un valor verdadero
      digitalWrite(buzz, HIGH);   // Enciende buzz
      digitalWrite(led, HIGH);    // Enciende led
      delay(2000);                // Durante 2s
      digitalWrite(buzz, LOW);    // Apaga buzz
      digitalWrite(led, LOW);     // Apaga led
      alarma = false;         // Carga valor falso en variable de control
    }             // Para evitar ingresar mas de una vez
  }
}
void Alarma8() {
  // Alarma 8
  DateTime fecha = rtc.now();
  if ( fecha.hour() == 21 && fecha.minute() == 30) { // si hora = 21 y minutos = 30
    if ( alarma == true ) {       // Si alarma tiene un valor verdadero
      digitalWrite(buzz, HIGH);   // Enciende buzz
      digitalWrite(led, HIGH);    // Enciende led
      delay(2000);                // Durante 2s
      digitalWrite(buzz, LOW);    // Apaga buzz
      digitalWrite(led, LOW);     // Apaga led
      alarma = false;         // Carga valor falso en variable de control
    }             // Para evitar ingresar mas de una vez
  }
}

void Continuar(){
  while (verifica == "S"){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(h);
        lcd.print(m);
        lcd.setCursor(0, 1);
        lcd.print("Continuar: S/N");
        TECLA2 = teclado.getKey();
          if (TECLA2 == 'A'){
          verifica = "S";
          
          }
          if (TECLA2 == 'B'){
          verifica = "N";
          lcd.clear();
          }
          delay(500);
          }
  }
void Controlador(){
  
    switch (TECLA) {
    case '1':
      Continuar();
      break;
    case '2':
      Continuar();
      break;
    case '3':
      Continuar();
      break;
    case '4':
      Continuar();
      break;
    case '5':
      Continuar();
      break;
    case '6':
      Continuar();
      break;
    case '7':
      Continuar();
      break;
    case '8':
      Continuar();
      break;
    case '9':

      break;
    }
  }
