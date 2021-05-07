#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33);  //Declara los puertos que se utilizaran para el cristal

float grados1;
float grados2;
float grados3;
int pulsos1;
int pulsos2;
int pulsos3;
int posiciona;
char motor;
char movimiento = 'z';
char opcion;
float guardados[11][3] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
int guardadosp[11][3] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
int numdatos = 0;
int addre = 0;

int pasos1[]={0x09, 0x08, 0x0C, 0x04, 0x06, 0x02, 0x03, 0x01};
int pasos2[]={0x90, 0x80, 0xC0, 0x40, 0x60, 0x20, 0x30, 0x10};
int pasos3[]={0x09, 0x08, 0x0C, 0x04, 0x06, 0x02, 0x03, 0x01};
byte puertos[]={34,35,36,37,42,43,44,45,50,51,52,53};

int x;
int y;

void setup() {
    Serial1.begin(9600,SERIAL_8N1);                 //Comienza los puertos para output
    analogReference(EXTERNAL); 
    for (x = 0; x < 16; x++){
      pinMode(puertos[x], OUTPUT);
    }
    pinMode(A8, OUTPUT);
    pinMode(A9, OUTPUT);
    pinMode(A10, OUTPUT);
    pinMode(A11, OUTPUT);
    x=0;
    y=0;
}

void loop() {
  Serial1.end();
  Serial1.begin(9600,SERIAL_8N1);                                         //Esto imprime preguntas en la pantalla
  int sensorValue = analogRead(0);
  Serial1.print("Voltaje= ");
  Serial1.print((float)(sensorValue*5.0/1023.0),2);
  Serial1.println();
  Serial1.print("Que operacion deseas realizar");
  Serial1.println();
  Serial1.print("a - Mover motores");
  Serial1.println();
  Serial1.print("b - Ver posiciones");
  Serial1.println();
  Serial1.print("C - Run");
  Serial1.println();

  while(Serial1.available() == 0) { } 
    opcion = Serial1.read();                                //Lee el dato que recibe la terminar virtual
    Serial1.println();
    Serial1.print("La opcion seleccionada es");
    Serial1.println();
      if (opcion == 'a' or opcion == 'A'){
        movermotor();
      }
  
      if (opcion == 'b' or opcion == 'B'){
        posiciones();
      }

      if (opcion == 'c' or opcion == 'C'){
        correr();
      }
     
   Serial1.println();
}

void movermotor(){                               //Aqui se leen las opciones de motor y opciones que puede realizar, envia a diferentes funciones
      Serial1.begin(9600,SERIAL_8N1);
      Serial1.print("Mover Motores");
      Serial1.println();
      Serial1.end();
      Serial1.begin(9600,SERIAL_8N1);
      Serial1.print("Que motor deseas mover a,b o c (para regresar presione r) (para guardar los datos presione g)");
      Serial1.println();
      while(Serial1.available() == 0) { } 
      motor = Serial1.read();
      Serial1.println();
        if (motor == 'a' or motor == 'A'){
          motor1();
        }
        if (motor == 'b' or motor == 'B'){
          motor2();
        }
        if (motor == 'c' or motor == 'C'){
          motor3();
        }
        if (motor == 'r' or motor == 'R'){
          loop();
        }
        if (motor == 'g' or motor == 'G'){
          guardar();
        }
}

void posiciones(){                    //Imprime las posiciones
  Serial1.end();
  Serial1.begin(9600,SERIAL_8N1);
  Serial1.print("Ver posiciones");
  for(y = 0; y < 10; y++){
      Serial1.println();
      Serial1.print(y+1);
    for(x = 0; x < 3; x++){
      Serial1.print("    ");
      Serial1.print(guardados[y][x]);
      Serial1.print(" ");
    }
  }
}

