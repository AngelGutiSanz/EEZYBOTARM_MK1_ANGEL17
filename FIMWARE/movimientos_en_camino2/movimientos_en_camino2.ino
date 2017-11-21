// Sweep Programa secuencia de movimientos Brazo Robótico

#include <Servo.h>

Servo servobase;         // Crear un objeto con servo para controlar la base
Servo servogripper;      // Crear un objeto con servo para controlar la pinza
Servo servodcha;         // Crear un objeto con servo para controlar el brazo derecho
Servo servoizda;         // Crear un objeto con servo para controlar la brazo izquierdo 

int pos = 0;        // variable to store the servo position
int retardo = 75;  // El tiempo que tarda entre movimiento
void setup() {
 
 // Pines de los leds y el pulsador
  pinMode(2,INPUT);        // Pulsador de arranque secuencia
  pinMode(3,OUTPUT);       // Led rojo 
  pinMode(4,OUTPUT);       // Led verde
  
 // Secuencia inicial + indicar en que salidas va a estar los servos
  servogripper.attach(10);                 //servo SG90, 500, 2400
    servogripper.write(100);
  servodcha.attach(6);                     //servo MG90, 400, 2400
    servodcha.write(50);
    delay(500);  
  servoizda.attach(5);                     //servo MG90, 400, 2400
   servoizda.write(150); 
   delay(500);  
  servobase.attach(9, 400, 2400);          //servo MG90, 400, 2400
    servobase.write(75);
    
  digitalWrite(3,HIGH);
  delay(1500);
  while (digitalRead(2)==0){}
       
}

void loop() {
  
  //Secuencia repetitiva de los movimientos
   digitalWrite(3,LOW);
   digitalWrite(4,HIGH);
  
  //1º Movimiento de la base hacia la izquierda 
   for (pos = 75; pos <= 100; pos += 1) {              // Mover el servo de la base a la posición 90º 
    servobase.write(pos);                    
    delay(20);                               
   }
   delay(retardo);

  //2º Movimiento: el servo de la derecha mueve brazo gordo a la posicion 90º
   for (pos = 50; pos <= 90; pos += 1){               // Mover el servo derecho a la posición 90º 
    servodcha.write(pos);
    delay(20);
   }
   delay(retardo);
  
  //3º Movimiento : servo de la izquierda sube a 95º para bajar el brazo 
   for (pos =150; pos >= 95; pos -= 1){             // Mover el servo izquierdo a la posición 90º
    servoizda.write(pos);
    delay(20);
   }
   delay(retardo);

  //4º Movimiento: el servo de la pinza se abre a 160º 
   for( pos =100; pos <= 140; pos += 1){              // Mueve la pinza y la abre
    servogripper.write(pos);
    delay(10);
   }
   delay(retardo);

  //5º Movimiento: el servo derecho vuelve a bajar hasta los 139º 
   for (pos = 90; pos <= 138; pos += 1){          // Mover el servo derecho a la posición 135º ,baja para recoger objeto
    servodcha.write(pos);
    delay(20);
   }
   delay(retardo);

  //6º Movimiento: el servo de la pinza se cierra a 100 
   for (pos =140; pos >=100; pos -= 1){       // Mueve la pinza y la cierra
    servogripper.write(pos);
    delay(15);
   }
   delay(retardo);

  //7º Movimiento: el servo de la derecha sube hasta el ángulo 95 
   for (pos =138; pos >=95 ; pos -= 1){       // Mover el servo derecho a la posición 65º
    servodcha.write(pos);
    delay(20);
   }
   delay(retardo);

  //8º Movimiento: el servo de la izquierda baja hasta la posición 150º     
   for (pos =95; pos <=170; pos += 1){       // Mover el servo izquierdo a la posición 150º
    servoizda.write(pos);
    delay(20);
   }
   delay(retardo);

   //9º Movimiento: el servo de la derecha vuelve a desplazarse para atras hasta la posición 60º 
   for (pos =95; pos >= 50; pos -=1){        // Mover el servo de la derecha a la psición 60º
    servodcha.write(pos);
    delay(20);
   }
   delay(retardo);
   
  //10º Movimiento: la base se desplaza hacia la derecha a otra posición
   for (pos =100; pos >=62; pos -= 1){       // Mover el servo de la base a la posición 40º
    servobase.write(pos);
    delay(20);
   }
   delay(retardo);

  //11º Movimiento: el servo derecho se desplaza hacia delante para soltar la bola en el agujero
   for (pos =50; pos <=110; pos +=1){
    servodcha.write(pos);
    delay(20);
   }
   delay(retardo);

  //12º Movimiento: la pinza se abre para dejar caer el objeto
   for( pos =100; pos <= 160; pos += 1){              // Mueve la pinza y la abre
    servogripper.write(pos);
    delay(10);
   }
   delay(retardo); 

  //13º Movimiento: el servo de la derecha retorna para atras
   for (pos =110; pos >= 50; pos -=1){        // Mover el servo de la derecha a la psición 60º
    servodcha.write(pos);
    delay(20);
   }
   delay(retardo);

  //14º Movimiento: el servo de la pinza se cierra a 100 
   for (pos =160; pos >=100; pos -= 1){       // Mueve la pinza y la cierra
    servogripper.write(pos);
    delay(10);
   }
   delay(retardo);

  //15º Movimiento: la base se desplaza hacia la izquierda a la posicion de inicio
   for (pos =61; pos <=75; pos += 1){       // Mover el servo de la base a la posición 40º
    servobase.write(pos);
    delay(20);
   }
   delay(retardo);

  //16º Movimiento : servo de la izquierda sube a 150º
   for (pos =170; pos >= 150; pos -= 1){             // Mover el servo izquierdo a la posición 90º
    servoizda.write(pos);
    delay(20);
   }
   delay(retardo);

}

