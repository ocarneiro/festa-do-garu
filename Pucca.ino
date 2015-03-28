// Pucca
// by Otavio Carneiro 
// This code is in the public domain.
// Get it on github (user: ocarneiro)

#include <Servo.h> 
 
Servo cancela;  //bloqueio / porteira: servo que abre ou fecha
                // para dar passagem (ou nao) aos personagens autorizados
 
int FECHADO = 0;   //posicao do servo que abre a cancela
int ABERTO = 120; //posicao do servo que fecha a cancela
 
void setup() 
{ 
  cancela.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop () 
{
  delay(15);
  fechar();
  if (analogRead(A0) > 500) {
    abrir();
  }
}

void fechar()
{
  cancela.write(FECHADO);
}

void abrir() 
{ 
  int pos = FECHADO;    // pos: variavel que guarda a posicao atual
  cancela.write(pos);
  delay(300);
  for(pos = FECHADO; pos < ABERTO; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    cancela.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  cancela.write(ABERTO);
  delay(1000);
  for(pos = ABERTO; pos>=FECHADO+1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    cancela.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
} 