void motor1(){                            //Imprime el motor en la pantalla, dependiendo de el boton presionado modifica variable, la cual se convierte de pulsos a grados multiplicando *.9 al llegar a 360 o -360 se reinicia
   Serial1.print("El motor seleccionado es el A (360)");
   Serial1.println();
   Serial1.print("Para mover hacia la izquierda presionar F, para mover a la derecha presionar B. Para regresar a la seleccion de motor presionar x");
   Serial1.println();
   lcd.begin(16,2);
   lcd.blink();
   delay(50);
   lcd.print("Motor # 1");
    while (movimiento != 'x'){
          lcd.setCursor(0, 1);
          lcd.print("Angulo = ");
          lcd.print(pulsos1*.9);
          Serial1.end();
          Serial1.begin(9600,SERIAL_8N1);
          while(Serial1.available() == 0) { } 
          movimiento = Serial1.read();
          if (movimiento == 'f' or movimiento == 'F') pulsos1 = pulsos1 - 1;
          if (movimiento == 'b' or movimiento == 'B') pulsos1 = pulsos1 + 1;
          if (pulsos1 < 0) PORTC = pasos1[(8 - abs(pulsos1)%8)%8];
          if (pulsos1 >= 0) PORTC = pasos1[(pulsos1)%8];
          if (pulsos1 == 400 or pulsos1 == -400) pulsos1 = 0;
    }
  grados1 = pulsos1*.9;
  movimiento = 'z';
  lcd.clear();
  movermotor();
}

void motor2(){      //Imprime el motor en la pantalla, dependiendo de el boton presionado modifica variable, la cual se convierte de pulsos a grados multiplicando *.9 al llegar a -180 se bloquea
   Serial1.print("El motor seleccionado es el B (180)");
   Serial1.println();
   Serial1.print("Para mover hacia la izquierda presionar F, para mover a la derecha presionar B. Para regresar a la seleccion de motor presionar x");
   Serial1.println();
   lcd.begin(16,2);
   lcd.blink();
   delay(50);
   lcd.print("Motor # 2");
    while (movimiento != 'x'){
          lcd.setCursor(0, 1);
          lcd.print("Angulo = ");
          lcd.print(pulsos2*.9);
          Serial1.end();
          Serial1.begin(9600,SERIAL_8N1);
          while(Serial1.available() == 0) { } 
          movimiento = Serial1.read();
          if (pulsos2 != 0){
            if (movimiento == 'b' or movimiento == 'B') pulsos2 = pulsos2 + 1;
          }
          if (pulsos2 != -200){
            if (movimiento == 'f' or movimiento == 'F') pulsos2 = pulsos2 - 1;
          }
          if (pulsos2 <= 0)PORTL = pasos2[(8 - abs(pulsos2)%8)%8];
          if (pulsos2 == 0) {
            if (pulsos3 == 0) PORTB = 0x06;
            else if (pulsos3 == 167) PORTB = 0x05;
            else PORTB = 0x04;
          }
          else if (pulsos2 == -200){
            if (pulsos3 == 0) PORTB = 0x0A;
            else if (pulsos3 == 167) PORTB = 0x09;
            else PORTB = 0x08;
          }
          else {
            PORTB = 0x00;
            if (pulsos3 == 0) PORTB = 0x02;
            if (pulsos3 ==167) PORTB = 0x01;
          }
    }
  grados2 = pulsos2*.9;
  movimiento = 'z';
  lcd.clear();
  movermotor();
}

void motor3(){      //Imprime el motor en la pantalla, dependiendo de el boton presionado modifica variable y se mueve unicamente 150.3 grados a partir del motor b, enciende led si llega a algun limite, y para los limites compara valores
  Serial1.print("El motor seleccionado es el C (150.3)");
   Serial1.println();
   Serial1.print("Para mover hacia la izquierda presionar F, para mover a la derecha presionar B. Para regresar a la seleccion de motor presionar x");
   Serial1.println();
   lcd.begin(16,2);
   lcd.blink();
   delay(50);
   lcd.print("Motor # 3");
    while (movimiento != 'x'){
          lcd.setCursor(0, 1);
          lcd.print("Angulo = ");
          lcd.print(grados2 + pulsos3*.9);
          Serial1.end();
          Serial1.begin(9600,SERIAL_8N1);
          while(Serial1.available() == 0) { } 
          movimiento = Serial1.read();
          if (pulsos3 != 0){
            if (movimiento == 'f' or movimiento == 'F') pulsos3 = pulsos3 - 1;
          }
          if (pulsos3 != 167){
            if (movimiento == 'b' or movimiento == 'B') pulsos3 = pulsos3 + 1;
          }
          if (pulsos3 >= 0) PORTK = pasos3[(pulsos3)%8];
          if (pulsos3 == 0) {
            if (pulsos2 == 0) PORTB = 0x06;
            else if (pulsos2 == -200) PORTB = 0x0A;
            else PORTB = 0x02;
          }
          else if (pulsos3 == 167){
            if (pulsos2 == 0)PORTB = 0x05;
            else if (pulsos2 == -200) PORTB = 0x09;
            else PORTB = 0x01;
          }
          else {
            PORTB = 0x00;
            if (pulsos2 ==0) PORTB = 0x04;
            if (pulsos2 == -200) PORTB =0x08;
          }
    }
  grados3 = pulsos3*.9;
  movimiento = 'z';
  lcd.clear();
  movermotor();
}

void guardar(){       // Incrementa variables una para el eeprom que guarda de 3 en 3 y otra para una matriz la cual se guarda siempre cambiando posicion de fila, y cierta columna para cierta variable
  if (motor == 'g'){
  Serial1.end();
  Serial1.begin(9600,SERIAL_8N1);
  if (addre == 30) addre = 0;
  if (numdatos == 10) numdatos = 0;
  guardados[numdatos][0] = grados1;
  guardados[numdatos][1] = grados2;
  guardados[numdatos][2] = grados3 + grados2;
  guardadosp[numdatos][0] = pulsos1;
  EEPROM.write(addre, pulsos1);
  guardadosp[numdatos][1] = pulsos2;
  EEPROM.write(addre + 1, pulsos2);
  guardadosp[numdatos][2] = pulsos3;
  EEPROM.write(addre + 2, pulsos3);
  addre = addre + 3;
  numdatos++;
  Serial1.end();
  }
  movermotor();
}

void correr(){    // esta subrurtina de FOR, lo que hace es regresar a los motores a su punto inicial, usa valores absolutos, y dependiendo de si los numeros son positivos o negativos, entonces aumenta o disminuye el numero, para pulsos, imprime en la pantalla el angulo actual
  Serial1.print("RUN");
  numdatos = 0;
  PORTB = 0x00;
  lcd.begin(16,2);
  delay(50);
  lcd.print("Motor # 1");
  if (pulsos1 < 0){                           //Regresa a posicion inicial
    for(x = pulsos1; x <= 0; x++){
      PORTC = pasos1[(8 - abs(x)%8)%8];
      lcd.setCursor(0, 1);
      lcd.print("Angulo = ");
      lcd.print(x*.9);
      delay(100);
    }
    pulsos1 = 0;
    PORTC = 0x00;
    lcd.clear();
  }
  
  else if(pulsos1 > 0){                       //Regresa a posicion inicial
     for(x = pulsos1; x >= 0; x = x-1){
     PORTC = pasos1[(x)%8];
     lcd.setCursor(0, 1);
     lcd.print("Angulo = ");
     lcd.print(x*.9);
     delay(100);
     }
     pulsos1 = 0;
     PORTC = 0x00;
     lcd.clear();
  }
  lcd.begin(16,2);
  delay(50);
  lcd.print("Motor # 2");
  if (pulsos2 < 0){                           //Regresa a posicion inicial
    for(x = pulsos2; x <= 0; x++){
      PORTL = pasos2[(8 - abs(x)%8)%8];
      lcd.setCursor(0, 1);
      lcd.print("Angulo = ");
      lcd.print(x*.9);
      delay(100);
    }
    pulsos2 = 0;
    PORTL = 0x00;
  }
  lcd.begin(16,2);
  delay(50);
  lcd.print("Motor # 3");
  if(pulsos3 > 0){                            //Regresa a posicion inicial
     for(x = pulsos3; x >= 0; x = x-1){
     PORTK = pasos3[(x)%8];
     lcd.setCursor(0, 1);
     lcd.print("Angulo = ");
     lcd.print(x*.9);
     delay(100);
     }
     pulsos3 = 0;
     PORTK = 0x00;
  }
  lcd.clear();
motoragrab();  
}

void motoragrab(){    // Utilizando la matriz guardado, entra a un for y con modulos 8 aumenta o disminuye el valor para llegar a la posicion guardada, todos los motores estan en un for que va cambiando el numero de motor, y dentro de este FOR, existen otros ciclos que mueven a los motores a distintas posiciones, siempre imprimiendo el angulo donde se encuentran y lo realizan en el orden de 1,2,3.
  x=0;
  y=0;
   
   for(y = 0; y < 11; y++){
      lcd.begin(16,2);
      delay(50);
      lcd.print("Motor # 1");
      if(guardadosp[y][0] < pulsos1){
          for(x = pulsos1; x >= int(guardadosp[y][0]); x = x - 1){
            if(x<0) PORTC = pasos1[(8 - abs(x)%8)%8];
            else if (x>=0) PORTC = pasos1[(x)%8];
            lcd.setCursor(0, 1);
            lcd.print("Angulo = ");
            lcd.print(x*.9);
            delay(250);
            pulsos1 = x;
          }
          delay(1000);
      }
      else if(guardadosp[y][0] > pulsos1){
        for(x = pulsos1; x <= int(guardadosp[y][0]); x = x +1){
            if(x<0)PORTC = pasos1[(8 - abs(x)%8)%8];
            else if(x>=0)PORTC = pasos1[(x)%8];
            lcd.setCursor(0, 1);
            lcd.print("Angulo = ");
            lcd.print(x*.9);
            delay(250);
            pulsos1 = x;
        }
        delay(1000);
      }
      lcd.begin(16,2);
      delay(50);
      lcd.print("Motor # 2");
      if(guardadosp[y][1] < pulsos2){
          for(x = pulsos2; x >= int(guardadosp[y][1]); x = x - 1){
            if(x<0) PORTL = pasos2[(8 - abs(x)%8)%8];
            else if (x>=0) PORTL = pasos2[(x)%8];
            lcd.setCursor(0, 1);
            lcd.print("Angulo = ");
            lcd.print(x*.9);
            delay(250);
            pulsos2 = x;
          }
          delay(1000);
      }
      else if(guardadosp[y][1] > pulsos2){
        for(x = pulsos2; x <= int(guardadosp[y][1]); x = x +1){
            if(x<0)PORTL = pasos2[(8 - abs(x)%8)%8];
            else if(x>=0)PORTL = pasos2[(x)%8];
            lcd.setCursor(0, 1);
            lcd.print("Angulo = ");
            lcd.print(x*.9);
            delay(250);
            pulsos2 = x;
        }
        delay(1000);
      }
      lcd.begin(16,2);
      delay(50);
      lcd.print("Motor # 3");
      if(guardadosp[y][2] < pulsos3){
          for(x = pulsos3; x >= int(guardadosp[y][2]); x = x - 1){
            if(x<0) PORTK = pasos3[(8 - abs(x)%8)%8];
            else if (x>=0) PORTK = pasos3[(x)%8];
            lcd.setCursor(0, 1);
            lcd.print("Angulo = ");
            lcd.print(guardados[y][1]+x*.9);
            delay(250);
            pulsos3 = x;
          }
          delay(1000);
      }
      else if(guardadosp[y][2] > pulsos3){
        for(x = pulsos3; x <= int(guardadosp[y][2]); x = x +1){
            if(x<0)PORTK = pasos3[(8 - abs(x)%8)%8];
            else if(x>=0)PORTK = pasos3[(x)%8];
            lcd.setCursor(0, 1);
            lcd.print("Angulo = ");
            lcd.print(guardados[y][1]+x*.9);
            delay(250);
            pulsos3 = x;
        }
        delay(1000);
      }  
    }
   lcd.clear(); 
}

